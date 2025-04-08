#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "tabla_simbolos.h"
#include "arbol_avl.h"
#include "definiciones.h"

/* Tabla de simbolos */
ArbolAVL ts;

// Inicializacion de la Tabla de Simbolos
void inicializacion_tabla_simbolos() {
    // Inicializacion del arbol AVL
    crear_arbol(&ts);
    // Introduccion de keywords
    insertar(&ts, "return", RETURN);
    insertar(&ts, "pass", PASS);
    insertar(&ts, "^=", XOR_EQ);
    insertar(&ts, "elif", ELIF);
    insertar(&ts, "exec", EXEC);
    insertar(&ts, "*=", MULT_EQ);
    insertar(&ts, "<<", SHITF_L);
    insertar(&ts, "not", NOT);
    insertar(&ts, "assert", ASSERT);
    insertar(&ts, "import", IMPORT);
    insertar(&ts, "continue", CONTINUE);
    insertar(&ts, "try", TRY);
    insertar(&ts, "%=", MOD_EQ);
    insertar(&ts, "**", EXP);
    insertar(&ts, "==", EQ_EQ);
    insertar(&ts, "del", DEL);
    insertar(&ts, "as", AS);
    insertar(&ts, "or", OR);
    insertar(&ts, "if", IF);
    insertar(&ts, "break", BREAK);
    insertar(&ts, "class", CLASS);
    insertar(&ts, "raise", RAISE);
    insertar(&ts, "is", IS);
    insertar(&ts, "for", FOR);
    insertar(&ts, "-=", MINUS_EQ);
    insertar(&ts, "//=", INT_DIV_EQ);
    insertar(&ts, "|=", OR_EQ);
    insertar(&ts, "<<=", SHITF_L_EQ);
    insertar(&ts, ">>", SHIFT_R_EQ);
    insertar(&ts, ">=", GREAT_EQ);
    insertar(&ts, "<>", LESS_GREAT);
    insertar(&ts, "and", AND);
    insertar(&ts, "from", FROM);
    insertar(&ts, "while", WHILE);
    insertar(&ts, "global", GLOBAL);
    insertar(&ts, "with", WITH);
    insertar(&ts, "else", ELSE);
    insertar(&ts, "yield", YIELD);
    insertar(&ts, "except", EXCEPT);
    insertar(&ts, "print", PRINT);
    insertar(&ts, "in", IN);
    insertar(&ts, "finally", FINALLY);
    insertar(&ts, "def", DEF);
    insertar(&ts, "lambda", LAMBDA);
    insertar(&ts, "+=", PLUS_EQ);
    insertar(&ts, "/=", DIV_EQ);
    insertar(&ts, "&=", AND_EQ);
    insertar(&ts, ">>=", SHIFT_R_EQ);
    insertar(&ts, "**=", EXP_EQ);
    insertar(&ts, "//", INT_DIV);
    insertar(&ts, "<=", LESS_EQ);
    insertar(&ts, "!=", DIFF);
}

// Busqueda de un lexema
int buscar_tabla_simbolos(char *lexema) {
    // Buscamos el lexema
    int codigo = buscar(ts, lexema);
    // Insertamos en la tabla si no se encuentra
    if (codigo == SIN_CODIGO) {
        insertar(&ts, lexema, IDENTIFICADOR);
        // Devolvemos identificador
        return IDENTIFICADOR;
    }
    // Devolvemos el código
    else {
        return codigo;
    }
}

// Liberacion de memoria de la tabla de simbolos
void cerrado_tabla_simbolos() {
    borrar_arbol(&ts);
}

// Impresion de la TS
void imprimir_tabla_simbolos() {
    printf("\n\e[1;34m>> INICIO TABLA DE SIMBOLOS <<\e[0m\n");
    imprimir(ts);
    printf("\e[1;34m>> FIN TABLA DE SIMBOLOS <<\e[0m\n");
}