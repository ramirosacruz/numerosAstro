#ifndef _ARITHMETIC
#define _ARITHMETIC


#define true 1
#define false 0

typedef struct {
    const char* entero;
    int longitudError;
} NumeroAstronomico;

char caracterAEntero(int numero);

int longitudDeArreglo(char caracter);

int esMenor(const char* puntero);

int sonIguales(NumeroAstronomico primerNro, NumeroAstronomico segundoNro);

#include "arithmetic.c"
#endif