#ifndef _ARITHMETIC
#define _ARITHMETIC

typedef struct {
    const char* entero;
    int longitudError;
} NumeroAstronomico;

int esMenor(NumeroAstronomico primerNro, NumeroAstronomico segundoNro);

int sonIguales(NumeroAstronomico primerNro, NumeroAstronomico segundoNro);

#include "arithmetic.c"
#endif