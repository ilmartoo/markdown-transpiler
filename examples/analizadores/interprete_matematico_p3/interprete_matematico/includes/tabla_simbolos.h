#ifndef __TABLA_SIMBOLOS_H__
#define __TABLA_SIMBOLOS_H__

#include "componente_lexico.h"

/**
 * Inicializacion de la Tabla de Simbolos
 */
void inicializacion_tabla_simbolos();

/**
 * Busqueda de un lexema en la tabla de simbolos, se inserta si no existe
 * @param lexema Lexema a buscar en la tabla de simbolos
 * @param codigo Identificador inicial asociado al lexema
 * @param datos Datos del componente léxico
 * @return Componente lexico asociado al lexema o NULL si ocurrió algún error al insertar
 */
CompLexico *buscar_insertar_tabla_simbolos(const char *lexema, int id, Datos datos);

/**
 * Busqueda de un lexema en la tabla de simbolos
 * @param lexema Lexema a buscar en la tabla de simbolos
 * @return Componente lexico asociado al lexema o NULL si no se encuentra
 */
CompLexico *buscar_tabla_simbolos(const char *lexema);

/**
 * Inserción de un lexema en la tabla de simbolos
 * @param lexema Lexema a buscar en la tabla de simbolos
 * @param id Id del componente léxico
 * @param datos Datos del componente léxico
 * @return Componente lexico asociado al lexema o NULL si ocurrió algún error al insertar
 */
CompLexico *insertar_tabla_simbolos(const char *lexema, int id, Datos datos);

/**
 * Borrado de un componente de la tabla de simbolos
 * @param lexema Lexema del componente a eliminar
 */
void quitar_tabla_simbolos(const char *lexema);

/**
 * Liberacion de memoria de la tabla de simbolos
 */
void cerrado_tabla_simbolos();

/**
 * Impresion de la TS
 */
void imprimir_tabla_simbolos();

#endif  //__TABLA_SIMBOLOS_H__