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
 * Obtencion de un componente lexico del fichero de codigo
 * @param comp_lexico Estructura inicializada. Se modificará el puntero al lexema y el id.
 * @return TRUE si se ha encontrado un nuevo componente lexico. FALSE cuando no hay más componentes
 * lexicos.
 */
bool siguiente_componente_lexico(CompLexico *comp_lexico);

/**
 * Finalizacion del analizador lexico
 */
void cerrado_analizador_lexico();

#endif  //__ANALIZADOR_LEXICO_H__
