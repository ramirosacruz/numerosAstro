#include <stdio.h>
#include <arithmetic.h>
#include <general.h>

NumeroAstronomico crearDesdeCadena(char* cadena){
    NumeroAstronomico numeroNuevo;
    numeroNuevo.entero = cadena;
    if (esError(numeroNuevo)){
        printError(numeroNuevo);
        numeroNuevo.longitudError = getTipoDeError(numeroNuevo);
        return numeroNuevo;
    }
    numeroNuevo.longitudError = longitudDeArreglo(numeroNuevo.entero);
    return numeroNuevo;
}

NumeroAstronomico crearDesdeCifraSeguidaDeCeros(int cifra, int cantCeros);

NumeroAstronomico crearAleatorio(int proxNroDeSecuenciaRand, int cantCeros);
