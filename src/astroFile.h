#ifndef _ASTROFILE
#define _ASTROFILE

typedef struct {
    const char* entero;
    int longitudError;
} NumeroAstronomico;

NumeroAstronomico read(FILE* flujo);
FILE* write(NumeroAstronomico nroAstronomico,FILE* flujo);

NumeroAstronomico scan(FILE* flujo);
FILE* print(NumeroAstronomico nroAstronomico,FILE* flujo);

#include "astroFile.c"
#endif
