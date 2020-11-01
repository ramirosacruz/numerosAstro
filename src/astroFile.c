#include <stdio.h>
#include <stdlib.h>
#include "./numeroAstronomico.h"

void show(NumeroAstronomico nro)
{
  char *valorOriginal = obtenerSoloValor(nro);
  char *valorBanderas = obtenerBanderas(nro);
  printf("--------------------------------- \n VALOR CON FORMATO: %s|%s  \n VALOR ORIGINAL: %s \n LONGITUD: %d \n ---------------------------------- \n", valorBanderas, valorOriginal, valorOriginal, nro.longitudError);
}

NumeroAstronomico read(FILE *flujo);

FILE *write(NumeroAstronomico nroAstronomico, FILE *flujo);

NumeroAstronomico scan(FILE *flujo);

FILE *print(NumeroAstronomico nroAstronomico, FILE *flujo);