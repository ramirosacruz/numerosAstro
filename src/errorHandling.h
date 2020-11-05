#include "./numeroAstronomico.h"
#ifndef _ERRORHANDLING
#define _ERRORHANDLING

#define SECUENCIA_NULA -1
#define SECUENCIA_INVALIDA -2
#define OVER_FLOW -3
#define DOBLE_ERROR -4

int esSecuenciaNula(NumeroAstronomico nro);

int esOverFlow(NumeroAstronomico nro);

int esSecuenciaInvalida(NumeroAstronomico nro);

int esError(NumeroAstronomico nro);

int getTipoDeError(NumeroAstronomico nro);
 
void printError(NumeroAstronomico numero);

#include "errorHandling.c"
#endif
