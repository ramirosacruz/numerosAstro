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
    int diferencia = 100 - longitudDeArreglo(cadena);
    char *nuevaCadena = crearCadenaPorCaracter(diferencia, '0');

    nuevaCadena[0] = enteroACaracter(carry);
    nuevaCadena[1] = enteroACaracter(overflow);

    for (int i = diferencia; i < 100; i++)
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
    ptr = (char *)malloc(nro.longitudError * sizeof(char)); // allocate memory to store 10 characters

    nro.entero += 100 - nro.longitudError;

    for (int i = 0; i < nro.longitudError; i++)
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

NumeroAstronomico crearAleatorio(int proxNroDeSecuenciaRand, int cantCeros);
