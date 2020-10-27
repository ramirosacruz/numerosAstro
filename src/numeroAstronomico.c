#include <stdio.h>
#include "./arithmetic.h"
#include "./errorHandling.h"
#include "./utils/general.h"
#include "./numeroAstronomico.h"

NumeroAstronomico crearDesdeCadena(char* cadena){
    NumeroAstronomico numeroNuevo;
    numeroNuevo.entero = cadena;
    if (esError(numeroNuevo)){
        numeroNuevo.longitudError = getTipoDeError(numeroNuevo);
        printError(numeroNuevo);
        return numeroNuevo;
    }
    numeroNuevo.longitudError = longitudDeArreglo(numeroNuevo.entero);
    return numeroNuevo;
}

NumeroAstronomico crearDesdeCifraSeguidaDeCeros(int cifra, int cantCeros){
    NumeroAstronomico numeroNuevo;
    char cadenaAux[100];
    char* punt = cadenaAux;
    sprintf(cadenaAux,"%d",cifra);
    int longitud = longitudDeArreglo(cadenaAux) + cantCeros;
    if (longitud >= 100 ){
        numeroNuevo.longitudError = OVER_FLOW;
        printError(numeroNuevo);
        return numeroNuevo;
    }
    
    while(*punt != '\0')
        punt++;

    for(int i=0; i < cantCeros; i++){
        *punt = '0';
        punt++;
        *punt = '\0';
    }
    numeroNuevo.entero = cadenaAux;
    numeroNuevo.longitudError = longitud;
    return numeroNuevo;
}

NumeroAstronomico crearAleatorio(int proxNroDeSecuenciaRand, int cantCeros);
