#include <stdio.h>
#include <string.h>
#include "errores.h"

// Mostrado de errores ocurridos
void raise(int error, int row, int col, bool localizado) {
    // Impresion de fila y columna si es especificado
    if (localizado)
        printf("\x1b[31m[ ERROR <Line %d, Col %d> ] ", row, col);
    else
        printf("\x1b[31m[ ERROR ] ");

    // Impresion de error correspondiente
    switch (error) {
        // Salto de linea sin finalizar el string
        case END_STRING_ERROR:
            printf("STRING ILEGAL: Comilla no encontrada antes de fin de línea\x1b[0m\n");
            break;

        // Caracter no reconocido
        case ILLEGAL_CARACTER_ERROR:
            printf("CARACTER ILEGAL: Caracter leído no admitido\x1b[0m\n");
            break;
    }
}