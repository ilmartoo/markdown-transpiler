#ifndef __SISTEMA_ENTRADA_H__
#define __SISTEMA_ENTRADA_H__

#include "boolean.h"

/**
 * Inicizaliza el sistema de entrada
 * @param nombre_fichero Nombre del fichero de codigo a analizar
 * @return TRUE si el fichero existe, FALSE en caso contrario o ocurre un error
 */
bool inicializacion_sistema_entrada(char *nombre_fichero);

/**
 * Devuelve el siguiente caracter del fichero de codigo
 * @return Siguiente caracter encontrado
 */
char siguiente_caracter();

/**
 * Establece el inicio del lexema al caracter actual
 */
void limpiar_lexema();

/**
 * Retrocede un caracter en el sistema de entrada
 */
void devolver_caracter();

/**
 * Recupera el lexema actual
 * @param dst Buffer inicializado donde se almacenará el lexema
 */
void obtener_lexema(char *dst);

/**
 * Liberacion de memoria del sistema de entrada
 */
void cerrado_sistema_entrada();

#endif  //__SISTEMA_ENTRADA_H__