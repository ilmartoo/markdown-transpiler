#include <stdio.h>
#include <stdlib.h>
#include "tabla_simbolos.h"
#include "analizador_sintactico.h"
#include "analizador_lexico.h"
#include "definiciones.h"

void inicio();
void consola();
void cierre();

// Ejecución del analizador léxico
int main(int argc, char **argv) {
    // Salimos si se introducen argumentos
    if (argc > 1) {
        printf("\x1b[31m ** Demasiados argumentos en la llamada al programa **\x1b[0m\n");
        return EXIT_FAILURE;
    }

    /* Inicializacion */
    inicio();
    
    /* Parser */
    yyparse();

    /* Cerrado */
    cierre();

    // Ejecucion correcta
    return EXIT_SUCCESS;
}

// Inicialización de modulos
void inicio() {
    inicializacion_tabla_simbolos();
    inicializacion_analizador_lexico();
    inicializacion_analizador_sintactico();
}

// Cerrado de modulos
void cierre() {
    cerrado_analizador_sintactico();
    cerrado_analizador_lexico();
    cerrado_tabla_simbolos();
}