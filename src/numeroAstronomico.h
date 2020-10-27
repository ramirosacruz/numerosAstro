#ifndef _NUMEROASTRONOMICO
#define _NUMEROASTRONOMICO

typedef struct {
    const char* entero;
    int longitudError;
} NumeroAstronomico;

NumeroAstronomico crearDesdeCadena(char* cadena);

NumeroAstronomico crearDesdeCifraSeguidaDeCeros(int cifra, int cantCeros);

NumeroAstronomico crearAleatorio(int proxNroDeSecuenciaRand, int cantCeros);

#include "numeroAstronomico.c"
#endif