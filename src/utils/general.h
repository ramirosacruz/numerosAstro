#ifndef _GENERAL
#define _GENERAL

#define TRUE 1
#define FALSE 0

char enteroACaracter(int numero);

int caracterAEntero(char caracter);

int longitudDeArreglo(const char *puntero);

char *crearCadenaPorCaracter(int longitud, const char caracter);

#include "general.c"
#endif