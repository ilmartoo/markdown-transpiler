#ifndef __COMPONENTE_LEXICO_H__
#define __COMPONENTE_LEXICO_H__

#include "boolean.h"

/* Datos de un identificador */
typedef struct struct_DatosIdentificador {
    bool inicializado;
    double valor;
} DatosIdentificador;

/* Datos de una funcion propia del interprete */
typedef struct struct_DatosFuncionPropia {
    int tipo;
    void (*fncptr)();
} DatosFuncionPropia;

/* Datos de una funcion matemática de librería */
typedef struct struct_DatosFuncionMath {
    double (*fncptr)(double);
} DatosFuncionMath;

/* Estructura de los datos posibles de un CL */
typedef union union_Datos {
    DatosIdentificador di;   // Datos de identificador
    DatosFuncionPropia dfp;  // Datos de funcion propia
    DatosFuncionMath dfm;    // Datos de funcion de libreria
} Datos;

/* Estructura de Componente Lexico */
typedef struct struct_CompLexico {
    int id;
    char* lexema;
    Datos datos;
} CompLexico;

#endif  //__COMPONENTE_LEXICO_H__