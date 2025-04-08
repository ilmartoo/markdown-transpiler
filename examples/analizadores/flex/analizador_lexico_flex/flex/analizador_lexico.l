%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sistema_entrada.h"
#include "analizador_lexico.h"
#include "tabla_simbolos.h"
#include "boolean.h"
#include "errores.h"
#include "pila.h"

/* Definicion de estructura de posicion en fichero */
typedef struct struct_PositionData {
	int row;    // Linea actual
	int col;    // Columna actual
	Pila pila;  // Pila de lineas logicas
} PositionData;

PositionData pdata = {.row = 1, .col = 1}; // Estructura global de localizacion del fichero

/* Funciones de lineas logicas */
// Nuevo caracter de comienzo de linea logica
void llogica_caracter_apertura(char c) {
	push(&pdata.pila, c);
}
// Nuevo caracter de final de linea logica
void llogica_caracter_cerrado(char c) {
	// Si esta vacia no se puede cerrar una definicion
	if (!es_vacia(pdata.pila)) {
		char top = peek(pdata.pila);
		// Comprobamos que cierre definiciones estilo (...) o [...] o {...}
		if ((top == '(' && c == ')') || (top == '[' && c == ']') || (top == '{' && c == '}')) {
			// Eliminado de elemento de la pila si cierra una definicion
			pop(&pdata.pila);
		}
	}
}
// Consulta si es final de linea logica
bool final_llogica() {
	return es_vacia(pdata.pila);
}

/* Funciones de localizacion */
// Nueva linea
void newline() {
	pdata.col = 1;
	pdata.row++;
}
// Añadir n caracteres
void step(int n) {
	pdata.col += n;
}

%}
/* Identificador */
IDENTIFIER			({LETTER}|_)({LETTER}|{DIGIT}|_)*
DIGIT				[[:digit:]]
LETTER				[[:alpha:]]

/* Strings */
STRINGPREFIX		[uUbB][rR]?|[rR]
SHORTSTRINGITEM_DC 	[^\\\n"]|{ESCAPESEC}
SHORTSTRINGITEM_SC 	[^\\\n']|{ESCAPESEC}
LONGSTRINGITEM_DC	"[^\\"]|""[^\\"]|[^\\"]|{ESCAPESEC}
LONGSTRINGITEM_SC	'[^\\']|''[^\\']|[^\\']|{ESCAPESEC}
ESCAPESEC			\\.

/* Enteros */
INTEGER				{DECIMALINTEGER}|{OCTINTEGER}|{HEXINTEGER}|{BININTEGER}
DECIMALINTEGER		{NONZERODIGIT}{DIGIT}*|0
OCTINTEGER			0[oO]{OCTDIGIT}+|0{OCTDIGIT}+
HEXINTEGER			0[xX]{HEXDIGIT}+
BININTEGER			0[bB]{BINDIGIT}+
NONZERODIGIT		[1-9]
OCTDIGIT			[0-7]
BINDIGIT			[01]
HEXDIGIT			{DIGIT}|[a-fA-F]

/* Floats */
FLOATNUMBER			{POINTFLOAT}|{EXPONENTFLOAT}
POINTFLOAT			{INTPART}?{FRACTION}|{INTPART}\.
EXPONENTFLOAT		({INTPART}|{POINTFLOAT}){EXPONENT}
INTPART				{DIGIT}+
FRACTION			\.{DIGIT}+
EXPONENT			[eE][+-]?{DIGIT}+

/* Reglas de entrada */
%x COMENTARIO
%x STRING_DC
%x STRING_SC
%x LONGSTRING_DC
%x LONGSTRING_SC

/* Opciones */
%option noyywrap
%option noinput
%option nounput

%%

	/* Omision de comentarios */
"#"						{BEGIN(COMENTARIO);}
<COMENTARIO>[^\n]*		{step(yyleng); yyless(yyleng);}
<COMENTARIO>\n			{newline(); yyless(yyleng); BEGIN(INITIAL);}

	/* Lectura de strings */
{STRINGPREFIX}?\"\"\"				{yymore(); BEGIN(LONGSTRING_DC);}
<LONGSTRING_DC>{LONGSTRINGITEM_DC}*	{yymore();}
<LONGSTRING_DC>\"\"\"				{step(yyleng); BEGIN(INITIAL); return STRING; }

{STRINGPREFIX}?'''					{yymore(); BEGIN(LONGSTRING_SC);}
<LONGSTRING_SC>{LONGSTRINGITEM_SC}*	{yymore();}
<LONGSTRING_SC>'''					{step(yyleng); BEGIN(INITIAL); return STRING; }

{STRINGPREFIX}?\"					{yymore(); BEGIN(STRING_DC);}
<STRING_DC>{SHORTSTRINGITEM_DC}*	{yymore();}
<STRING_DC>\"						{step(yyleng); BEGIN(INITIAL); return STRING; }

{STRINGPREFIX}?'					{yymore(); BEGIN(STRING_SC);}
<STRING_SC>{SHORTSTRINGITEM_SC}*	{yymore();}
<STRING_SC>'						{step(yyleng); BEGIN(INITIAL); return STRING; }

<STRING_SC,STRING_DC>[\\\n]			{step(yyleng); yyless(yyleng); BEGIN(INITIAL); raise(END_STRING_ERROR, pdata.row, pdata.col, TRUE);}
<LONGSTRING_SC,LONGSTRING_DC>\\		{step(yyleng); yyless(yyleng); BEGIN(INITIAL); raise(END_STRING_ERROR, pdata.row, pdata.col, TRUE);}

	/* Lectura de identificadores, enteros y floats */
{IDENTIFIER} 	{step(yyleng); return IDENTIFICADOR;}

{INTEGER}		{step(yyleng); return INT;}

{FLOATNUMBER}	{step(yyleng); return FLOAT;}

	/* Separadores (lineas logicas) */
"("				{step(yyleng); llogica_caracter_apertura('('); return '(';}
")"				{step(yyleng); llogica_caracter_cerrado(')'); return ')';}
"["				{step(yyleng); llogica_caracter_apertura('['); return '[';}
"]"				{step(yyleng); llogica_caracter_cerrado(']'); return ']';}
"{"				{step(yyleng); llogica_caracter_apertura('{'); return '{';}
"}"				{step(yyleng); llogica_caracter_cerrado('}'); return '}';}

	/* Operadores multicaracter */
"**"			{step(yyleng); return EXP;}
"//"			{step(yyleng); return INT_DIV;}
"<<"			{step(yyleng); return SHIFT_L;}
">>"			{step(yyleng); return SHIFT_R;}

	/* Delimitadores multicaracter */
"<="			{step(yyleng); return LESS_EQ;}
">="			{step(yyleng); return GREAT_EQ;}
"=="			{step(yyleng); return EQ_EQ;}
"!="			{step(yyleng); return DIFF;}
"<>"			{step(yyleng); return LESS_GREAT;}
"+="			{step(yyleng); return PLUS_EQ;}
"-="			{step(yyleng); return MINUS_EQ;}
"*="			{step(yyleng); return MULT_EQ;}
"/="			{step(yyleng); return DIV_EQ;}
"//="			{step(yyleng); return INT_DIV_EQ;}
"%="			{step(yyleng); return MOD_EQ;}
"&="			{step(yyleng); return AND_EQ;}
"|="			{step(yyleng); return OR_EQ;}
"^="			{step(yyleng); return XOR_EQ;}
">>="			{step(yyleng); return SHIFT_R_EQ;}
"<<="			{step(yyleng); return SHIFT_L_EQ;}
"**="			{step(yyleng); return EXP_EQ;}

	/* Nueva linea */
\r?\n|\r		{newline(); if(final_llogica()) {return '\n';} else {yyless(yyleng);}}

	/* Caso especial de nueva linea sin ser nueva linea logica */
\\\n			{step(1); newline(); yyless(yyleng);}

	/* Lectura de caracteres admitidos o escapado de caracteres */
[^$? \t]|\\[^\n]		{step(yyleng); return yytext[0];}

	/* Omision de espacios en blanco */
[ \t]+			{step(yyleng); yyless(yyleng);}

	/* EOF */
<<EOF>>			{return EOF;}

	/* Caracteres no admitidos*/
[$?]			{step(yyleng); yyless(yyleng); raise(ILLEGAL_CARACTER_ERROR, pdata.row, pdata.col, TRUE);}

%%

/* Siguiente componente léxico */
bool siguiente_componente_lexico(CompLexico *comp_lexico) {
	int comp_lex_id = yylex();
	// Selección de acción segun codigo
	if(comp_lex_id != EOF) {
		// Limpiado de lexema
		free(comp_lexico->lexema);

		// Id de componente lexico
		comp_lexico->id = comp_lex_id;
		// Nueva línea lógica
		if (comp_lex_id == '\n'){
			// Copiado del lexema
			comp_lexico->lexema = strdup("\\n");
		}
		// Identificador
		else if(comp_lex_id == IDENTIFICADOR) {
			// Copiado del lexema
			comp_lexico->lexema = strdup(yytext);
			// Busqueda en la tabla de símbolos
			comp_lexico->id = buscar_tabla_simbolos(comp_lexico->lexema);
		}
		// Resto de lexemas
		else {
			// Copiado del lexema
			comp_lexico->lexema = strdup(yytext);
		}
		return TRUE;
	}
	return FALSE;
}

/* Inicializaciones y cerrados del sistema de entrada y analizador lexico */
// Inicializacion del analizador lexico
void inicializacion_analizador_lexico() {
	// Creado de la pila
	nueva_pila(&pdata.pila);
}
// Liberacion de memoria del analizador lexico
void cerrado_analizador_lexico() {
	// Borrado de la pila
	borrado_pila(&pdata.pila);
	// Terminamos el analizador
	yylex_destroy();
}
// Inicializacion del sistema de entrada
bool inicializacion_sistema_entrada(char *nombre_fichero) {
	// Apertura del archivo
	yyin = fopen(nombre_fichero, "r");
	// Retorno con comprobacion de apertura correcta
	return yyin != NULL;
}
// Liberacion de memoria del sistema de entrada
void cerrado_sistema_entrada() {
	// Cerrado del archivo
	fclose(yyin);
}