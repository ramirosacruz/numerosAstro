/*Operaciones de Manejo de Errores
4. EsSecuenciaNula : NumeroAstronomico → Boolean
5. EsSecuenciaInvalida : NumeroAstronomico → Boolean
6. EsOverflow : NumeroAstronomico → Boolean
7. EsPunteroNulo. Esta operación es propia de la implementación.
8. GetTipoDeError : NumeroAstronomico → TipoDeError
TipoDeError = {Ninguno, CadenaNula, CadenaInvalida, Overflow(, PunteroNulo)}
TipoDeError se implementa como un enum. PunteroNulo es propia de la implementación.
9. EsError : NumeroAstronomico → Boolean
Esta operación equivale a: EsCadenaNula ∨ EsCadenaInvalida ∨ EsOverflow
*/
#include <stdio.h>
#include <stdlib.h>
#include "./errorHandling.h"

int esSecuenciaNula(NumeroAstronomico nro){
    if(longitudDeArreglo(nro.entero))
        return TRUE;
    else
        return FALSE;  
}

int esOverFlow(NumeroAstronomico nro){
    if(longitudDeArreglo(nro.entero) <= 100)
        return FALSE;
    else
        return TRUE;  
}

int esSecuenciaInvalida(NumeroAstronomico nro){
    while(*nro.entero != '\0'){
        int entero;
        entero = caracterAEntero(*nro.entero);
        if (entero < 0 || entero > 9)
            return TRUE;
        *nro.entero++;
    }
    return FALSE;
}

int esError(NumeroAstronomico nro){
    int error1 = esSecuenciaNula(nro);
    int error2 = esSecuenciaInvalida(nro);
    int error3 = esOverFlow(nro);
    if(error1 + error2 + error3)
        return TRUE;
    else
        return FALSE; 
}

int getTipoDeError(NumeroAstronomico nro){
    if(esSecuenciaNula(nro))
        return SECUENCIA_NULA;
    if(esOverFlow(nro)){
        if(esSecuenciaInvalida(nro))
            return DOBLE_ERROR;
        else
            return OVER_FLOW;
    }
    if(esSecuenciaInvalida(nro))
        return SECUENCIA_INVALIDA;
    return FALSE;
}
 
void printError(NumeroAstronomico numero){
    switch (numero.longitudError)
    {
    case -1:
        printf("Error: El Numero ingresado es nulo \n");
        break;
    
    case -2:
        printf("Error: El Numero ingresado tiene caracteres invalidos \n");
        break;
    
    case -3:
        printf("Error: El Numero ingresado supera lo 100 digitos \n");
        break;
    
    case -4:
        printf("Error: El Numero ingresado tiene caracteres invalidos y supera los 100 digitos \n");
        break;
    }
}