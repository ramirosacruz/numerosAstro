#ifndef _NUMEROASTRONOMICO
#define _NUMEROASTRONOMICO

typedef struct
{
    const char *entero;
    int longitudError;
} NumeroAstronomico;

NumeroAstronomico crearDesdeCadena(char *cadena);

NumeroAstronomico crearDesdeCifraSeguidaDeCeros(int cifra, int cantCeros);

NumeroAstronomico crearAleatorio(int proxNroDeSecuenciaRand, int cantCeros);

char *generarCadenaDeNumeroAstronomico(char *cadena, int carry, int overflow);

#include "numeroAstronomico.c"
#endif