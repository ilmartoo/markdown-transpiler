%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errores.h"
#include "analizador_lexico.h"
#include "analizador_sintactico.h"
#include "tabla_simbolos.h"
#include "funciones_propias.h"
#include "componente_lexico.h"
#include "definiciones.h"
#include "boolean.h"

/* Creación y guardado de componente lexico */
int componente_lexico(int id);

/* Numero de buffers de lectura */
# define STACK_MAX_BUFFERS 10
struct Stack {
	YY_BUFFER_STATE list[STACK_MAX_BUFFERS];
	int i;
};
struct Stack buffers;

%}

/* Reglas auxiliares*/
DIGIT				[[:digit:]]
LETTER				[[:alpha:]]
LOWER				[[:lower:]]
UPPER				[[:upper:]]
INTEGER				{DIGIT}+|0x{DIGIT}+
FLOAT				{POINTFLOAT}|{EXPONENTFLOAT}
POINTFLOAT			({DIGIT}+)?{FRACTION}|{DIGIT}+\.
EXPONENTFLOAT		({DIGIT}+|{POINTFLOAT}){EXPONENT}
FRACTION			\.{DIGIT}+
EXPONENT			[eE][+-]?{DIGIT}+

/* Identificadores deben contener al menos una letra minúscula o no contener ninguna letra */
ID			(\_{DIGIT}+|\_{UPPER}+|\_)*({LOWER}({LETTER}|{DIGIT}|\_)*)|\_+{DIGIT}({DIGIT}|\_)*
/* Constantes deben tener todas las letras mayúsculas y contener al menos una */
CONST		(\_{DIGIT}+|\_)*{UPPER}({UPPER}|{DIGIT}|\_)*	
/* Operadores */
OP			[+\-*/%^]
/* Literales numéricos */
NUM			{INTEGER}|{FLOAT}
/* String */
STRING 		\"([^\n]|\\[^\n])*\"|\'([^\n]|\\[^\n])*\'

%x COMENTARIO

%option noinput
%option nounput
/* Quitamos yywrap para manejar los ficheros y los EOF manualmente */
%option noyywrap 

%%

	/* Omision de comentarios de archivos */
"#"						{ BEGIN(COMENTARIO); }
<COMENTARIO>[^\n]*		{ 
						  yyless(yyleng);
						  BEGIN(INITIAL);
						}

	/* Omision de espacios */
[ \t]+		{ yyless(yyleng); }

	/* Strings */
{STRING}	{ return componente_lexico(STRING); }

	/* Numeros, constantes e identificadores*/
{ID}	 	{ return componente_lexico(IDENTIFICADOR); }

{CONST}		{ return componente_lexico(CONSTANTE); }

{NUM}		{ return componente_lexico(NUMERICO); }

	/* Operadores */
({OP}|"=")	{ return yytext[0]; }

	/* Operadores de asignación */
"+=" 		{ return PLUS_EQ; }
"-=" 		{ return MINUS_EQ; }
"*=" 		{ return MULT_EQ; }
"/=" 		{ return DIV_EQ; }
"^=" 		{ return EXP_EQ; }
"%=" 		{ return MOD_EQ; }

	/* Necesarios para las llamadas a funciones */
"("		{ return '('; }
")"		{ return ')'; }

	/* Fin de comando */
";"		{ return ';'; }

	/* Fin de linea */
(\r?\n|\r)		{ return '\n'; }

	/* Fin de archivo */
<<EOF>>			{ 
	if (buffers.i > 0) 
		return END_COMMAND_FILE; 
	else 
		return EOF; }

	/* Caracter no reconocido */
.		{ 
			raise_error(ERR_UNMACHED_CHAR, yytext);
			return STOP_CURRENT_ANALISIS;
		}

%%

/* Creación y guardado de componente lexico */
int componente_lexico(int id) {
	int result;

	// Literal numérico
	if (id == NUMERICO) {
		yylval.num = atof(yytext);
		result = id;
	}
	// String
	else if (id == STRING) {
		yylval.str = strndup(yytext + 1, yyleng - 2); // Eliminación de las comillas
		result = id;
	}
	// Identificador / Constante / Funcion matemática / Funcion propia
	else {
		// Buscamos el componente lexico
		CompLexico *cl = buscar_tabla_simbolos(yytext);
		
		// Compontente léxico no está presente en la tabla de símbolos
		if (cl == NULL) {

			// Buscamos si es una función
			double (*fnc)() = NULL;
			fnc = (double(*)())lookup_fnc(yytext);

			// No es una función
			if (fnc == NULL) {
				// Insertamos componente en la tabla de simbolos
				Datos datos = {.di = {.inicializado = FALSE, .valor = 0.}};
				cl = insertar_tabla_simbolos(yytext, id, datos);

				// Añadimos el componente lexico a la sesión actual
				add_to_sesion(cl);

				yylval.cmplx = cl;
				result = cl->id;
			}
			// Es una función de una librería
			else {
				// Insertamos componente en la tabla de simbolos
				Datos datos = {.dfm = {.fncptr = fnc}};
				cl = insertar_tabla_simbolos(yytext, FUNCION, datos);

				// Añadimos la función a la sesión actual
				add_fnc(cl);

				yylval.cmplx = cl;
				result = cl->id;
			}
		}
		// Componente lexico presente en la tabla de simbolos
		else {
			yylval.cmplx = cl;
			result = cl->id;
		}
	}

	// Devolución de componente lexico
	return result;
}

/* Cierra el archivo a leer actualmente */
bool close_file() {
	// Cerramos buffer de entrada y volvemos al anterior
	if(buffers.i > 0) {
		yy_delete_buffer(buffers.list[buffers.i]);
		yy_switch_to_buffer(buffers.list[--buffers.i]);
	}
	return buffers.i == 0;
}

/* Introduce el último fichero cargado en el sistema de entrada */
void read_file() {
	if (buffers.i > 0) {
		yy_switch_to_buffer(buffers.list[buffers.i]);
	}
}

/* Añadimos un input al sistema de entrada */
bool load_file(const char *filename) {
	// Abrimos el archivo
	FILE *fp = fopen(filename, "r");

	// Cambiamos entrada al fichero
	if (fp != NULL && buffers.i < STACK_MAX_BUFFERS - 1) {
		buffers.list[buffers.i] = YY_CURRENT_BUFFER; 					// Guardado de buffer actual
		buffers.list[++buffers.i] = yy_create_buffer(fp, YY_BUF_SIZE); 	// Creacion del nuevo buffer cargado
		return TRUE;
	}
	return FALSE;
}

/* Inicializaciones y cerrados del sistema de entrada y analizador lexico */
// Inicializacion del analizador lexico
void inicializacion_analizador_lexico() {
	buffers.i = 0;
}

// Liberacion de memoria del analizador lexico
void cerrado_analizador_lexico() {
	yylex_destroy();
}