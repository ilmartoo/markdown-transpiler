#ifndef __ERRORES_H__
#define __ERRORES_H__

#include "boolean.h"

/* Flags de error */
#define BLOCK_SIZE_ERROR       1
#define END_STRING_ERROR       2
#define ILLEGAL_CARACTER_ERROR 3

/**
 * Imprime un error por pantalla estableciendo linea y columna de ocurrencia
 * @param error Flag del error ocurrido
 * @param row Fila de localizacion del error
 * @param col Columna de localizacion del error
 * @param localizado Boolean para imprimir la localizacion del error
 */
void raise(int error, int row, int col, bool localizado);

#endif  //__ERRORES_H__