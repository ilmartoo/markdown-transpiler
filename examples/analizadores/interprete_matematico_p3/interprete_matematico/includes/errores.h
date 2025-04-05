#ifndef __ERRORES_H__
#define __ERRORES_H__

/* Flag de comunicación flex/bison en la recuperación de errores */
#define STOP_CURRENT_ANALISIS     1300  // Necesaria para parar el analisis del comando actual

/* Flags de error */
#define ERR_UNMACHED_CHAR         1310  // Caracter ilegal
#define ERR_INVALID_STRING        1311  // String ilegal

#define ERR_DIVISION_BY_0         1320  // División por 0

#define ERR_SYMBOL_NOT_DEFINED    1330  // Variable sin definir
#define ERR_CONSTANT_NOT_DEFINED  1331  // Constante sin definir
#define ERR_CONSTANT_REDEFINITION 1332  // Constante ya definida

#define ERR_INVALID_FUNCTION_CALL 1340  // Llamada invalida a función
#define ERR_INVALID_ARGUMENT      1341  // Argumento invalido
#define ERR_INVALID_ARGUMENT_TYPE 1342  // Argumento de tipo invalido
#define ERR_INVALID_ASSIGN_TYPE   1343  // Tipo de dato para almacén de valor invalido

#define ERR_FILE_NOT_FOUND        1350  // Archivo no encontrado
#define ERR_LIB_NOT_FOUND         1351  // Librería no encontrada

#define ERR_UNKNOWN_ERROR         1400  // Flag para permitir imprimir errores de bison inesperados

/**
 * Imprime un error
 * @param err Identificador del error
 * @param cause Cadena de error
 */
void raise_error(int err, const char *cause);

#endif  //__ERRORES_H__