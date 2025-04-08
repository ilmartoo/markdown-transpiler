#include <stdio.h>
#include <stdlib.h>
#include "analizador_lexico.h"
#include "boolean.h"

void inicio_analizador_sitactico() {
    // Comienzo de lectura
    printf("\n\e[1;34m>> COMIENZO DEL ANALIZADOR SINTÁCTICO <<\e[0m\n");

    // Buffer de componente lexico
    CompLexico comp_lexico = {.lexema = NULL};

    // Peticion de componente lexico
    while (siguiente_componente_lexico(&comp_lexico)) {
        // Impresion de componente lexico
        printf("<\"%s\", %d>\n", comp_lexico.lexema, comp_lexico.id);
    }
    // Free del ultimo lexema
    free(comp_lexico.lexema);

    // Final de lectura
    printf("\e[1;34m>> FINAL DEL ANALIZADOR SINTÁCTICO <<\e[0m\n");
}