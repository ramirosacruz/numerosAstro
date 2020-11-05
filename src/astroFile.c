#include <stdio.h>
#include <stdlib.h>
#include "./numeroAstronomico.h"

/**
 * @return No devuelve nada pero muestra por pantalla el número astronómico de manera legible
 * */
void show(NumeroAstronomico nro)
{
  char *valorOriginal = obtenerSoloValor(nro);
  char *valorBanderas = obtenerBanderas(nro);
  nro.entero += 2;
  printf("--------------------------------- \n VALOR CON FORMATO: %s|%s|  \n VALOR ORIGINAL: %s \n LONGITUD: %d \n ---------------------------------- \n", valorBanderas, valorOriginal, nro.entero, nro.longitudError);
}

/**
 * @return Genera un NA apartir de un puntero a un archivo, este debe contener el registro de un NA
 * */
NumeroAstronomico readNA(FILE *flujo)
{
  NumeroAstronomico buff;

  fread(&buff, sizeof(NumeroAstronomico), 1, flujo);

  return buff;
}

/**
 * @return A partir de un NA y un puntero a un archivo, escribe el NA en un archivo binario
 * */
void writeNA(NumeroAstronomico nroAstronomico, FILE *flujo)
{
  fwrite(&nroAstronomico, sizeof(NumeroAstronomico), 1, flujo);
  return;
}

/**
 * @return Genera un NA apartir de un puntero a un archivo, este debe contener el nuevo numero con el formato: secuenciadedigitos#
 * */
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
  return numeroNuevo;
}

/**
 * @return A partir de un NA y un puntero a un archivo, escribe el NA dado en el archivo apuntado con el formato: secuenciadedigitos#
 * */
void printNA(NumeroAstronomico nro, FILE *flujo)
{
  nro.entero += 2;
  fprintf(flujo, "%s#", nro.entero);
}