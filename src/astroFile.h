#include "./numeroAstronomico.h"

#ifndef _ASTROFILE
#define _ASTROFILE

void show(NumeroAstronomico nro);

NumeroAstronomico readNA(FILE *flujo);

void writeNA(NumeroAstronomico nroAstronomico, FILE *flujo);

NumeroAstronomico scanNA(FILE *flujo);

void printNA(NumeroAstronomico nro, FILE *flujo);

#include "astroFile.c"
#endif
