#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol_avl.h"
#include "boolean.h"
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

// Borrado de un nodo
void eliminar_nodo(Nodo *nodo) {
    // En el caso de los operadores (char *)
    // nos aseguramos al insertar que valor apunta
    // al mismo sitio que lexema, asegurandonos que no
    // quedan datos sin liberar
    free((*nodo)->cl.lexema);
    free(*nodo);
    *nodo = NULL;
}

// Borrado recursivo del árbol
void borrar_arbol(ArbolAVL *arbol) {
    if (arbol != NULL && *arbol != NULL) {
        // Borrado de rama izquierda
        borrar_arbol(&(*arbol)->izq);
        // Borrado de rama derecha
        borrar_arbol(&(*arbol)->der);
        // Liberacion de memoria de nodo actual
        eliminar_nodo(arbol);
    }
}

// Obtencion de la altura del arbol con raiz en el nodo
int altura(Nodo nodo) {
    return nodo == NULL ? 0 : nodo->altura;
}

// Recalculo de la altura de un nodo
int recalcular_altura(Nodo nodo) {
    return max(altura(nodo->izq), altura(nodo->der)) + 1;
}

// Factor de balance para un nodo
int balance_nodo(Nodo nodo) {
    return nodo == NULL ? 0 : altura(nodo->izq) - altura(nodo->der);
}

// Creación de nuevo nodo
Nodo nuevo_nodo(const char *lexema, int id, Datos datos) {
    // Reservamos memoria
    Nodo nuevo = (Nodo)malloc(sizeof(struct struct_NodoAVL));
    // Inicializamos valores
    nuevo->altura = 1;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    // Establecemos componente léxico
    nuevo->cl.lexema = strdup(lexema);
    nuevo->cl.id = id;
    nuevo->cl.datos = datos;

    return nuevo;
}

// Balanceo de un nodo del arbol
void balancear_nodo(ArbolAVL *arbol);

// Inserción de lexemas e ids en el árbol
CompLexico *insertar(ArbolAVL *arbol, const char *lexema, int id, Datos datos) {
    if (arbol != NULL) {
        // Insercion del nodo
        if (*arbol == NULL) {
            // Devolucion del Componente Lexico
            return &(*arbol = nuevo_nodo(lexema, id, datos))->cl;
        }
        // Inserción en hijos
        int aux = strcmp(lexema, (*arbol)->cl.lexema);
        if (aux != 0) {
            CompLexico *cl = NULL;
            // Insercion en rama izquierda
            if (aux < 0) {
                cl = insertar(&(*arbol)->izq, lexema, id, datos);
            }
            // Insercion en rama derecha
            else {
                cl = insertar(&(*arbol)->der, lexema, id, datos);
            }
            // Recalculo de la altura
            (*arbol)->altura = recalcular_altura(*arbol);
            // Balanceo
            balancear_nodo(arbol);
            // Devolucion del Componente Lexico
            return cl;
        }
        // Clave duplicada
        else {
            return NULL;
        }
    }
    return NULL;
}

// Busqueda recursiva de un nodo mediante lexema
Nodo buscar_nodo(ArbolAVL arbol, const char *lexema) {
    // No se encuentra el lexema
    if (arbol == NULL) {
        return NULL;
    }

    // Buscamos el lexema
    int aux = strcmp(lexema, arbol->cl.lexema);
    if (aux == 0) {
        return arbol;
    }
    // Buscamos en la rama izquierda
    else if (aux < 0) {
        return buscar_nodo(arbol->izq, lexema);
    }
    // Buscamos en la rama derecha
    else {
        return buscar_nodo(arbol->der, lexema);
    }
}

// Buscado de lexemas en el árbol
CompLexico *buscar(ArbolAVL arbol, const char *lexema) {
    return &buscar_nodo(arbol, lexema)->cl;
}

// ELiminado de lexemas en el árbol
void eliminar(ArbolAVL *nodo, const char *lexema) {
    // Valor no existente
    if (nodo == NULL || *nodo == NULL) {
        return;
    }

    // Buscamos el lexema
    int aux = strcmp(lexema, (*nodo)->cl.lexema);
    if (aux == 0) {
        // Nodo hoja o nodo con un hijo
        // Hijo izquierdo o derecho nulo
        if ((*nodo)->der == NULL || (*nodo)->izq == NULL) {
            // Guardamos hijo
            Nodo hijo = (*nodo)->izq ? (*nodo)->izq : (*nodo)->der;
            // Borramos
            eliminar_nodo(nodo);
            // Asignamos hijo (puede ser un nulo si no tiene hijo)
            *nodo = hijo;
        }
        // Nodo con dos hijos
        else {
            // Obtenemos nodo hoja a reemplazar
            Nodo *hijo = &(*nodo)->der;
            while ((*hijo)->izq != NULL) {
                hijo = &(*hijo)->izq;
            }

            // Reemplazamos nodo más a la izquierda por su hijo derecho
            Nodo sust = *hijo;
            *hijo = (*hijo)->der;

            // Reemplazamos nodo a eliminar por el sustituto encontrado
            Nodo aux = *nodo;
            *nodo = sust;
            (*nodo)->izq = aux->izq;
            (*nodo)->der = aux->der;

            // Eliminamos nodo
            eliminar_nodo(&aux);
        }

    }
    // Buscamos en la rama izquierda
    else if (aux < 0) {
        eliminar(&(*nodo)->izq, lexema);
    }
    // Buscamos en la rama derecha
    else {
        eliminar(&(*nodo)->der, lexema);
    }

    // Balanceamos si el arbol tiene más de un nodo
    if (*nodo != NULL) {
        balancear_nodo(nodo);
    }
}

// Rotación derecha de subarbol
Nodo rotacion_derecha(Nodo y) {
    Nodo x = y->izq;
    Nodo aux = x->der;

    // Rotamos
    x->der = y;
    y->izq = aux;

    // Actualizamos alturas
    y->altura = recalcular_altura(y);
    x->altura = recalcular_altura(x);

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
    x->altura = recalcular_altura(x);
    y->altura = recalcular_altura(y);

    // Devolvemos nueva raiz
    return y;
}

// Balanceo de un nodo del arbol
void balancear_nodo(ArbolAVL *nodo) {
    // Balanceamos solo si el subarbol es suficientemente alto
    if (altura(*nodo) > 2) {
        int bal = balance_nodo(*nodo);
        // Desbalance por el nodo izquierdo
        if (bal > 1) {
            bal = balance_nodo((*nodo)->izq);
            // // Rotacion LL
            if (bal >= 0) {
                *nodo = rotacion_derecha(*nodo);
            }
            // Rotacion LR
            else if (bal < 0) {
                (*nodo)->izq = rotacion_izquierda((*nodo)->izq);
                *nodo = rotacion_derecha(*nodo);
            }
        }
        // Desbalance por el nodo derecho
        else if (bal < -1) {
            bal = balance_nodo((*nodo)->der);
            // Rotacion RR
            if (bal <= 0) {
                *nodo = rotacion_izquierda(*nodo);
            }
            // Rotacion RL
            else if (bal > 0) {
                (*nodo)->der = rotacion_derecha((*nodo)->der);
                *nodo = rotacion_izquierda(*nodo);
            }
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
