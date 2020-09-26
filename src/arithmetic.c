
/*
11. Sumar : NumeroAstronomico × NumeroAstronomico → NumeroAstronomico
12. SonIguales : NumeroAstronomico × NumeroAstronomico → Boolean
13. EsMenor : NumeroAstronomico × NumeroAstronomico → Boolean
*/
#include <stdio.h>
#include <stdlib.h>

#define VERDADERO 1
#define FALSO 0

typedef struct {
const char* entero;
int longitudError;
} NumeroAstronomico;

int caracterAEntero(char caracter){
    int x = caracter + 0;
    return x - 48;
}

int longitudDeArreglo(const char* puntero){
    int longitud = 0;
    while(*puntero != '\0'){
        longitud ++;
        *puntero ++;
    }
    return longitud;
}

int esMenor(NumeroAstronomico primerNro, NumeroAstronomico segundoNro){
    if(primerNro.longitudError < segundoNro.longitudError)
        return VERDADERO;
    else{
        if(primerNro.longitudError == segundoNro.longitudError){
            if(*primerNro.entero < *segundoNro.entero)
                return VERDADERO;    
        } 
        return FALSO;    
    }
}

int sonIguales(NumeroAstronomico primerNro, NumeroAstronomico segundoNro){
    if(primerNro.longitudError != segundoNro.longitudError)
        return FALSO;
    else{
        while(*primerNro.entero != '\0'){
            if(*primerNro.entero != *segundoNro.entero)
                return FALSO;
            *primerNro.entero ++;
            *segundoNro.entero ++;
        }
        return VERDADERO;
    }
}
