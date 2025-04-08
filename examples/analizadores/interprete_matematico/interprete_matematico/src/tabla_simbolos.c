#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "boolean.h"
#include "tabla_simbolos.h"
#include "funciones_propias.h"
#include "componente_lexico.h"
#include "arbol_avl.h"
#include "definiciones.h"

/* Tabla de simbolos y macro asociada */
ArbolAVL ts;

// Inicializacion de la Tabla de Simbolos
void inicializacion_tabla_simbolos() {
    // Inicializacion del arbol AVL
    crear_arbol(&ts);

    /* Funciones trigonométricas */
    insertar(&ts, "acos", FUNCION, (Datos){.dfm = {.fncptr = acos}});
    insertar(&ts, "asin", FUNCION, (Datos){.dfm = {.fncptr = asin}});
    insertar(&ts, "atan", FUNCION, (Datos){.dfm = {.fncptr = atan}});
    insertar(&ts, "cos", FUNCION, (Datos){.dfm = {.fncptr = cos}});
    insertar(&ts, "cosh", FUNCION, (Datos){.dfm = {.fncptr = cosh}});
    insertar(&ts, "sin", FUNCION, (Datos){.dfm = {.fncptr = sin}});
    insertar(&ts, "sinh", FUNCION, (Datos){.dfm = {.fncptr = sinh}});
    insertar(&ts, "tanh", FUNCION, (Datos){.dfm = {.fncptr = tanh}});

    /* Funciones matemáticas */
    insertar(&ts, "log", FUNCION, (Datos){.dfm = {.fncptr = log}});
    insertar(&ts, "log10", FUNCION, (Datos){.dfm = {.fncptr = log10}});
    insertar(&ts, "ceil", FUNCION, (Datos){.dfm = {.fncptr = ceil}});
    insertar(&ts, "floor", FUNCION, (Datos){.dfm = {.fncptr = floor}});

    /* Constantes */
    insertar(&ts, "PI", CONSTANTE, (Datos){.di = {.inicializado = TRUE, .valor = M_PI}});
    insertar(&ts, "E", CONSTANTE, (Datos){.di = {.inicializado = TRUE, .valor = M_E}});
    insertar(&ts, "TRUE", CONSTANTE, (Datos){.di = {.inicializado = TRUE, .valor = TRUE}});
    insertar(&ts, "FALSE", CONSTANTE, (Datos){.di = {.inicializado = TRUE, .valor = FALSE}});

    /* Funciones del interprete sin argumentos */
    insertar(&ts, "help", FP_NARGS, (Datos){.dfp = {.tipo = FP_HELP, .fncptr = help}});
    insertar(&ts, "workspace", FP_NARGS, (Datos){.dfp = {.tipo = FP_WORKSPACE, .fncptr = workspace}});
    insertar(&ts, "cleanall", FP_NARGS, (Datos){.dfp = {.tipo = FP_CLEAN_ALL, .fncptr = clean_all}});
    insertar(&ts, "exit", FP_NARGS, (Datos){.dfp = {.tipo = FP_EXIT, .fncptr = print_exit}});
    
    /* Funciones del interprete con un argumento */
    insertar(&ts, "echo", FP_ONEARG, (Datos){.dfp = {.tipo = FP_ECHO, .fncptr = (void (*)())echo}});
    insertar(&ts, "load", FP_ONEARG, (Datos){.dfp = {.tipo = FP_LOAD, .fncptr = (void (*)())load}});
    insertar(&ts, "import", FP_ONEARG, (Datos){.dfp = {.tipo = FP_IMPORT, .fncptr = (void (*)())import}});
    insertar(&ts, "clean", FP_ONEARG, (Datos){.dfp = {.tipo = FP_CLEAN_VAR, .fncptr = (void (*)())clean_var}});

    /* Funciones del interprete con una expresión como argumento */
    insertar(&ts, "print", FP_EXPARG, (Datos){.dfp = {.tipo = FP_PRINT, .fncptr = (void (*)())print}});
}

// Busqueda de un lexema e inserción si no se encuentra
CompLexico *buscar_insertar_tabla_simbolos(const char *lexema, int id, Datos datos) {
    // Buscamos el componente lexico
    CompLexico *cl = buscar(ts, lexema);

    // Insertamos el componente si no se encuentra en la tabla
    return (cl != NULL ? cl : insertar(&ts, lexema, id, datos));
}

// Busqueda de un lexema
CompLexico *buscar_tabla_simbolos(const char *lexema) {
    // Buscamos el componente lexico y lo devolvemos
    return buscar(ts, lexema);
}

// Inserción de un elemento en la tabla de simblolos
CompLexico *insertar_tabla_simbolos(const char *lexema, int id, Datos datos) {
    // Insertamos y devolvemos si se inserto correctamente
    return insertar(&ts, lexema, id, datos);
}

// Borrado de un componente
void quitar_tabla_simbolos(const char *lexema) {
    eliminar(&ts, lexema);
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