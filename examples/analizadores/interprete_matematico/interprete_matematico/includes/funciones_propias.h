#ifndef __FUNCIONES_PROPIAS_H__
#define __FUNCIONES_PROPIAS_H__

#include "componente_lexico.h"

/* Identificadores de funciones */
#define FP_ECHO      100
#define FP_HELP      101
#define FP_LOAD      102
#define FP_WORKSPACE 103
#define FP_CLEAN_ALL 104
#define FP_CLEAN_VAR 105
#define FP_IMPORT    106
#define FP_EXIT      107
#define FP_PRINT     108

/* FUNCIONES PRIVADAS DEL INTERPRETE */
/**
 * Añade una variable a la sesión
 * @param cl Componente léxico de la variable a añadir
 */
void add_to_sesion(CompLexico *cl);

/**
 * Añade la referencia a una funcion importada
 * @param fnc Componente léxico de la función a añadir
 */
void add_fnc(CompLexico *fnc);

/**
 * Busca una función en las librerías importadas
 * @param fnc Nombre de la función
 * @return Puntero a la función o NULL si no se encuentra
 */
double *lookup_fnc(const char *fnc);

/**
 * Impresión del prompt
 */
void print_prompt();

/**
 * Impresión de un resultado
 * @param result Resultado a imprimir
 */
void print_output(double result);

/**
 * Confirma el guardado de las variables en la lista temporal
 */
void commit_variables();

/**
 * Elimina las variables de la lista temporal
 */
void rollback_variables();

/* FUNCIONES VISIBLES PARA EL USUARIO */
/**
 * Imprime la ayuda del interprete
 */
void help();

/**
 * Comunica al analizador si debe imprimir el resultado
 * @param do_print Booleano TRUE si se quiere imprimir la salida
 * o FALSE en caso contrario
 */
void echo(bool do_print);

/**
 * Imprime un valor por pantalla
 * @param value Valor a imprimir por pantalla
 */
void print(double value);

/**
 * Carga un fichero de instrucciones
 * @param path Ruta absoluta o relativa al archivo
 * @return Booleano que indica si se ha podido cargar el archivo
 */
bool load(const char *path);

/**
 * Imprime nombre y valor de las variables y constantes
 * de la sesión definidas por el usuario
 */
void workspace();

/**
 * Incluye dinamicamente una libreria de funciones matemáticas
 * @param lib Ruta a la libreria
 * @return Devuelve un booleano indicando si se ha encontrado la libreria
 */
bool import(const char *libreria);

/**
 * Elimina la variable o constante de la sesión,
 * teniendo que haber sido definida por el usuario
 * con anterioridad
 * @param variable Lexema de la variable o constante a eliminar
 * @return Devuelve un booleano indicando si se ha eliminado el elemento
 */
bool clean_var(const char *variable);

/**
 * Elimina las variables o constantes de la sesión,
 * teniendo que haber sido definidas por el usuario
 * con anterioridad
 */
void clean_all();

/**
 * Comunica la finalización del interprete
 */
void print_exit();

/**
 * Liberación de memoria de las funciones propias
 */
void finalizacion_funciones();

#endif  //__FUNCIONES_PROPIAS_H__