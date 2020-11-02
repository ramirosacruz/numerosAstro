#include <stdio.h>
#include "./arithmetic.h"
#include "./errorHandling.h"
#include "./utils/general.h"
#include "./numeroAstronomico.h"

/**
 * @author: Ramiro Flores y Nicolas Carson
 * @version: 1.0
 * @see: https://github.com/ramirosacruz/numerosAstro
*/

/**
 * @return Se genera el número astronómico con las banderas al comienzo
 * y posteriormente se colocan los números
 * */
char *generarCadenaDeNumeroAstronomico(char *cadena, int carry, int overflow)
{
    int longitudAbsoluta = longitudDeArreglo(cadena) + 2;
    char *nuevaCadena = (char *)malloc(longitudAbsoluta * sizeof(char));

    nuevaCadena[0] = enteroACaracter(carry);
    nuevaCadena[1] = enteroACaracter(overflow);

    for (int i = 2; i < longitudAbsoluta; i++)
    {
        nuevaCadena[i] = *cadena;
        cadena++;
    }

    return nuevaCadena;
}

/**
 * @return Recibe un número al cual se le elimina las banderas y los ceros
 */
char *obtenerSoloValor(NumeroAstronomico nro)
{
    char *ptr;

    int longitudAbsoluta = nro.longitudError - 2;

    ptr = (char *)malloc(longitudAbsoluta * sizeof(char)); // allocate memory to store 10 characters

    nro.entero += 2;

    for (int i = 0; i < nro.longitudError; i++)
    {
        ptr[i] = *nro.entero;
        nro.entero++;
    }

    return ptr;
}

char *obtenerBanderas(NumeroAstronomico nro)
{
    char *ptr;

    ptr = (char *)malloc(2 * sizeof(char)); // allocate memory to store 10 characters

     for (int i = 0; i < 2; i++)
    {
        ptr[i] = *nro.entero;
        nro.entero++;
    }

    return ptr;
}

NumeroAstronomico crearDesdeCadena(char *cadena)
{
    NumeroAstronomico numeroNuevo;
    numeroNuevo.entero = cadena;
    /* printf("%s \n", numeroNuevo.entero); */
    if (esError(numeroNuevo))
    {
        numeroNuevo.longitudError = getTipoDeError(numeroNuevo);
        printError(numeroNuevo);
        return numeroNuevo;
    }
    numeroNuevo.longitudError = longitudDeArreglo(numeroNuevo.entero);
    numeroNuevo.entero = generarCadenaDeNumeroAstronomico(cadena, 0, 0);

    return numeroNuevo;
}

NumeroAstronomico crearDesdeCifraSeguidaDeCeros(int cifra, int cantCeros)
{
    NumeroAstronomico numeroNuevo;
    char cadenaAux[100];
    char *punt = cadenaAux;
    sprintf(cadenaAux, "%d", cifra);
    int longitud = longitudDeArreglo(cadenaAux) + cantCeros;
    if (longitud >= 100)
    {
        numeroNuevo.longitudError = OVER_FLOW;
        printError(numeroNuevo);
        return numeroNuevo;
    }

    while (*punt != '\0')
        punt++;

    for (int i = 0; i < cantCeros; i++)
    {
        *punt = '0';
        punt++;
        *punt = '\0';
    }
    numeroNuevo.entero = cadenaAux;
    numeroNuevo.longitudError = longitud;
    return numeroNuevo;
}

NumeroAstronomico crearAleatorio(){
    srand(time(NULL));
    int longitud = (rand() % 100) + 1;
    char *cadenaAux = (char *)malloc(longitud * sizeof(char));
    char *punt = cadenaAux;
    for(int i=0; i < longitud; i++)
    {
        *punt = enteroACaracter(rand() % 10);
        punt++;
        *punt = '\0';
    }
    NumeroAstronomico numeroNuevo;
    numeroNuevo.entero = generarCadenaDeNumeroAstronomico(cadenaAux, 0, 0);
    numeroNuevo.longitudError = longitud;
    return numeroNuevo;
}
 