#ifndef _ASTROFILE
#define _ASTROFILE

typedef struct {
    const char* entero;
    int longitudError;
} NumeroAstronomico;

int esMenor(NumeroAstronomico primerNro, NumeroAstronomico segundoNro);

int sonIguales(NumeroAstronomico primerNro, NumeroAstronomico segundoNro);

#include "astroFile.c"
#endif