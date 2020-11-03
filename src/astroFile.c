#include <stdio.h>
#include <stdlib.h>
#include "./numeroAstronomico.h"

void show(NumeroAstronomico nro)
{
  char *valorOriginal = obtenerSoloValor(nro);
  char *valorBanderas = obtenerBanderas(nro);
  printf("--------------------------------- \n VALOR CON FORMATO: %s|%s|  \n VALOR ORIGINAL: %s \n LONGITUD: %d \n ---------------------------------- \n", valorBanderas, valorOriginal, nro.entero, nro.longitudError);
}

NumeroAstronomico readNA(FILE *flujo)
{
  NumeroAstronomico buff;

  fread(&buff, sizeof(NumeroAstronomico), 1, flujo);
  printf(">>>>>>>>>>>> >>>>>>>>%saa", buff.entero);

  return buff;
}

void writeNA(NumeroAstronomico nroAstronomico, FILE *flujo)
{
  printf(">>>>>>>>>>>> >>>>>>>>%ld", sizeof(NumeroAstronomico));
  fwrite(&nroAstronomico, sizeof(NumeroAstronomico), 1, flujo);
  return;
}

NumeroAstronomico scanNA(FILE *flujo)
{
  char *cadenaAux = (char *)malloc(sizeof(flujo));
  char *punt = cadenaAux;
  do
  {
    *punt = fgetc(flujo);
    punt++;
    *punt = fgetc(flujo);
    ungetc(*punt, flujo);
  } while (*punt != '#');
  *punt = '\0';
  NumeroAstronomico numeroNuevo;
  numeroNuevo.longitudError = longitudDeArreglo(cadenaAux);
  numeroNuevo.entero = generarCadenaDeNumeroAstronomico(cadenaAux, 0, 0);
  if (esError(numeroNuevo))
  {
    numeroNuevo.longitudError = getTipoDeError(numeroNuevo);
    printError(numeroNuevo);
  }
  fclose(flujo);
  return numeroNuevo;
}

void printNA(NumeroAstronomico nro, FILE *flujo)
{
  nro.entero += 2;
  fprintf(flujo, "%s#", nro.entero);
}