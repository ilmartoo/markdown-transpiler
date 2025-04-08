#include <stdio.h>
#include <stdlib.h>
#include "sistema_entrada.h"
#include "tabla_simbolos.h"
#include "pila.h"
#include "analizador_sintactico.h"
#include "analizador_lexico.h"

// Ejecución del analizador léxico
int main(int argc, char **argv) {
    // Salimos si no se pasa el archivo a analizar
    if (argc < 2) {
        printf("\x1b[31m** No se ha proporcionado un archivo\x1b[0m\n");
        return EXIT_FAILURE;
    }
    else if (argc > 2) {
        printf("\x1b[31m** Demasiados argumentos en la llamada al programa\x1b[0m\n");
        return EXIT_FAILURE;
    }

    // Inicializacion de tabla de simbolos y el analizador lexico
    inicializacion_tabla_simbolos();
    inicializacion_analizador_lexico();

    // Impresion de la tabla de simbolos inicial
    imprimir_tabla_simbolos();

    // Inicializamos el sistema de entrada
    if (inicializacion_sistema_entrada(argv[1])) {
        // Inicio del analisis sintactico
        inicio_analizador_sitactico();

        // Impresion de la tabla de simbolos inicial
        imprimir_tabla_simbolos();
    }
    // Fallo de inicializacion del sistema de entrada
    else {
        printf("\n\x1b[31mFallo al intentar analizar el archivo\x1b[0m\n");
    }

    // Cerrado del analizador lexico, tabla de simbolos y sistema de entrada
    cerrado_sistema_entrada();
    cerrado_analizador_lexico();
    cerrado_tabla_simbolos();

    // Ejecucion correcta
    return EXIT_SUCCESS;
}