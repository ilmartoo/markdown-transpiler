#ifndef __ARBOL_AVL_H__
#define __ARBOL_AVL_H__

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
 * @param lexema String a insertar
 * @param id Id de componente lexico a insertar
 */
void insertar(ArbolAVL *arbol, const char *lexema, int id);

/**
 * Busca un lexema en el árbol AVL y devuelve el identificador de componente léxico
 * asociado o SIN_CODIGO en caso de no encontrarlo
 * @param arbol Árbol AVL a utilizar
 * @param lexema String a buscar
 */
int buscar(ArbolAVL arbol, const char *lexema);

/**
 * Imprime el contenido de un árbol AVL
 * @param arbol Árbol AVL a imprimir
 */
void imprimir(ArbolAVL arbol);

#endif  //__ARBOL_AVL_H__