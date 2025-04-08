#ifndef __TABLA_SIMBOLOS_H__
#define __TABLA_SIMBOLOS_H__

#include "componente_lexico.h"

/**
 * Inicializacion de la Tabla de Simbolos
 */
void inicializacion_tabla_simbolos();

/**
 * Busqueda de un lexema en la tabla de simbolos
 * @param lexema Lexema a buscar en la tabla de simbolos
 * @return Identificador de componente lexico asociado al lexema
 */
int buscar_tabla_simbolos(char *lexema);

/**
 * Liberacion de memoria de la tabla de simbolos
 */
void cerrado_tabla_simbolos();

/**
 * Impresion de la TS
 */
void imprimir_tabla_simbolos();

#endif  //__TABLA_SIMBOLOS_H__