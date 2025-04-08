#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol_avl.h"
#include "boolean.h"
#include "componente_lexico.h"
#include "definiciones.h"

/* Estruturas y constantes */
// Constante Nodo para dar legibilidad al código
#define Nodo ArbolAVL
// Nodo del arbol AVL
struct struct_NodoAVL {
    CompLexico cl;                     // Componente léxico
    struct struct_NodoAVL *izq, *der;  // Hijos del nodo
    int altura;                        // Altura del nodo
};

/* Macro de cálculo de máximo */
#define max(a, b) (a > b ? a : b)

// Creación del árbol
void crear_arbol(ArbolAVL *arbol) {
    if (arbol != NULL) {
        *arbol = NULL;
    }
}

// Borrado recursivo del árbol
void borrar_arbol(ArbolAVL *arbol) {
    if (arbol != NULL && *arbol != NULL) {
        // Borrado de rama izquierda
        if ((*arbol)->izq != NULL)
            borrar_arbol(&(*arbol)->izq);
        // Borrado de rama derecha
        if ((*arbol)->der != NULL)
            borrar_arbol(&(*arbol)->der);
        // Liberacion de memoria de nodo actual
        free((*arbol)->cl.lexema);
        free(*arbol);
    }
}

// Obtencion de la altura del arbol con raiz en el nodo
int altura(Nodo nodo) {
    return nodo == NULL ? 0 : nodo->altura;
}

// Factor de balance para un nodo
int balance_nodo(Nodo nodo) {
    return nodo == NULL ? 0 : altura(nodo->izq) - altura(nodo->der);
}

// Creación de nuevo nodo
Nodo nuevo_nodo(const char *lexema, int id) {
    // Reservamos memoria
    Nodo nuevo = (Nodo)malloc(sizeof(struct struct_NodoAVL));
    nuevo->cl.lexema = (char *)malloc(strlen(lexema) + 1);
    // Inicializamos valores
    nuevo->altura = 1;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    // Establecemos componente léxico
    strncpy(nuevo->cl.lexema, lexema, strlen(lexema) + 1);
    nuevo->cl.id = id;

    return nuevo;
}

// Balanceo del arbol
void balancear(ArbolAVL *arbol);

// Inserción de lexemas e ids en el árbol
// No se contempla la insercion de claves existentes
void insertar(ArbolAVL *arbol, const char *lexema, int id) {
    if (arbol != NULL) {
        Nodo *actual = arbol;
        while (TRUE) {
            // Insercion del nodo
            if (*actual == NULL) {
                *actual = nuevo_nodo(lexema, id);
                break;
            }
            // Insercion en rama izquierda
            else if (strcmp(lexema, (*actual)->cl.lexema) < 0) {
                actual = &(*actual)->izq;
            }
            // Insercion en rama derecha
            else {
                actual = &(*actual)->der;
            }
        }

        // Balanceo del arbol
        balancear(arbol);
    }
}

// Buscado de lexemas en el árbol
// Devuelve SIN_CODIGO si no se encuentra
int buscar(ArbolAVL arbol, const char *lexema) {
    Nodo actual = arbol;  // Nodo actual
    int aux;              // Variable auxiliar
    while (actual != NULL) {
        // Comparacion de lexemas
        aux = strcmp(lexema, actual->cl.lexema);
        // Lexema encontrado
        if (aux == 0) {
            return actual->cl.id;
        }
        // Buscamos en la rama izquierda
        else if (aux < 0) {
            actual = actual->izq;
        }
        // Buscamos en la rama derecha
        else {
            actual = actual->der;
        }
    }
    return SIN_CODIGO;
}

// Rotación derecha de subarbol
Nodo rotacion_derecha(Nodo y) {
    Nodo x = y->izq;
    Nodo aux = x->der;

    // Rotamos
    x->der = y;
    y->izq = aux;

    // Actualizamos alturas
    y->altura = max(altura(y->izq), altura(y->der)) + 1;
    x->altura = max(altura(x->izq), altura(x->der)) + 1;

    // Devolvemos nueva raiz
    return x;
}

// Rotación izquierda de subarbol
Nodo rotacion_izquierda(Nodo x) {
    Nodo y = x->der;
    Nodo aux = y->izq;

    // Rotamos
    y->izq = x;
    x->der = aux;

    //  Actualizamos alturas
    x->altura = max(altura(x->izq), altura(x->der)) + 1;
    y->altura = max(altura(y->izq), altura(y->der)) + 1;

    // Devolvemos nueva raiz
    return y;
}

// Balanceo del arbol
void balancear(ArbolAVL *arbol) {
    Nodo *actual = arbol;     // Nodo actual
    int bal;                  // Variable auxiliar
    bool balanceado = FALSE;  // Variable de finalizacion
    while (!balanceado) {
        bal = balance_nodo(*actual);
        // Desbalance por el nodo izquierdo
        if (bal > 1) {
            bal = balance_nodo((*actual)->izq);
            // Rotacion RR
            if (bal == 1) {
                *actual = rotacion_derecha(*actual);
                balanceado = TRUE;
            }
            // Rotacion RL
            else if (bal == -1) {
                (*actual)->izq = rotacion_izquierda((*actual)->izq);
                *actual = rotacion_derecha(*actual);
                balanceado = TRUE;
            }
            // Seguimos buscando raiz del desbalanceo
            else {
                actual = &(*actual)->izq;
            }
        }
        // Desbalance por el nodo derecho
        else if (bal < -1) {
            bal = balance_nodo((*actual)->der);
            // Rotacion LL
            if (bal == 1) {
                *actual = rotacion_izquierda(*actual);
                balanceado = TRUE;
            }
            // Rotacion LR
            else if (bal == -1) {
                (*actual)->der = rotacion_derecha((*actual)->der);
                *actual = rotacion_izquierda(*actual);
                balanceado = TRUE;
            }
            // Seguimos buscando raiz del desbalanceo
            else {
                actual = &(*actual)->der;
            }
        }
        // No hay desbalanceo
        else {
            balanceado = TRUE;
        }
    }
}

// Impresion del arbol
void imprimir(ArbolAVL arbol) {
    if (arbol != NULL) {
        imprimir(arbol->izq);
        printf("[ \"%s\", %d ]\n", arbol->cl.lexema, arbol->cl.id);
        imprimir(arbol->der);
    }
}