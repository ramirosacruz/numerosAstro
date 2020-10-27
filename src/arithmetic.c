
/*
11. Sumar : NumeroAstronomico × NumeroAstronomico → NumeroAstronomico
12. SonIguales : NumeroAstronomico × NumeroAstronomico → Boolean
13. EsMenor : NumeroAstronomico × NumeroAstronomico → Boolean
*/
#include <stdio.h>
#include <stdlib.h>
#include "./utils/general.h"
#include "./arithmetic.h"
#include "./numeroAstronomico.h"

/**
 * @return se evalua si primerNro es menor al segundoNro
*/
int esMenor(NumeroAstronomico primerNro, NumeroAstronomico segundoNro)
{
    if (primerNro.longitudError < segundoNro.longitudError)
        return TRUE;
    else
    {
        if (primerNro.longitudError == segundoNro.longitudError)
        {
            while (*primerNro.entero != '\0')
            {
                if (*primerNro.entero < *segundoNro.entero)
                    return TRUE;
                primerNro.entero++;
                segundoNro.entero++;
                printf("%c", *segundoNro.entero);
            }
        }
        return FALSE;
    }
}

/**
 * @return se determina el valor de verdad si primerNro y segundoNro si:
 *  1) tienen igualdad en cuanto longitud
 *  2) si los dígitos coinciden
*/
int sonIguales(NumeroAstronomico primerNro, NumeroAstronomico segundoNro)
{
    if (primerNro.longitudError != segundoNro.longitudError)
        return FALSE;
    else
    {
        while (*primerNro.entero != '\0')
        {
            if (*primerNro.entero != *segundoNro.entero)
                return FALSE;
            primerNro.entero++;
            segundoNro.entero++;
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