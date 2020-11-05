#ifndef _GENERAL
#define _GENERAL

#define TRUE 1
#define FALSE 0
#define max(a, b) \
  ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
char enteroACaracter(int numero);

int caracterAEntero(char caracter);

int longitudDeArreglo(const char *puntero);

/* char *crearCadenaPorCaracter(int longitud, const char caracter);
 */
#include "general.c"
#endif