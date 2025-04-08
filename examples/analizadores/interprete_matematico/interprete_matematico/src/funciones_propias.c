#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include "analizador_lexico.h"
#include "tabla_simbolos.h"
#include "funciones_propias.h"
#include "componente_lexico.h"
#include "boolean.h"

/* Precision en la impresión de resultados */
#define OUTPUT_PRECISION 10

/* Estructuras de la sesión y lista de variables */
// Nodo de la lista de variables de la sesión
struct VarList {
    CompLexico *cl;       /* Componente léxico */
    struct VarList *next; /* Siguiente componente léxico */
};
// Nodo de la lista de librerias de la sesión
struct LibList {
    char *name;           /* Nombre de la libreria */
    void *handler;        /* Handler de la libreria */
    struct LibList *next; /* Siguiente librería */
};
// Estructura de la sesión
struct Session {
    bool echo_active;         /* Booleano de impresion de resultados */
    struct VarList *var_list; /* Lista de variables y constantes de la sesión */
    struct VarList *tmp_list; /* Lista temporal de variables y constantes del comando ejecutado */
    struct LibList *lib_list; /* Lista de librerias importadas */
    struct VarList *fnc_list; /* Lista de funciones de las librerias incluidas */
};

/* Almacenamiento de la sesión */
struct Session session = {
    .echo_active = TRUE, .var_list = NULL, .tmp_list = NULL, .lib_list = NULL, .fnc_list = NULL};

// Impresión de prompt
void print_prompt() {
    printf(" >> ");
}

// Impresion de resultados eliminando los 0 a la derecha en la parte decimal
void print_output(double result) {
    // Impresión de resultados
    if (session.echo_active) {
        printf(" %.*g\n", OUTPUT_PRECISION, result);
    }
}

// Comunica al analizador si debe imprimir el resultado
void echo(bool do_print) {
    session.echo_active = do_print;
    // Feedback al usuario
    if (do_print) {
        printf(" \x1b[1;36mOutput de resultados activado\x1b[0m\n");
    } else {
        printf(" \x1b[1;36mOutput de resultados desactivado\x1b[0m\n");
    }
}

// Imprime un valor por pantalla
void print(double value) {
    printf(" %.*g\n", OUTPUT_PRECISION, value);
}

// Imprime la ayuda del interprete
void help() {
    printf(" \x1b[1;36mInformación detallada sobre el funcionamiento del intérprete de\n"
           " matemático.\n\n"
           " Las intrucciones se componen de comandos, funciones y operaciones\n"
           " que se pueden intercalar a lo largo de la ejecución. Estas a su\n"
           " vez se componen de datos, los cuales tienen asignado un tipo y\n"
           " este determina que se puede hacer con ellos.\n\n"
           " \x1b[1;32mTipos de datos:\x1b[1;36m\n\n"
           "\tnumérico\tUn número entero, decimal o en notación\n"
           "\t\t\tcientífica.\n\n"
           "\tvariable\tNombre al que se le pueden asignar valores\n"
           "\t\t\tpara su posterior uso. Puede ser redefinida.\n\n"
           "\tconstante\tNombre que no puede contener letras minúsculas\n"
           "\t\t\tque actua como una variable, pero solo puede\n"
           "\t\t\tser definida una vez, manteniendo su valor\n"
           "\t\t\tinalterable a lo largo de la ejecución.\n"
           "\t\t\tEl inteprete tiene un conjunto de constantes\n"
           "\t\t\tya definidas (Ver apartado \x1b[1;32mConstantes\x1b[1;36m).\n\n"
           "\tcomando\t\tNombre de una función propia del interprete\n"
           "\t\t\tque puede ser invocado mediante el formato\n"
           "\t\t\tcomando(arg) siendo arg el argumento\n"
           "\t\t\tnecesario o ninguno si no necesita. (Ver\n"
           "\t\t\tapartado \x1b[1;32mComandos\x1b[1;36m).\n\n"
           "\tfunción\t\tNombre de una función que puede ser invocada\n"
           "\t\t\tmediante el formato función(arg) siendo arg \n"
           "\t\t\tuna expresión (Ver apartado \x1b[1;32mFormato de las\n"
           "\t\t\tinstrucciones\x1b[1;36m) (Ver apartado \x1b[1;32mFunciones\x1b[1;36m).\n\n"
           " \x1b[1;32mFormato de las intrucciones:\x1b[1;36m\n\n"
           "\tA op B\t\tEXPRESIÓN.\n"
           "\t\t\tA y B son númericos, variables, constantes o\n"
           "\t\t\tfunciones.\n"
           "\t\t\top es un operador (Ver apartado \x1b[1;32mOperadores\x1b[1;36m).\n"
           "\t\t\tRealiza la operación correspondiente entre\n"
           "\t\t\tA y B. Los operadores tienen un orden de\n"
           "\t\t\tprecedencia establecido, pero puede alterarse\n"
           "\t\t\tinsertando la expresión dentro de paréntesis\n"
           "\t\t\t(A op B) haciendo que sea prioritaria.\n"
           "\t\t\tLos paréntesis también permiten insertar\n"
           "\t\t\tasignaciones con o sin operación, siendo\n"
           "\t\t\tposible darse expresiones (A = B) o (A op= B).\n\n"
           "\tA = B\t\tASIGNACIÓN.\n"
           "\t\t\tA es una variable, definida o a definir, o \n"
           "\t\t\tuna constante necesariamente no definida.\n"
           "\t\t\tB es una expresión.\n"
           "\t\t\t= es el operador =.\n"
           "\t\t\tAsigna el valor de la expresión a A.\n\n"
           "\tC\t\tCOMANDO.\n"
           "\t\t\tC es un comando del interprete (Ver apartado\n"
           "\t\t\t\x1b[1;32mComandos\x1b[1;36m).\n"
           "\t\t\tEjecuta un comando del intérprete.\n\n"
           "\tA op= B\t\tASIGNACIÓN CON OPERACIÓN.\n"
           "\t\t\tA es una variable necesariamente definida.\n"
           "\t\t\tB es una expresión.\n"
           "\t\t\top= se compone de dos caracteres, un operador\n"
           "\t\t\t(Ver apartado \x1b[1;32mOperadores\x1b[1;36m) y el caracter '='.\n"
           "\t\t\tEsta instrucción es equivalente a realizar\n"
           "\t\t\tA = A op B.\n\n"
           " Las instrucciones se procesan de línea en línea, tratando cada una\n"
           " como un conjunto. Cada línea puede contener varias instrucciones \n"
           " separandolas entre ';'. Si se produce algún error al procesar la \n"
           " línea, se interrumpe y se reestablece el estado del al de antes de\n"
           " comenzar el procesado de la línea, descartándola en el proceso.\n\n"
           " Una instrucción puede estar vacía, es decir, no contener ningún\n"
           " caracter excepto el salto de línea o contener instrucciones vacías.\n"
           " En estos casos la línea se descarta sin mayor acción requerida.\n"
           " Debido a esto, las siguientes líneas son perfectamente válidas: \n"
           "   >> ;;;;;;;;\\n\n"
           "   >> \\n\n"
           " Nota: Los símbolos <\\n> representan los saltos de línea.\n\n"
           " Se puede salir del interprete introduciendo un caracter de fin\n"
           " de fichero <EOF> (Ctrl + D). Se cuenta también con una función\n"
           " específica para salir del interprete (Ver apartado \x1b[1;32mComandos\x1b[1;36m).\n\n"
           " \x1b[1;32mOperadores:\x1b[1;36m\n\n"
           "\t=\t\tOperador de asignación. Prioridad 0.\n\n"
           "\t+\t\tOperador de suma. Prioridad 1.\n\n"
           "\t-\t\tOperador de resta. Prioridad 1. También puede ser \n"
           "\t\t\tusado junto a un numérico para convertirlo en negativo,\n"
           "\t\t\tcambiando su prioridad a 3 en este caso.\n\n"
           "\t*\t\tOperador de multiplicación. Prioridad 2.\n\n"
           "\t/\t\tOperador de división. Prioridad 2.\n\n"
           "\t%%\t\tOperador de módulo. Prioridad 2.\n\n"
           "\t^\t\tOperador de exponenciación. Prioridad 4.\n\n"
           " \x1b[1;32mComandos:\x1b[1;36m\n\n"
           "\thelp()\t\tMuestra la ayuda del interprete.\n\n"
           "\techo(num)\tActiva o desactiva la impresión de resultados.\n"
           "\t\t\tRecibe un booleano o un número, actuando \n"
           "\t\t\tnum = 0 como FALSE y num > 0 como TRUE.\n\n"
           "\tprint(exp)\tImprime el resultado de una expresión.\n\n"
           "\tload(\"path\")\tLee un fichero de instrucciones, actuando como\n"
           "\t\t\tun conjunto. Si se detecta algún fallo dentro\n"
           "\t\t\tdel fichero al leer los comandos, se volverá\n"
           "\t\t\tal último estado antes de ejecutarlo. En el\n"
           "\t\t\tcaso de llamar a la función en una línea con\n"
           "\t\t\tmúltiples comandos, la ejecución del archivo\n"
           "\t\t\tse llevará a cabo al terminar la ejecución del\n"
           "\t\t\tresto de instrucciones de la línea.\n\n"
           "\timport(\"path\")\tImporta una librería de funciones matemáticas.\n"
           "\t\t\tTodas las funciones contenidas deben de\n"
           "\t\t\trecibir un double como parámetro y devolver\n"
           "\t\t\tun double <double fnc (double d)>. Cualquier\n"
           "\t\t\tfunción presente en la librería que no siga el\n"
           "\t\t\tformato especificado tendrá un funcionamiento\n"
           "\t\t\tindefinido en el ámbito del interprete.\n\n"
           "\tworkspace()\tMuestra las variables y constantes definidas\n"
           "\t\t\tpor el usuario y las librerías importadas hasta el\n"
           "\t\t\tmomento.\n\n"
           "\tclean(var)\tElimina la variable o constante pasada como\n"
           "\t\t\targumento. Necesariamente debe haber sido\n"
           "\t\t\tdefinida por el usuario y no borrada con\n"
           "\t\t\tanterioridad.\n\n"
           "\tcleanall()\tElimina todas las variables y constantes\n"
           "\t\t\tdefinidas por el usuario y librerías importadas\n"
           "\t\t\tdesde el inicio del interprete o desde la última\n"
           "\t\t\tinvocación del comando.\n\n"
           "\texit()\t\tFinaliza la ejecución del interprete.\n\n"
           " \x1b[1;32mFunciones:\x1b[1;36m\n\n"
           "\tcos\t\tCalcula el coseno de un ángulo en radianes.\n\n"
           "\tacos\t\tCalcula el arcocoseno de un ángulo en radianes.\n\n"
           "\tcosh\t\tCalcula el coseno hiperbólico de un ángulo en\n"
           "\t\t\tradianes.\n\n"
           "\tsin\t\tCalcula el seno de un ángulo en radianes.\n\n"
           "\tasin\t\tCalcula el arcoseno de un ángulo en radianes.\n\n"
           "\tsinh\t\tCalcula el seno hiperbólico de un ángulo en\n"
           "\t\t\tradianes.\n\n"
           "\tatan\t\tCalcula la arcotangente de un ángulo en radianes.\n\n"
           "\ttanh\t\tCalcula la tangente hiperbólica de un ángulo en\n"
           "\t\t\tradianes.\n\n"
           "\tlog\t\tCalcula el logaritmo en base e de un número.\n\n"
           "\tlog10\t\tCalcula el logaritmo en base 10 de un número.\n\n"
           "\tceil\t\tCalcula el siguiente entero a un número si\n"
           "\t\t\tcuenta con parte decimal o devuelve el mismo \n"
           "\t\t\tnúmero si no tiene.\n\n"
           "\tfloor\t\tObtiene la parte entera de un número.\n\n"
           " \x1b[1;32mConstantes:\x1b[1;36m\n\n"
           "\tPI\t\tRepresenta el número pi.\n\n"
           "\tE\t\tRepresenta el número e.\n\n"
           "\tTRUE\t\tRepresenta el valor 1. Puede usarse como\n"
           "\t\t\targumento para las funciones como un valor\n"
           "\t\t\tnumérico.\n\n"
           "\tFALSE\t\tRepresenta el valor 0. Puede usarse como\n"
           "\t\t\targumento para las funciones como un valor\n"
           "\t\t\tnumérico.\n"
           "\x1b[0m");
}

// Carga un fichero de instrucciones
bool load(const char *path) {
    if (load_file(path)) {
        // Feedback
        printf(" \x1b[1;36mFichero %s cargado\x1b[0m\n", path);
        return TRUE;
    }
    return FALSE;
}

// Imprime nombre y valor de las variables y constantes
// de la sesión definidas por el usuario, librerias
// importadas y funciones de librerias utilizadas
void workspace() {
    /* Librerías */
    printf("\x1b[1;36m LIBS: [\x1b[0m");

    if (session.lib_list != NULL) {
        struct LibList *lib = session.lib_list;

        // Impresión de la primera librería
        printf(" %s", lib->name);
        /* Pasamos al siguiente componente */
        lib = lib->next;

        // Impresión del resto de librerías
        while (lib != NULL) {
            /* Imprimimos datos del componente */
            printf("\x1b[1;36m,\x1b[0m %s", lib->name);
            /* Pasamos al siguiente componente */
            lib = lib->next;
        }
    }

    /* Variables y constantes */
    printf("\x1b[1;36m ]\n WORKSPACE: [\x1b[0m");

    if (session.var_list != NULL) {
        printf("\n");

        struct VarList *elem = session.var_list;

        // Impresión del primer elemento
        printf("   %s = %.*g", elem->cl->lexema, OUTPUT_PRECISION, elem->cl->datos.di.valor);
        /* Pasamos al siguiente componente */
        elem = elem->next;

        // Impresión del resto de elementos
        while (elem != NULL) {
            /* Imprimimos datos del componente */
            printf("\x1b[1;36m,\x1b[0m\n   %s = %.*g", elem->cl->lexema, OUTPUT_PRECISION,
                   elem->cl->datos.di.valor);
            /* Pasamos al siguiente componente */
            elem = elem->next;
        }

        printf("\n");
    }

    printf(" \x1b[1;36m]\n\x1b[0m");
}

// Incluye dinamicamente una libreria de funciones matemáticas
bool import(const char *libreria) {
    /* Comprobamos si la librería ya está añadida */
    if (dlopen(libreria, RTLD_LAZY | RTLD_NOLOAD) != NULL) {
        return TRUE;  // Librería ya añadida
    }

    /* Cargamos libreria */
    void *handler = NULL;
    if ((handler = dlopen(libreria, RTLD_NOW | RTLD_GLOBAL | RTLD_DEEPBIND)) == NULL) {
        return FALSE;
    }

    /* Incluimos la librería en la lista */
    struct LibList *nuevo = (struct LibList *)malloc(sizeof(struct LibList));
    nuevo->name = strdup(libreria);
    nuevo->handler = handler;
    nuevo->next = session.lib_list;
    // La añadimos a la lista
    session.lib_list = nuevo;

    printf(" \x1b[1;36mLibrería %s importada.\x1b[0m\n", nuevo->name);
    return TRUE;
}

// Elimina la variable o constante de la sesión,
// teniendo que haber sido definida por el usuario con anterioridad
bool clean_var(const char *variable) {
    struct VarList **elem = &session.var_list;
    while (*elem != NULL) {
        // Borramos la variable
        if (strcmp((*elem)->cl->lexema, variable) == 0) {
            struct VarList *aux = (*elem)->next;

            // Feedback
            printf(" \x1b[1;36mVariable del usuario %s eliminada de la sesión\x1b[0m\n",
                   (*elem)->cl->lexema);

            // Borramos variable
            quitar_tabla_simbolos((*elem)->cl->lexema);
            free(*elem);

            *elem = aux;
            // Confirmamos la eliminación
            return TRUE;
        }
        // Seguimos buscando
        else {
            elem = &(*elem)->next;
        }
    }
    // No se ha encontrado la variable
    return FALSE;
}

// Elimina las variables o constantes de la sesión,
// teniendo que haber sido definidas por el usuario con anterioridad
void clean_all() {
    // Eliminación de variables
    struct VarList *elem = session.var_list;
    struct VarList *aux;
    while (elem != NULL) {
        aux = elem->next;

        // Borramos elemento
        quitar_tabla_simbolos(elem->cl->lexema);
        free(elem);

        // Pasamos al siguiente
        elem = aux;
    }
    // Ponemos la lista a NULL para indicar que no hay elementos
    session.var_list = NULL;

    // Eliminación de librerias
    struct LibList *lib_elem = session.lib_list;
    struct LibList *lib_aux;
    while (lib_elem != NULL) {
        lib_aux = lib_elem->next;

        // Cerramos libreria y borramos
        dlclose(lib_elem->handler);
        free(lib_elem->name);
        free(lib_elem);

        // Pasamos al siguiente
        lib_elem = lib_aux;
    }

    // Feedback
    printf(" \x1b[1;36mLibrerias y variables del usuario eliminadas de la sesión\x1b[0m\n");
}

// Añade una variable a la sesión
void add_to_sesion(CompLexico *cl) {
    // Reservamos memoria e inicializamos
    struct VarList *nuevo = (struct VarList *)malloc(sizeof(struct VarList));
    nuevo->cl = cl;
    nuevo->next = session.tmp_list;
    // La añadimos a la lista
    session.tmp_list = nuevo;
}

// Añade la referencia a una funcion importada
void add_fnc(CompLexico *fnc) {
    // Reservamos memoria e inicializamos
    struct VarList *nuevo = (struct VarList *)malloc(sizeof(struct VarList));
    nuevo->cl = fnc;
    nuevo->next = session.fnc_list;
    // La añadimos a la lista
    session.tmp_list = nuevo;
}

// Busca una funcion en las librerias importadas
double *lookup_fnc(const char *fnc) {
    double *fnc_ptr = NULL;
    // Buscamos puntero a función.
    // Al cargar las librerias con RTLD_GLOBAL
    // nos permite buscar en el orden:
    //    1- programa actual
    //    2- librerías estáticas
    //    3- librerías dinámicas con RTLD_GLOBAL
    // con una llamada a dlsym(RTLD_DEFAULT, ...)
    fnc_ptr = dlsym(RTLD_DEFAULT, fnc);
    // Devolvemos resultado
    return fnc_ptr;
}

// Confirma el guardado de las variables en la lista temporal
void commit_variables() {
    struct VarList **aux = &session.tmp_list;
    // Enlazamos final de la lista de variables temporales
    // al principio de la de confirmadas
    while (*aux != NULL) {
        aux = &(*aux)->next;
    }
    (*aux) = session.var_list;
    // Asignamos lista completa tmp_list + var_list a la lista var_list
    session.var_list = session.tmp_list;
    session.tmp_list = NULL;  // Borramos lista temporal
}

// Elimina las variables de la lista temporal
void rollback_variables() {
    struct VarList *aux, *elem = session.tmp_list;
    while (elem != NULL) {
        aux = elem->next;

        // Borramos elemento
        quitar_tabla_simbolos(elem->cl->lexema);
        free(elem);

        // Pasamos al siguiente
        elem = aux;
    }
    // Ponemos la lista a NULL para indicar que no hay elementos
    session.tmp_list = NULL;
}

// Comunica la finalización del interprete
void print_exit() {
    // Comunicamos finalización
    printf(" \x1b[1;32mFinalizando el interprete...\x1b[0m\n");
}

// Liberación de memoria de las funciones propias
void finalizacion_funciones() {
    struct VarList *aux, *elem = session.var_list;
    // Liberación de memoria de la lista de variables guardadas
    while (elem != NULL) {
        aux = elem->next;
        // Liberamos elemento
        free(elem);
        // Pasamos al siguiente
        elem = aux;
    }

    // Liberación de memoria de la lista de variables temporales
    elem = session.tmp_list;
    while (elem != NULL) {
        aux = elem->next;
        // Liberamos elemento
        free(elem);
        // Pasamos al siguiente
        elem = aux;
    }

    // Liberación de memoria de la lista de funciones
    elem = session.fnc_list;
    while (elem != NULL) {
        aux = elem->next;
        // Liberamos elemento
        free(elem);
        // Pasamos al siguiente
        elem = aux;
    }

    // Liberación de memoria y cerrado de librerias incluidas
    struct LibList *lib_aux, *lib_elem = session.lib_list;
    while (elem != NULL) {
        lib_aux = lib_elem->next;
        // Cerramos libreria
        dlclose(lib_elem->handler);
        // Liberamos elemento
        free(lib_elem->name);
        free(lib_elem);
        // Pasamos al siguiente
        lib_elem = lib_aux;
    }
}