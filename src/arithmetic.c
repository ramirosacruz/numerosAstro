
/*
11. Sumar : NumeroAstronomico × NumeroAstronomico → NumeroAstronomico
12. SonIguales : NumeroAstronomico × NumeroAstronomico → Boolean
13. EsMenor : NumeroAstronomico × NumeroAstronomico → Boolean
*/
#include <stdio.h>
#include <stdlib.h>
#include <general.h>

int esMenor(NumeroAstronomico primerNro, NumeroAstronomico segundoNro){
    if(primerNro.longitudError < segundoNro.longitudError)
        return true;
    else{
        if(primerNro.longitudError == segundoNro.longitudError){
            if(*primerNro.entero < *segundoNro.entero)
                return true;    
        } 
        return false;    
    }
}

int sonIguales(NumeroAstronomico primerNro, NumeroAstronomico segundoNro){
    if(primerNro.longitudError != segundoNro.longitudError)
        return false;
    else{
        while(*primerNro.entero != '\0'){
            if(*primerNro.entero != *segundoNro.entero)
                return false;
            *primerNro.entero ++;
            *segundoNro.entero ++;
        }
        return true;
    }
}
