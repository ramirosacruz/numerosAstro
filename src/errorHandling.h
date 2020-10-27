#include "./numeroAstronomico.h"
#ifndef _ERRORHANDLING
#define _ERRORHANDLING
 
int esSecuenciaNula(NumeroAstronomico nro);

int esOverFlow(NumeroAstronomico nro);

int esSecuenciaInvalida(NumeroAstronomico nro);

int esError(NumeroAstronomico nro);

int getTipoDeError(NumeroAstronomico nro);
 
void printError(NumeroAstronomico numero);

#include "errorHandling.c"
#endif
