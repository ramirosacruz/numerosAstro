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

FILE *mostrar(NumeroAstronomico nro, int grupoEnPrimerLinea,FILE *flujo);

const char* mostrarLinea(FILE *flujo,const char *ptr,int longitud);

#include "numeroAstronomico.c"
#endif