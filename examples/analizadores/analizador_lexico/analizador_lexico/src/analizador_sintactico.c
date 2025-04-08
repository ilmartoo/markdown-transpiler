#include <stdio.h>
#include <stdlib.h>
#include "analizador_lexico.h"
#include "boolean.h"

void inicio_analizador_sitactico() {
    // Comienzo de lectura
    printf("\n\e[1;34m>> COMIENZO DEL ANALIZADOR SINTÁCTICO <<\e[0m\n");

    // Buffer de lexema de tamaño maximo + 1 para '\0'
    char lexema[TAM_LEXEMA * 2 + 1];
    lexema[TAM_LEXEMA * 2] = '\0';
    // Buffer de componente lexico
    CompLexico comp_lexico = {.lexema = lexema};

    // Peticion de componente lexico
    while (siguiente_componente_lexico(&comp_lexico)) {
        // Impresion de componente lexico
        printf("<\"%s\", %d>\n", comp_lexico.lexema, comp_lexico.id);
    }

    // Final de lectura
    printf("\e[1;34m>> FINAL DEL ANALIZADOR SINTÁCTICO <<\e[0m\n");
}
