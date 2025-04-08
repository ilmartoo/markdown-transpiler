#ifndef __ANALIZADOR_LEXICO_H__
#define __ANALIZADOR_LEXICO_H__

#include "componente_lexico.h"
#include "definiciones.h"
#include "boolean.h"

/**
 * Inicializacion del analizador lexico
 */
void inicializacion_analizador_lexico();

/**
 * Analizador lexico implementado por flex segun el archivo flex .l
 * @return Id del componente lexico econtrado
 */
int yylex();

/**
 * Lectura de un fichero por el sistema de entrada
 * @param path Ruta al archivo
 * @return Booleano que indica si se ha encontrado el archivo
 */
bool load_file(const char *path);

/**
 * Introduce el último fichero cargado en el sistema de entrada
 */
void read_file();

/**
 * Cierra el archivo a leer actualmente por el sistema de entrada
 * @return Devuelve un boolean indicando si la entrada despues de cerrar el archivo
 * es stdin. TRUE si es stdin. FALSE en caso contrario.
 */
bool close_file();

/**
 * Finalizacion del analizador lexico
 */
void cerrado_analizador_lexico();

#endif  //__ANALIZADOR_LEXICO_H__
