
/*
11. Sumar : NumeroAstronomico × NumeroAstronomico → NumeroAstronomico
12. SonIguales : NumeroAstronomico × NumeroAstronomico → Boolean
13. EsMenor : NumeroAstronomico × NumeroAstronomico → Boolean
*/
#include <stdio.h>
#include <stdlib.h>
#include "./utils/general.h"
#include "arithmetic.h"


int esMenor(NumeroAstronomico primerNro, NumeroAstronomico segundoNro){
    if(primerNro.longitudError < segundoNro.longitudError)
        return TRUE;
    else{
        if(primerNro.longitudError == segundoNro.longitudError){
            if(*primerNro.entero < *segundoNro.entero)
                return TRUE;    
        } 
        return FALSE;    
    }
}

int sonIguales(NumeroAstronomico primerNro, NumeroAstronomico segundoNro){
    if(primerNro.longitudError != segundoNro.longitudError)
        return FALSE;
    else{
        while(*primerNro.entero != '\0'){
            if(*primerNro.entero != *segundoNro.entero)
                return FALSE;
            *primerNro.entero ++;
            *segundoNro.entero ++;
        }
        return TRUE;
    }
}

/* 
NumeroAstronomico sumar(NumeroAstronomico primerNro, NumeroAstronomico segundoNro){
    NumeroAstronomico nuevoNA;
    nuevoNA.entero = "";
    nuevoNA.longitudError = 0;
    while(*primerNro.entero != '\0'){
        *primerNro.entero += segundoNro.entero
        *primerNro.entero ++;
        *segundoNro.entero ++;
    }
    return true;
}
  */