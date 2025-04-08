#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "sistema_entrada.h"
#include "componente_lexico.h"
#include "errores.h"

/* Estructura de memoria de centinela */
typedef struct Centinela Centinela;
struct Centinela {
    FILE *fichero;                 // Puntero a fichero de codigo
    char bloqueA[TAM_LEXEMA + 1];  // Bloque A de carga de fichero
    char bloqueB[TAM_LEXEMA + 1];  // Bloque B de carga de fichero
    char *inicio;                  // Puntero inicio de lexema
    char *delantero;               // Puntero fin de lexema
    bool bloqueA_principal;        // Establece si el bloque principal es el bloque A
    bool inicio_en_principal;      // Flag de localizacion de puntero inicio
};

/* Macros para determinar el bloque principal y secundario */
#define bloque_principal(c)  (c.bloqueA_principal ? c.bloqueA : c.bloqueB)
#define bloque_secundario(c) (c.bloqueA_principal ? c.bloqueB : c.bloqueA)

/* Variables globales */
Centinela cent;

// Guardado de lexema cuando se borra bloque secundario con inicio en el
void leer_nuevo_bloque(char *bloque_dst) {
    // Leemos y incluimos EOF si se leen menos caracteres de los que se quieren
    long n_leidos = fread(bloque_dst, sizeof(char), TAM_LEXEMA, cent.fichero);
    if (TAM_LEXEMA > n_leidos) {
        bloque_dst[n_leidos] = EOF;
    }
}

// Carga de fichero
bool inicializacion_sistema_entrada(char *nombre_fichero) {
    // Inicializacion del centinela
    cent.fichero = NULL;
    cent.inicio = cent.delantero = cent.bloqueA;
    cent.bloqueA_principal = TRUE;
    cent.inicio_en_principal = TRUE;

    // Carga de fichero
    cent.fichero = fopen(nombre_fichero, "r");

    // Si no existe fichero salimos
    if (cent.fichero == NULL)
        return FALSE;

    // Inclusion de EOF centinela
    cent.bloqueA[TAM_LEXEMA] = cent.bloqueB[TAM_LEXEMA] = EOF;

    // Lectura de primer bloque
    leer_nuevo_bloque(bloque_principal(cent));

    return TRUE;
}

// Siguiente caracter del fichero
char siguiente_caracter() {
    // Fin de bloque o fin de fichero
    if (*cent.delantero == EOF) {
        // EOF del bloque principal
        if (cent.delantero == (bloque_principal(cent) + TAM_LEXEMA)) {
            // Comprobamos si inicio esta en el bloque secundario
            if (!cent.inicio_en_principal) {
                // Error -> Perdida de parte inicial del lexema
                raise(BLOCK_SIZE_ERROR, 0, 0, FALSE);

                // Cambiamos localizacion de inicio
                // El bloque principal pasara a ser el secundario
                cent.inicio = bloque_principal(cent);
            }

            // Lectura de proximo bloque
            leer_nuevo_bloque(bloque_secundario(cent));

            // Nuevo bloque cargado pasa a ser bloque principal
            cent.bloqueA_principal = !cent.bloqueA_principal;

            // Establecemos nueva posicion de fin de lexema
            cent.delantero = bloque_principal(cent);

            // Inicio pasa a estar en el bloque secundario
            cent.inicio_en_principal = FALSE;
        }
        // Fin de fichero
        else {
            cent.delantero++;
            return EOF;
        }
        // No necesitamos comprobar el fin del bloque secundario
        // pues al intercambiar bloque principal y bloque secundario
        // cada vez que se llega a fin de bloque nos aseguramos que
        // el proximo EOF es o fin de bloque principal o fin de fichero
    }

    // Lectura del caracter
    char actual = *cent.delantero;
    cent.delantero++;  // Apuntamos al proximo caracter a leer
    return actual;
}

// Rollback
void devolver_caracter() {
    // Tal como opera delantero, nunca coincidirá
    // en el primer lugar de un bloque, pudiendo
    // retroceder sin problema.
    // Tampoco se va a retroceder dos veces seguidas
    // puesto que es necesario leer un caracter para
    // decidir si retroceder.
    cent.delantero--;
}

// Establece el inicio del lexema en el caracter actual
void limpiar_lexema() {
    cent.inicio = cent.delantero;
    cent.inicio_en_principal = TRUE;
}

// Lexema leido
void obtener_lexema(char *dst) {
    char *lexema = NULL;

    // Comprobamos a que bloque apunta el inicio del lexema
    //
    // Inicio de lexema en bloque principal
    if (cent.inicio_en_principal) {
        // Cálculo de caracteres a leer
        long int dist = cent.delantero - cent.inicio;

        // Copiado de caracteres del bloque principal
        strncpy(dst, cent.inicio, dist);
        dst[dist] = '\0';
    }
    // Inicio de lexema en bloque secundario
    else {
        // Cálculo de caracteres a leer
        long int dist = bloque_secundario(cent) + TAM_LEXEMA - cent.inicio;
        long int dist_aux = cent.delantero - bloque_principal(cent);

        // Copiado de caracteres del bloque secundario y principal
        strncpy(dst, cent.inicio, dist);
        strncpy(dst + dist, bloque_principal(cent), dist_aux);
        dst[dist + dist_aux] = '\0';
    }

    // Comienzo de nuevo lexema y limpiado de buffer extra
    limpiar_lexema();

    return lexema;
}

// Cerrado de fichero y liberacion de memoria
void cerrado_sistema_entrada() {
    // Cerrado de fichero
    fclose(cent.fichero);
    cent.fichero = NULL;
}