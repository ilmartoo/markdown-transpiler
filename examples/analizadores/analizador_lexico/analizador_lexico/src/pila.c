#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "boolean.h"

/* PILA LIFO */
struct struct_NodoPila {
    char elemento;
    struct struct_NodoPila *next;
};
#define Nodo Pila

// Inicializacion de la pila
void nueva_pila(Pila *p) {
    if (p != NULL) {
        *p = NULL;
    }
}

// Elimina elemento de la pila
char pop(Pila *p) {
    if (p != NULL && *p != NULL) {
        // Eliminacion de primer nodo
        Nodo primero = *p;
        *p = (*p)->next;
        // Guardado del elemento
        char elem = primero->elemento;
        // Liberacion de memoria
        free(primero);

        return elem;
    }
    return 0;
}

// Introduce elemento en la pila
void push(Pila *p, char elem) {
    if (p != NULL && *p != NULL) {
        Nodo viejo = *p;  // Antiguo primer nodo
        // Inicializamos nuevo nodo
        Nodo nuevo = (Nodo)malloc(sizeof(struct struct_NodoPila));
        nuevo->elemento = elem;
        // Introducimos nuevo nodo de primero
        *p = nuevo;
        nuevo->next = viejo;
    }
}

// Devolvemos el primer elemento de la pila
char peek(Pila p) {
    return p == NULL ? 0 : p->elemento;
}

// Boolean para comprobar si la pila está vacía
bool es_vacia(Pila p) {
    return p == NULL;
}

// Borrado de la pila
void borrado_pila(Pila *p) {
    if (p != NULL) {
        Nodo actual = *p;  // Empezamos con el puntero al primer nodo
        while (actual != NULL) {
            // Actualizacion del primer nodo
            *p = actual->next;
            // Liberacion de memoria del nodo
            free(actual);
            // Actualizacion del nodo a borrar
            actual = *p;
        }
    }
}