#ifndef _GENERAL
#define _GENERAL

#define TRUE 1
#define FALSE 0
#define SECUENCIA_NULA -1
#define SECUENCIA_INVALIDA -2
#define OVER_FLOW -3
#define DOBLE_ERROR -4

char enteroACaracter(int numero);

int caracterAEntero(char caracter);

int longitudDeArreglo(const char* puntero);

#include "general.c"
#endif