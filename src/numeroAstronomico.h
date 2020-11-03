#ifndef _NUMEROASTRONOMICO
#define _NUMEROASTRONOMICO

typedef struct
{
    const char *entero;
    int longitudError;
} NumeroAstronomico;

char *generarCadenaDeNumeroAstronomico(char *cadena, int carry, int overflow);

char *obtenerSoloValor(NumeroAstronomico nro);

NumeroAstronomico crearDesdeCadena(char *cadena);

NumeroAstronomico crearDesdeCifraSeguidaDeCeros(int cifra, int cantCeros);

NumeroAstronomico crearAleatorio();

#include "numeroAstronomico.c"
#endif