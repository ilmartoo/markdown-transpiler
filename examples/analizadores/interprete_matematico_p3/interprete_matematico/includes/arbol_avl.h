#ifndef __ARBOL_AVL_H__
#define __ARBOL_AVL_H__

#include "componente_lexico.h"

/* Arbol AVL */
typedef struct struct_NodoAVL *ArbolAVL;

/**
 * Inicializa un árbol AVL
 * @param arbol Árbol AVL a inicializar
 */
void crear_arbol(ArbolAVL *arbol);

/**
 * Borra un árbol AVL
 * @param arbol Árbol AVL a borrar
 */
void borrar_arbol(ArbolAVL *arbol);

/**
 * Inserta un lexema y su id de componente léxico en el árbol
 * @param arbol Árbol AVL a utilizar
 * @param lexema Clave del elemento a insertar
 * @param id Id del componente lexico a insertar
 * @param datos Datos del componente léxico
 * @return Componente lexico del nodo insertado
 */
CompLexico *insertar(ArbolAVL *arbol, const char *lexema, int id, Datos datos);

/**
 * Busca un lexema en el árbol AVL y devuelve el elemento que contiene
 * @param arbol Árbol AVL a utilizar
 * @param lexema Clave del elemento a buscar
 * @return Componente lexico contenido en el nodo encontrado (NULL si no se encuentra)
 */
CompLexico *buscar(ArbolAVL arbol, const char *lexema);

/**
 * Elimina un lexema del árbol AVL
 * @param arbol Árbol AVL a utilizar
 * @param lexema Clave del elemento a eliminar
 */
void eliminar(ArbolAVL *arbol, const char *lexema);

/**
 * Imprime el contenido de un árbol AVL
 * @param arbol Árbol AVL a imprimir
 */
void imprimir(ArbolAVL arbol);

#endif  //__ARBOL_AVL_H__