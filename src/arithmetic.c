
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
            //Ignora las banderas
            primerNro.entero += 2;
            segundoNro.entero += 2;
            while (*primerNro.entero != '\0')
            {
                if (*primerNro.entero < *segundoNro.entero)
                    return TRUE;
                primerNro.entero++;
                segundoNro.entero++;
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

/**
 * @return recibe dos números y realiza suma digito a digito utilizando banderas
*/
NumeroAstronomico sumar(NumeroAstronomico primerNro, NumeroAstronomico segundoNro)
{
    char *sumaEntero = crearCadenaPorCaracter(100, '0');

    //Ignoramos las banderas
    primerNro.entero += 99;
    segundoNro.entero += 99;

    int longitud = (primerNro.longitudError > segundoNro.longitudError) ? segundoNro.longitudError : primerNro.longitudError;

    for (int i = 99; i > 2; i--)
    {
        int suma = caracterAEntero(*primerNro.entero) + caracterAEntero(*segundoNro.entero);

        if (suma >= 10)
        {
            //carry
            sumaEntero[0] = '1';
            sumaEntero[i] = enteroACaracter(suma - 10);
        }
        else
        {
            sumaEntero[0] = '0';
            sumaEntero[i] = enteroACaracter(suma + caracterAEntero(sumaEntero[0]));
        }
        primerNro.entero--;
        segundoNro.entero--;
    }
    NumeroAstronomico nuevoNa;
    nuevoNa.entero = sumaEntero;
    nuevoNa.longitudError = longitud;
    return nuevoNa;
}