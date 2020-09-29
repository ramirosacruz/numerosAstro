#ifndef _ARITHMETIC
#define _ARITHMETIC


#define true 1
#define false 0

typedef struct {
    const char* entero;
    int longitudError;
} NumeroAstronomico;

int esMenor(NumeroAstronomico primerNro, NumeroAstronomico segundoNro);

int sonIguales(NumeroAstronomico primerNro, NumeroAstronomico segundoNro);

#include "arithmetic.c"
#endif