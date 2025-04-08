%{

#include <stdio.h>
#include <math.h>
#include "analizador_sintactico.h"
#include "tabla_simbolos.h"
#include "analizador_lexico.h"
#include "componente_lexico.h"
#include "funciones_propias.h"
#include "definiciones.h"
#include "boolean.h"
#include "errores.h"

/* Tratamiento de errores */
void yyerror(const char *s); /* Funcion de impresión de error */

/* Estructura de datos de la ejecución actual */
void reset_current_exec();
struct CurrentExec {
	bool error;			 /* Booleano para no imprimir resultado en caso de error */
	int err_flag;		 /* Flag del error actual */
	bool print_out;		 /* Booleano para no imprimir resultado cuando proceda */
	bool file;			 /* Booleano para indicar la lectura de fichero */
	bool file_ready;	 /* Booleano para indicar la correcta carga de un fichero que está en espera */
	char *last_fnc_name; /* Nombre de la última función utilizada (para la impresión de errores) */
} ce;

/* Checkeo de inicialización de variables y constantes */
bool is_inicializada(CompLexico *cl);

/* Función de limpiado de strings de yylval */
void clear_string(char *ptr);

%}

/* Mejor comentado de errores */
%define parse.error verbose

/* Requerimientos del header */
%code requires {
	#include "analizador_sintactico.h"
	#include "analizador_lexico.h"
	#include "boolean.h"
	#include "componente_lexico.h"
}

/* Tipo de dato de yylval*/
%union {
	CompLexico *cmplx;
	double num;
	char *str;
}

/* Tokens y tipos */
%token <num> NUMERICO
%token <cmplx> FUNCION IDENTIFICADOR CONSTANTE
%token <str> STRING
/* Tokens de funciones propias del interprete */
%token <cmplx> FP_NARGS FP_ONEARG FP_EXPARG
/* Token de fin de archivo */
%token END_COMMAND_FILE

/* Tipo de las expresiones */
%type <num> exp fnc comm line asign instr asign_op exp_asg
%type <cmplx> storage var

/* Orden de precedencia y tipo de recursividad */
%right ';'
%right '=' PLUS_EQ MINUS_EQ MULT_EQ DIV_EQ EXP_EQ MOD_EQ
%left '-' '+'	  /* Suma y resta */
%left '*' '/' '%' /* Multiplicación, división y módulo */
%precedence NEG   /* Negación de literal numérico */
%right '^' 		  /* Exponenciación */

%%

/* Regla de lectura de comandos (hasta fin de fichero) */
input:	%empty /* cadena vacía */
		| input line {
			 /* Cargamos fichero si está en espera */
			if (ce.file_ready) {
				ce.file_ready = FALSE;
				ce.file = TRUE;
				read_file();
			}
			/* Procesamos si terminamos de leer un fichero o terminamos de leer una línea */
			else if (!ce.file) {
				/* Finalización del comando */
				if (!ce.error) {
					/* Impresión de la salida*/
					if(ce.print_out) {
						print_output($2);
					}
					commit_variables(); // Guardamos variables de la línea
				}
				else {
					rollback_variables(); // Eliminamos variables de la línea
				}

				/* Imprimimos prompt */
				print_prompt();
				/* Reseteamos valores de la ejecución actual */
				reset_current_exec();
			} }
		;

/* Regla de lectura de lineas */
line: 	instr end { $$ = $1; }
		/* Lectura de linea vacía */
		| pyc end { ce.print_out = FALSE; }
		| end { ce.print_out = FALSE; }
		/* Linea con errores */
		| error end {
			/* Cancelamos la impresión actual */
			ce.error = TRUE;
			/* Cancelamos lectura de archivo */
			if (ce.file || ce.file_ready) {
				ce.file = !close_file();
				ce.file_ready = FALSE;
			}
			yyerrok; }
		;

/* Regla de fin de linea */
end:	'\n'
		| END_COMMAND_FILE {
			/* Cerramos archivo */
			ce.file = !close_file();
			ce.file_ready = FALSE;
			}

/* Regla de lectura de comandos */
instr:	comm pyc { $$ = $1; }
		| comm { $$ = $1; }
		| comm pyc instr { $$ = $3; }
		| pyc instr { $$ = $2; }

/* Regla de puntos y coma */
pyc:	';'
		| ';' pyc
		;

/* Regla de comandos posibles */
comm:	fp { /* Cancelamos impresión pues es una función*/
			 ce.print_out = FALSE; }
		| exp_asg { $$ = $1; }
		;

/* Regla de expresión o asignación */
exp_asg:	exp { $$ = $1; }
			| asign { $$ = $1; }

/* Regla de funciones propias */
fp: 	/** Funciones sin argumentos **/
		FP_NARGS '(' ')' {
			/* Guardamos referencia a la función */
			ce.last_fnc_name = $1->lexema;
			/* Llamada a la función */  	
			(*($1->datos.dfp.fncptr))();
			/* Realizamos salida del programa si corresponde */
			if ($1->datos.dfp.tipo == FP_EXIT) {
				YYACCEPT;
			} }
		/** Funciones con 1 argumento **/
		/* String - ejecución de load(file) */
		| FP_ONEARG '(' STRING ')' {
			CompLexico *f = $1;
			/* Guardamos referencia a la función */
			ce.last_fnc_name = $1->lexema;
			/* Llamada a la función load() */
			if (f->datos.dfp.tipo == FP_LOAD) {
				/* Imprimimos error si la ruta no es válida */
				if (!((bool(*)())f->datos.dfp.fncptr)($3)) {
					/* Registramos el error */
					ce.err_flag = ERR_FILE_NOT_FOUND; 
					yyerror($3);
					clear_string($3); // Liberación de memoria del string
					/* Abortamos lectura debido al error */
					YYERROR;
				}
				/* Establecemos booleano de carga correcta de archivo */
				else {
					clear_string($3); // Liberación de memoria del string
					ce.file_ready = TRUE;
				}
			}
			/* Llamada a la función import() */
			else if (f->datos.dfp.tipo == FP_IMPORT) {
				/* Imprimimos error si la ruta no es válida */
				if (!((bool(*)())f->datos.dfp.fncptr)($3)) {
					/* Registramos el error */
					ce.err_flag = ERR_LIB_NOT_FOUND; 
					yyerror($3);
					clear_string($3); // Liberación de memoria del string
					/* Abortamos lectura debido al error */
					YYERROR;
				}
				clear_string($3); // Liberación de memoria del string
			}
			/* Error de tipo de dato */
			else {
				clear_string($3); // Liberación de memoria del string
				/* Registramos el error */
				ce.err_flag = ERR_INVALID_ARGUMENT_TYPE; 
				yyerror(f->lexema);
				/* Necesario para parar el analisis y no imprimir mas errores */
				ce.err_flag = STOP_CURRENT_ANALISIS;
				/* Abortamos lectura debido al error */
				YYERROR; 
			} }
		/* Variable o constante - ejecución de clean(var) o echo(bool) */
		| FP_ONEARG '(' var ')' {
			CompLexico *f = $1;
			/* Guardamos referencia a la función */
			ce.last_fnc_name = $1->lexema;
			/* Función clean(var) */
			if (f->datos.dfp.tipo == FP_CLEAN_VAR) {
				f->datos.dfp.fncptr($3->lexema);
			}
			/* Función echo(bool) */
			else if (f->datos.dfp.tipo == FP_ECHO) {
				f->datos.dfp.fncptr((bool)$3->datos.di.valor);
			}
			/* Error de tipo de dato */
			else {
				/* Registramos el error */
				ce.err_flag = ERR_INVALID_ARGUMENT_TYPE; 
				yyerror(f->lexema);
				/* Necesario para parar el analisis y no imprimir mas errores */
				ce.err_flag = STOP_CURRENT_ANALISIS;
				/* Abortamos lectura debido al error */
				YYERROR; 
			} }
		/* Numérico - ejecución de echo(bool) */
		| FP_ONEARG '(' NUMERICO ')' {
			CompLexico *f = $1;
			/* Guardamos referencia a la función */
			ce.last_fnc_name = $1->lexema;
			/* Función echo(bool) */
			if (f->datos.dfp.tipo == FP_ECHO) {
				f->datos.dfp.fncptr((bool)$3);
			}
			/* Error de tipo de dato */
			else {
				/* Registramos el error */
				ce.err_flag = ERR_INVALID_ARGUMENT_TYPE; 
				yyerror(f->lexema);
				/* Necesario para parar el analisis y no imprimir mas errores */
				ce.err_flag = STOP_CURRENT_ANALISIS;
				/* Abortamos lectura debido al error */
				YYERROR; 
			} }
		/* String - ejecución de print(value) */
		| FP_EXPARG '(' exp ')' {
			CompLexico *f = $1;
			/* Guardamos referencia a la función */
			ce.last_fnc_name = $1->lexema;
			/* Llamada a la función load() */
			if (f->datos.dfp.tipo == FP_PRINT) {
				f->datos.dfp.fncptr($3);
			}
			/* Error de tipo de dato */
			else {
				/* Registramos el error */
				ce.err_flag = ERR_INVALID_ARGUMENT_TYPE; 
				yyerror(f->lexema);
				/* Necesario para parar el analisis y no imprimir mas errores */
				ce.err_flag = STOP_CURRENT_ANALISIS;
				/* Abortamos lectura debido al error */
				YYERROR; 
			} }
		;

/* Regla de expresiones matemáticas */
exp: 	/* Valor numérico */
		NUMERICO { $$ = $1; }
		/* Valor de una variable o constante */
		| var { $$ = $1->datos.di.valor; }
		/* Llamada a función */
		| fnc { $$ = $1; }
		/* Expresiones de operación */
		| exp '+' exp { $$ = $1 + $3; }
		| exp '-' exp { $$ = $1 - $3; }
		| exp '*' exp { $$ = $1 * $3; }
		| exp '/' exp {
			// Comprobamos que no se produzca una división por 0
			if ($3 > 0) {
				$$ = $1 / $3;
			}
			// División por 0
			else {
				/* Registramos el error */
				ce.err_flag = ERR_DIVISION_BY_0;
				yyerror(NULL);
				/* Abortamos lectura debido al error */
				YYERROR;
			} }
		| exp '%' exp { $$ = fmod($1, $3); }
		| '-' exp %prec NEG { $$ = -$2; }
		| exp '^' exp { $$ = pow($1, $3); }
		| '(' exp_asg ')' { $$ = $2; }
		;

/* Regla de variables y constantes inicializadas */
var:	/* Valor de una variable */
		IDENTIFICADOR {
			/* Comprobación de inicialización */
			if (!is_inicializada($1)) {
				/* Registramos el error */
				ce.err_flag = ERR_SYMBOL_NOT_DEFINED;
				yyerror($1->lexema);
				/* Abortamos lectura debido al error */
				YYERROR;
			}
			/* Asignamos */
			else {
			$$ = $1; 
			} }
		/* Valor de una constante */
		| CONSTANTE { 
			/* Comprobación de inicialización */
			if(!is_inicializada($1)) {
				/* Registramos el error */
				ce.err_flag = ERR_CONSTANT_NOT_DEFINED;
				yyerror($1->lexema);
				/* Abortamos lectura debido al error */
				YYERROR;
			}
			/* Asignamos */
			else {
				$$ = $1;
		 	} }

/* Regla de expresiones de asignación */
asign:	storage '=' exp { 	
			$$ = ($1->datos.di.valor = $3);
			$1->datos.di.inicializado = TRUE; }
		/* Asignaciones que deben estar inicializadas */
		| IDENTIFICADOR asign_op {
			/* Comprobacion de inicialización */
			if (!is_inicializada($1)) {
				/* Registramos el error */
				ce.err_flag = ERR_SYMBOL_NOT_DEFINED;
				yyerror($1->lexema);
				/* Abortamos lectura debido al error */
				YYERROR;
			}
			/* Asignamos */
			else {
				$$ = ($1->datos.di.valor = $2);
		 	} }

asign_op: 	PLUS_EQ exp { $$ = ($<cmplx>0->datos.di.valor += $2); }
			| MINUS_EQ exp { $$ = ($<cmplx>0->datos.di.valor -= $2); }
			| MULT_EQ exp { $$ = ($<cmplx>0->datos.di.valor *= $2); }
			| DIV_EQ exp { $$ = ($<cmplx>0->datos.di.valor /= $2); }
			| MOD_EQ exp { $$ = ($<cmplx>0->datos.di.valor = fmod($<cmplx>0->datos.di.valor, $2)); }
			| EXP_EQ exp { $$ = ($<cmplx>0->datos.di.valor = pow($<cmplx>0->datos.di.valor, $2)); }
			;

/* Regla de variables a asignar un valor */
storage:	/* Variable */
			IDENTIFICADOR { $$ = $1; }
			/* Constante */
			| CONSTANTE {	
				/* Constante ya inicializada */
				if(is_inicializada($1)) {
					/* Registramos el error */
					ce.err_flag = ERR_CONSTANT_REDEFINITION;
					yyerror($1->lexema);
					/* Abortamos lectura debido al error */
					YYERROR;
				} 
				/* Devolvemos referencia */
				else {
					$$ = $1;
				} }
			;

/* Regla de función matemática */
fnc:	FUNCION '(' exp ')' { $$ = (*($1->datos.dfm.fncptr))($3); } ;

%%

/* Funcion de error */
void yyerror(const char *s) {
	/* Error ya tratado */
	if (yychar == STOP_CURRENT_ANALISIS) {
		return;
	}
	/* Flag no definida */
	else if (ce.err_flag == ERR_UNKNOWN_ERROR) {	
		switch(yychar) {
			/* Valor en la izquierda de una asignación no válido */
			case '=':
			case PLUS_EQ:
			case MINUS_EQ:
			case MULT_EQ:
			case DIV_EQ:
			case MOD_EQ:
			case EXP_EQ:
				raise_error(ERR_INVALID_ASSIGN_TYPE, NULL);
				break;
			/* Llamada incorrecta a una función */
			case '(':
			case ')':
				raise_error(ERR_INVALID_FUNCTION_CALL, ce.last_fnc_name);
				break;
			/* String en un lugar no válido */
			case STRING:
				clear_string(yylval.str); // Liberación de memoria del string
				raise_error(ERR_UNKNOWN_ERROR, s); // Lanzamos error igualmente
				break;
			/* Error de sintaxis de bison */
			default:
				raise_error(ERR_UNKNOWN_ERROR, s);
		}
	}
	/* Flag definida */
	else {
		raise_error(ce.err_flag, s);
	}
	/* Paramos la impresión de errores hasta final de lectura del comando */
	ce.err_flag = STOP_CURRENT_ANALISIS;
}

// Comprueba si una variable o constante está inicializada
bool is_inicializada(CompLexico *cl) { 
	if((cl->id == IDENTIFICADOR || cl->id == CONSTANTE) && cl->datos.di.inicializado == TRUE)
		return TRUE;
	return FALSE;
}

/* Función de limpiado de strings de yylval */
void clear_string(char *ptr) {
	if (ptr != NULL) {
		free(ptr);
		ptr = NULL;
	}
}

/* Reseteo de los datos de la ejecución actual */
void reset_current_exec() {
	ce.error = FALSE;
	ce.err_flag = ERR_UNKNOWN_ERROR;
	ce.print_out = TRUE;
	ce.file_ready = FALSE;
	ce.file = FALSE;
	ce.last_fnc_name = NULL;
}

/* Inicializaciones y cerrados del analizador sintáctico */
// Inicializacion del analizador sintactico
void inicializacion_analizador_sintactico() {
	// Impresion del prompt
	print_prompt();
	// Inicialización de la primera ejecución
	reset_current_exec();
}

// Liberacion de memoria del analizador sintactico
void cerrado_analizador_sintactico() {
	// Liberación de memoria de las funciones propias
	finalizacion_funciones();
}