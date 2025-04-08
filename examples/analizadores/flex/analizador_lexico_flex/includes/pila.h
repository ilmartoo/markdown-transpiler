#ifndef __PILA_H__
#define __PILA_H__

#include "boolean.h"

/* Pila (LIFO) */
typedef struct struct_NodoPila *Pila;

/**
 * Inicialización de la pila
 * @param pila Pila a inicializar
 */
void nueva_pila(Pila *p);

/**
 * Borrado de la pila
 * @param pila Pila a eliminar
 */
void borrado_pila(Pila *p);

/**
 * Quita de la pila el primer elemento
 * @param pila Pila a modificar
 * @return Antiguo primer elemento de la pila o '\0' si está vacía
 */
char pop(Pila *p);

/**
 * Introduce un elemento en la pila
 * @param pila Pila a modificar
 * @param c Elemento a introducir en la pila
 */
void push(Pila *p, char c);

/**
 * Muestra el primer elemento de la pila
 * @return Primer elemento de la pila o '\0' si está vacía
 */
char peek(Pila p);

/**
 * Comprobación del vacio de la pila
 * @param pila Pila a revisar
 * @return TRUE si la pila está vacía o FALSE en caso contrario
 */
bool es_vacia(Pila p);

#endif  //__PILA_H__