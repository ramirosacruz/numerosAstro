#include "./numeroAstronomico.h"

#ifndef _ASTROFILE
#define _ASTROFILE

void show(NumeroAstronomico nro);

NumeroAstronomico read(FILE *flujo);
FILE *write(NumeroAstronomico nroAstronomico, FILE *flujo);

NumeroAstronomico scan(FILE *flujo);
FILE *print(NumeroAstronomico nroAstronomico, FILE *flujo);

#include "astroFile.c"
#endif
