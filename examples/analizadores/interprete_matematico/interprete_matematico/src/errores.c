#include <stdio.h>
#include <string.h>
#include "errores.h"

// Impresion de error
void raise_error(int flag, const char *cause) {
    printf(" \x1b[1;31m** ");
    // Impresion del error correspondiente
    switch (flag) {
        // Caracter ilegal
        case ERR_UNMACHED_CHAR:
            printf("Caracter %c no reconocido", cause[0]);
            break;

        // String ilegal
        case ERR_INVALID_STRING:
            printf("String ilegal detectado");
            break;

        // Expresiones juntas sin operador
        case ERR_DIVISION_BY_0:
            printf("División por 0");
            break;

        // Variable sin definir
        case ERR_SYMBOL_NOT_DEFINED:
            printf("Símbolo %s no definido", cause);
            break;

        // Constante sin definir
        case ERR_CONSTANT_NOT_DEFINED:
            printf("Constante %s no definida", cause);
            break;

        // Constante ya definida
        case ERR_CONSTANT_REDEFINITION:
            printf("No es posible redefinir la constante %s", cause);
            break;

        // Llamada inválida a función
        case ERR_INVALID_FUNCTION_CALL:
            printf("Llamada de la función %s no válida", cause);
            break;

        // Argumento invalido
        case ERR_INVALID_ARGUMENT:
            printf("Argumento no válido en la llamada a la función %s", cause);
            break;

        // Argumento de tipo invalido
        case ERR_INVALID_ARGUMENT_TYPE:
            printf("Tipo de argumento no válido en la llamada a la función %s", cause);
            break;

        // ipo de dato para almacén de valor invalido
        case ERR_INVALID_ASSIGN_TYPE:
            printf("Imposible asignarle un valor al elemento deseado");
            break;

        // Archivo no encontrado
        case ERR_FILE_NOT_FOUND:
            printf("No existe fichero en la ruta \"%s\"", cause);
            break;

        // Librería no encontrada
        case ERR_LIB_NOT_FOUND:
            printf("No existe librería en la ruta \"%s\"", cause);
            break;

        // Error de sintaxis de bison
        case ERR_UNKNOWN_ERROR:
        default:
            printf("%s", cause);
            break;
    }
    printf(" **\x1b[0m\n");
}