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
 * Liberacion de memoria del sistema de entrada
 */
void cerrado_sistema_entrada();

#endif  //__SISTEMA_ENTRADA_H__