#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "sistema_entrada.h"
#include "analizador_lexico.h"
#include "tabla_simbolos.h"
#include "boolean.h"
#include "errores.h"
#include "pila.h"

/* Codigos de estado */
#define START_STATE   0
#define COMMENT_STATE 1
#define NUMERIC_STATE 2

/* Definicion de estructuras */
// Estructura de posicion en fichero
typedef struct struct_PositionData {
    char c;     // Buffer de caracter
    int row;    // Linea actual
    int col;    // Columna actual
    Pila pila;  // Pila de lineas logicas
} PositionData;
// Estructura de estado
typedef struct struct_State {
    int id;           // Identificador del estado actual
    bool end;         // Boolean de finalizacion de bucle
    bool rollback;    // Boolean de rollback
    int comp_lex_id;  // Codigo de componente lexico
} State;

/* Variables globales */
PositionData pdata = {.row = 1, .col = 1};

/* Declaracion de funciones de automatas */
// Cadenas
void string_literal(State *s, char comilla);
void docstring_literal(State *s, char comilla);
// Enteros
void integer_literal(State *s);
void binary_literal(State *s);
void hexadecimal_literal(State *s);
void octal_literal(State *s);
// Punto flotante
void point_float_literal(State *s);
void exponent_float_literal(State *s);
// Identificador
void identificador(State *s);

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

/* Funciones utilitarias*/
// Siguiente caracter
void next() {
    pdata.c = siguiente_caracter();
    pdata.col++;
}
// Siguiente caracter y limpiado de lexema
void clear_and_next() {
    limpiar_lexema();
    next();
}
// Nueva linea
void newline() {
    pdata.col = 1;
    pdata.row++;
}

// Inicializacion del analizador lexico
void inicializacion_analizador_lexico() {
    nueva_pila(&pdata.pila);
}

// Liberacion de memoria del analizador lexico
void cerrado_analizador_lexico() {
    borrado_pila(&pdata.pila);
}

// Siguiente componente lexico
bool siguiente_componente_lexico(CompLexico *comp_lexico) {
    // El componente lexico debe estar inicializado
    if (comp_lexico == NULL)
        return FALSE;

    // Inicializacion del estado del automata
    State estado = {.id = START_STATE, .end = FALSE, .rollback = FALSE};

    // Automatas
    while (!estado.end) {
        switch (estado.id) {
            // Comentario
            case COMMENT_STATE:
                // Leemos caracteres hasta un salto de linea
                do {
                    clear_and_next();
                } while (pdata.c != '\n' || pdata.c == EOF);
                // Limpiamos el lexema y seguimos buscando
                if (pdata.c == '\n') {
                    limpiar_lexema();
                    estado.id = START_STATE;
                }
                // Fin de fichero
                else {
                    estado.end = TRUE;
                    estado.comp_lex_id = EOF;
                }
                break;

            // Literal numerico
            case NUMERIC_STATE:
                switch (pdata.c) {
                    // Binario
                    case 'b':
                    case 'B':
                        binary_literal(&estado);
                        break;
                    // Hexadecimal
                    case 'x':
                    case 'X':
                        hexadecimal_literal(&estado);
                        break;
                    // Octal
                    case 'o':
                    case 'O':
                        octal_literal(&estado);
                        break;
                    // Octal o Nuevo lexema
                    default:
                        if (isdigit(pdata.c)) {
                            // Los codigos en ASCII de los numeros empiezan en
                            // 48 ('0') y van en aumento: 49 ('1'), 50 ('2')...
                            // Octal
                            if (pdata.c < '8') {
                                octal_literal(&estado);
                            }
                            // Integer <0>
                            else {
                                estado.rollback = TRUE;
                                estado.end = TRUE;
                                estado.comp_lex_id = INT;
                            }
                        }
                        break;
                }
                break;

            // Comienzo
            case START_STATE:
                // Leemos
                next();

                // Omision de espacios
                while (pdata.c == ' ') {
                    clear_and_next();
                }
                // Final de fichero
                if (pdata.c == EOF) {
                    estado.end = TRUE;
                    estado.comp_lex_id = EOF;
                }
                // Caracter especial '\'
                // Escape de caracter siguiente
                else if (pdata.c == '\\') {
                    next(); // Caracter escapado
                    // Contamos espacio para localización de errores
                    if (pdata.c == '\n'){
                        newline();
                    }
                    limpiar_lexema(); // Limpiamos el lexema
                }
                // Comentario
                else if (pdata.c == '#') {
                    estado.id = COMMENT_STATE;
                }
                // Tabulacion
                else if (pdata.c == '\t') {
                    estado.rollback = FALSE;
                    estado.end = TRUE;
                    estado.comp_lex_id = pdata.c;
                }
                // Cambio de linea MAC / Windows
                else if (pdata.c == '\r') {
                    next();
                    // Cambio de linea Windows
                    if (pdata.c == '\n') {
                        estado.rollback = FALSE;
                    }
                    // Cambio de linea MAC
                    else {
                        // Rollback para analizar el caracter
                        devolver_caracter();
                    }
                    // Detectado salto de linea
                    // Es linea logica?
                    if (final_llogica()) {
                        estado.end = TRUE;
                        estado.comp_lex_id = '\n';
                    }
                    // Limpiado de lexema de nueva linea pues no es linea logica
                    else {
                        limpiar_lexema();
                    }
                    newline();  // Modificamos row y col
                }
                // Cambio de linea Linux -> Fin linea fisica (logica si
                // coincide)
                else if (pdata.c == '\n') {
                    // Detectado salto de linea
                    // Es linea logica?
                    if (final_llogica()) {
                        estado.rollback = FALSE;
                        estado.end = TRUE;
                        estado.comp_lex_id = '\n';
                    }
                    // Limpiado de lexema de nueva linea pues no es linea logica
                    else {
                        limpiar_lexema();
                    }
                    newline();  // Modificamos row y col
                }
                // Literal numerico
                else if (isdigit(pdata.c)) {
                    // Literal numerico no entero natural
                    if (pdata.c == '0') {
                        estado.id = NUMERIC_STATE;
                    }
                    // Entero
                    else {
                        integer_literal(&estado);
                    }
                }
                // Literal (string)
                else if (pdata.c == '"' || pdata.c == '\'') {
                    string_literal(&estado, pdata.c);
                }
                // String o Identificador
                else if (isalpha(pdata.c)) {
                    switch (pdata.c) {
                        // String o Identificador
                        case 'u':
                        case 'U':
                        case 'b':
                        case 'B':
                            next();
                            // String
                            if (pdata.c == '"' || pdata.c == '\'') {
                                string_literal(&estado, pdata.c);
                            }
                            // String
                            else if (pdata.c == 'r' || pdata.c == 'R') {
                                next();
                                // String
                                if (pdata.c == '"' || pdata.c == '\'') {
                                    string_literal(&estado, pdata.c);
                                }
                                // Identificador
                                else if (isalpha(pdata.c) || pdata.c == '_' || isdigit(pdata.c)) {
                                    identificador(&estado);
                                }
                                // Identificador <br> o <Br> o <ur> o <Ur> o
                                // <bR> o <BR> o <uR> o <UR>
                                else {
                                    estado.rollback = TRUE;
                                    estado.end = TRUE;
                                    estado.comp_lex_id = STRING;
                                }
                            }
                            // Identificador
                            else if (isalpha(pdata.c) || pdata.c == '_' || isdigit(pdata.c)) {
                                identificador(&estado);
                            }
                            // Identificador <b> o <B> o <u> o <U>
                            else {
                                estado.rollback = TRUE;
                                estado.end = TRUE;
                                estado.comp_lex_id = STRING;
                            }
                            break;

                        // String o Identificador
                        case 'r':
                        case 'R':
                            next();
                            // String
                            if (pdata.c == '"' || pdata.c == '\'') {
                                string_literal(&estado, pdata.c);
                            }
                            // Identificador
                            else if (isalpha(pdata.c) || pdata.c == '_' || isdigit(pdata.c)) {
                                identificador(&estado);
                            }
                            // Identificador <r> o <R>
                            else {
                                estado.rollback = TRUE;
                                estado.end = TRUE;
                                estado.comp_lex_id = STRING;
                            }
                            break;

                        default:
                            identificador(&estado);
                            break;
                    }
                }
                // Identificador
                else if (pdata.c == '_') {
                    identificador(&estado);
                }
                // Operadores
                else {
                    switch (pdata.c) {
                        // Delimitador ;
                        // Fin forzado de linea logica
                        case ';':
                            estado.rollback = FALSE;
                            estado.end = TRUE;
                            estado.comp_lex_id = pdata.c;
                        // Operadores y Delimitadores individuales
                        case '~':
                        case '@':
                        case ',':
                        case ':':
                        case '.':
                        case '`':
                            estado.rollback = FALSE;
                            estado.end = TRUE;
                            estado.comp_lex_id = pdata.c;
                            break;
                        // Desigual
                        case '!':
                            next();
                            // Operador negacion
                            if (pdata.c == '=') {
                                estado.rollback = FALSE;
                                estado.end = TRUE;
                                estado.comp_lex_id = DIFF;
                            }
                            // Caracter no disponible !
                            else {
                                // Error -> Caracter ilegal
                                raise(ILLEGAL_CARACTER_ERROR, pdata.row, pdata.col, TRUE);
                                // Continuamos el analisis
                            }
                            break;
                        // Operadores * **
                        // Delimitadores *= **=
                        case '*':
                            next();
                            if (pdata.c == '*') {
                                next();
                                // Delimitador **=
                                if (pdata.c == '=') {
                                    estado.rollback = TRUE;
                                    estado.end = TRUE;
                                    estado.comp_lex_id = EXP_EQ;
                                }
                                // Operador **
                                else {
                                    estado.rollback = TRUE;
                                    estado.end = TRUE;
                                    estado.comp_lex_id = EXP;
                                }
                            }
                            // Delimitador *=
                            else if (pdata.c == '=') {
                                estado.rollback = TRUE;
                                estado.end = TRUE;
                                estado.comp_lex_id = MULT_EQ;
                            }
                            // Operador *
                            else {
                                estado.rollback = TRUE;
                                estado.end = TRUE;
                                estado.comp_lex_id = '*';
                            }
                            break;
                        // Operadores < <= << <>
                        // Delimitador <<=
                        case '<':
                            next();
                            // Operador <=
                            if (pdata.c == '=') {
                                estado.rollback = FALSE;
                                estado.end = TRUE;
                                estado.comp_lex_id = LESS_EQ;
                            }
                            // Operador <>
                            else if (pdata.c == '>') {
                                estado.rollback = FALSE;
                                estado.end = TRUE;
                                estado.comp_lex_id = LESS_GREAT;
                            }
                            // Operador <<
                            // Delimitador <<=
                            else if (pdata.c == '<') {
                                next();
                                // Delimitador <<=
                                if (pdata.c == '=') {
                                    estado.rollback = FALSE;
                                    estado.end = TRUE;
                                    estado.comp_lex_id = SHITF_L_EQ;
                                }
                                // Operador <<
                                else {
                                    estado.rollback = TRUE;
                                    estado.end = TRUE;
                                    estado.comp_lex_id = SHITF_L;
                                }
                            }
                            // Operador <
                            else {
                                estado.rollback = TRUE;
                                estado.end = TRUE;
                                estado.comp_lex_id = '<';
                            }
                            break;
                        // Operadores > >= >>
                        // Delimitador >>=
                        case '>':
                            next();
                            // Operador >=
                            if (pdata.c == '=') {
                                estado.rollback = FALSE;
                                estado.end = TRUE;
                                estado.comp_lex_id = GREAT_EQ;
                            }
                            // Delimitador >>=
                            // Operador >>
                            else if (pdata.c == '>') {
                                next();
                                // Delimitador >>=
                                if (pdata.c == '=') {
                                    estado.rollback = FALSE;
                                    estado.end = TRUE;
                                    estado.comp_lex_id = SHIFT_R_EQ;
                                }
                                // Operador >>
                                else {
                                    estado.rollback = TRUE;
                                    estado.end = TRUE;
                                    estado.comp_lex_id = SHIFT_R;
                                }
                            }
                            // Operador >
                            else {
                                estado.rollback = TRUE;
                                estado.end = TRUE;
                                estado.comp_lex_id = '>';
                            }
                            break;
                        // Operadores / /=
                        // Delimitadores // //=
                        case '/':
                            next();
                            // Delimitador /=
                            if (pdata.c == '=') {
                                estado.rollback = FALSE;
                                estado.end = TRUE;
                                estado.comp_lex_id = DIV_EQ;
                            }
                            // Operador //
                            // Delimitador //=
                            else if (pdata.c == '/') {
                                next();
                                // Delimitador //=
                                if (pdata.c == '=') {
                                    estado.rollback = FALSE;
                                    estado.end = TRUE;
                                    estado.comp_lex_id = INT_DIV_EQ;
                                }
                                // Operador //
                                else {
                                    estado.rollback = TRUE;
                                    estado.end = TRUE;
                                    estado.comp_lex_id = INT_DIV;
                                }
                            }
                            // Operador /
                            else {
                                estado.rollback = TRUE;
                                estado.end = TRUE;
                                estado.comp_lex_id = '/';
                            }
                            break;
                        // Operador =
                        // Delimitador ==
                        case '=':
                            next();
                            // Operador =
                            if (pdata.c == '=') {
                                estado.rollback = FALSE;
                                estado.end = TRUE;
                                estado.comp_lex_id = EQ_EQ;
                            }
                            // Delimitador ==
                            else {
                                estado.rollback = TRUE;
                                estado.end = TRUE;
                                estado.comp_lex_id = '=';
                            }
                            break;
                        // Delimitador apertura
                        case '(':
                        case '[':
                        case '{':
                            // Comienzo de linea logica
                            llogica_caracter_apertura(pdata.c);
                            // Final de busqueda
                            estado.rollback = FALSE;
                            estado.end = TRUE;
                            estado.comp_lex_id = pdata.c;
                            break;
                        // Delimitador cerrado
                        case ')':
                        case ']':
                        case '}':
                            // Final de linea logica
                            llogica_caracter_cerrado(pdata.c);
                            // Final de busqueda
                            estado.rollback = FALSE;
                            estado.end = TRUE;
                            estado.comp_lex_id = pdata.c;
                            break;
                        // Operadores +
                        // Delimitadores +=
                        case '+':
                            next();
                            // Delimitador +=
                            if (pdata.c == '=') {
                                estado.rollback = FALSE;
                                estado.end = TRUE;
                                estado.comp_lex_id = PLUS_EQ;
                            }
                            // Operador +
                            else {
                                estado.rollback = TRUE;
                                estado.end = TRUE;
                                estado.comp_lex_id = '+';
                            }
                            break;
                        // Operador -
                        // Delimitador -=
                        case '-':
                            next();
                            // Delimitador -=
                            if (pdata.c == '=') {
                                estado.rollback = FALSE;
                                estado.end = TRUE;
                                estado.comp_lex_id = MINUS_EQ;
                            }
                            // Operador -
                            else {
                                estado.rollback = TRUE;
                                estado.end = TRUE;
                                estado.comp_lex_id = '-';
                            }
                            break;
                        // Operador &
                        // Delimitador &=
                        case '&':
                            next();
                            // Delimitador &=
                            if (pdata.c == '=') {
                                estado.rollback = FALSE;
                                estado.end = TRUE;
                                estado.comp_lex_id = AND_EQ;
                            }
                            // Operador &
                            else {
                                estado.rollback = TRUE;
                                estado.end = TRUE;
                                estado.comp_lex_id = '&';
                            }
                            break;
                        // Operador |
                        // Delimitador |=
                        case '|':
                            next();
                            // Delimitador |=
                            if (pdata.c == '=') {
                                estado.rollback = FALSE;
                                estado.end = TRUE;
                                estado.comp_lex_id = OR_EQ;
                            }
                            // Operador |
                            else {
                                estado.rollback = TRUE;
                                estado.end = TRUE;
                                estado.comp_lex_id = '|';
                            }
                            break;
                        // Operador
                        // Delimitador
                        case '^':
                            next();
                            // Delimitador ^=
                            if (pdata.c == '=') {
                                estado.rollback = FALSE;
                                estado.end = TRUE;
                                estado.comp_lex_id = XOR_EQ;
                            }
                            // Operador ^
                            else {
                                estado.rollback = TRUE;
                                estado.end = TRUE;
                                estado.comp_lex_id = '^';
                            }
                            break;
                        // Caracter desconocido
                        default:
                            // Error -> Caracter ilegal
                            raise(ILLEGAL_CARACTER_ERROR, pdata.row, pdata.col, TRUE);
                            break;
                    }
                }
                break;
        }
    }

    // Rollback de caracter en el sistema de entrada
    if (estado.rollback) {
        devolver_caracter();  // Funcion del sistema de entrada
    }

    // Identificador -> Busqueda e insercion en la tabla de simbolos
    if (estado.comp_lex_id == IDENTIFICADOR) {
        obtener_lexema(comp_lexico->lexema);
        comp_lexico->id = buscar_tabla_simbolos(comp_lexico->lexema);
    }
    // Salto de linea logico
    else if (estado.comp_lex_id == '\n') {
        // Lexema unico para el salto de linea logico
        char lexema[] = "\\n";
        // Introduccion de lexema propio
        strncpy(comp_lexico->lexema, lexema, strlen(lexema) + 1);
        comp_lexico->id = estado.comp_lex_id;
        // Limpiado de lexema
        limpiar_lexema();
    }
    // EOF -> Fin de analisis
    else if (estado.comp_lex_id == EOF) {
        return FALSE;  // No se devuelve componente lexico
    }
    // Otro -> Creacion del componente lexico
    else {
        // Insertamos valores
        obtener_lexema(comp_lexico->lexema);
        comp_lexico->id = estado.comp_lex_id;
    }

    // Devolucion de componente lexico
    return TRUE;
}

/**
 *
 *   - DEFINICION -
 *       - DE -
 *    - AUTOMATAS -
 *
 */
// String
void string_literal(State *estado, char comilla) {
    next();
    // Fin de string o docstring
    if (pdata.c == comilla) {
        next();
        // Docstring
        if (pdata.c == comilla) {
            docstring_literal(estado, comilla);
        }
        // Fin de string
    } else {
        do {
            // No se finaliza la cadena
            if (pdata.c == '\n') {
                raise(END_STRING_ERROR, pdata.row, pdata.col, TRUE);
                newline();  // Modificamos row y col
                break;
            }
            // Escape de caracter
            else if (pdata.c == '\\') {
                next();  // Caracter escapado
                if (pdata.c == '\n') {
                    newline();  // Modificamos row y col
                }
            }
            next();
        } while (pdata.c != comilla);
        estado->rollback = FALSE;
        estado->end = TRUE;
        estado->comp_lex_id = STRING;
    }
}
// Docstring
void docstring_literal(State *estado, char comilla) {
    short int n_comillas = 0;
    do {
        next();
        // Contabilizamos comilla
        if (pdata.c == comilla) {
            n_comillas++;
        }
        // Escape de caracter
        else {
            if (pdata.c == '\\') {
                next();  // Caracter escapado
            }
            // Tenemos en cuenta cambios de linea aun habiendolos escapado
            // en el anterior if
            if (pdata.c == '\n') {
                newline();  // Modificamos row y col
            }
            n_comillas = 0;
        }
    } while (n_comillas < 3);
    estado->rollback = FALSE;
    estado->end = TRUE;
    estado->comp_lex_id = STRING;
}
// Entero
void integer_literal(State *estado) {
    // Leemos enteros
    do {
        next();
    } while (isdigit(pdata.c));
    // Hasta que leemos otro caracter
    // Float de punto flotante
    if (pdata.c == '.') {
        point_float_literal(estado);
    }
    // Float de exponente
    else if (pdata.c == 'e' || pdata.c == 'E') {
        exponent_float_literal(estado);
    }
    // Finalizamos
    else {
        estado->rollback = TRUE;
        estado->end = TRUE;
        estado->comp_lex_id = INT;
    }
}
// Entero binario
void binary_literal(State *estado) {
    // Leemos binario
    do {
        next();
    } while (isdigit(pdata.c) && pdata.c - '0' < 2);
    estado->rollback = TRUE;
    estado->end = TRUE;
    estado->comp_lex_id = INT;
}
// Entero hexadecimal
void hexadecimal_literal(State *estado) {
    // Leemos hexadecimal
    do {
        next();
    } while (isdigit(pdata.c) ||
             ((islower(pdata.c) && pdata.c < 'g') || (isupper(pdata.c) && pdata.c < 'G')));
    estado->rollback = TRUE;
    estado->end = TRUE;
    estado->comp_lex_id = INT;
}
// Entero octal
void octal_literal(State *estado) {
    // Leemos octal
    do {
        next();
    } while (isdigit(pdata.c) && pdata.c < '8');
    estado->rollback = TRUE;
    estado->end = TRUE;
    estado->comp_lex_id = INT;
}
// Float de punto flotante
void point_float_literal(State *estado) {
    do {
        next();
    } while (isdigit(pdata.c));
    // Float de exponente
    if (pdata.c == 'e' || pdata.c == 'E') {
        exponent_float_literal(estado);
    }
    // Finalizamos
    else {
        estado->rollback = TRUE;
        estado->end = TRUE;
        estado->comp_lex_id = FLOAT;
    }
}
// Float de exponente
void exponent_float_literal(State *estado) {
    do {
        next();
    } while (isdigit(pdata.c));
    estado->rollback = TRUE;
    estado->end = TRUE;
    estado->comp_lex_id = FLOAT;
}
// Identificador
void identificador(State *estado) {
    do {
        next();
    } while (isalpha(pdata.c) || pdata.c == '_' || isdigit(pdata.c));
    estado->rollback = TRUE;
    estado->end = TRUE;
    estado->comp_lex_id = IDENTIFICADOR;
}
