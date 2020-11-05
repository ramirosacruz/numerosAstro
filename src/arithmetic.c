
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
 * @return se evalua si primerNro es menor al segundoNro y devuelve TRUE(1) si lo es o FALSE(0) si no
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

/**
 *@return A partir de dos NAs se fija si estos son iguales y devuelve TRUE(1) si lo son o FALSE(0) si no
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

    int longitudAbsoluta = max(primerNro.longitudError, segundoNro.longitudError);

    if (primerNro.longitudError == segundoNro.longitudError)
        if (enteroACaracter(primerNro.entero[3]) + enteroACaracter(primerNro.entero[3]) >= 10)
            longitudAbsoluta++;

    char *sumaEntero;
    sumaEntero = (char *)malloc((longitudAbsoluta + 2) * sizeof(char));
    sumaEntero[0] = '0';
    sumaEntero[1] = '0';

    primerNro.entero += primerNro.longitudError + 1;
    segundoNro.entero += segundoNro.longitudError + 1;

    for (int i = longitudAbsoluta - 1 + 2; i >= 2; i--)
    {
        int suma = caracterAEntero(*primerNro.entero) + caracterAEntero(*segundoNro.entero);

        int carry = caracterAEntero(sumaEntero[0]);

        if (suma >= 10)
        {
            sumaEntero[i] = enteroACaracter(suma - 10 + carry);
            sumaEntero[0] = '1';
        }
        else
        {
            sumaEntero[i] = enteroACaracter(suma + carry);
            sumaEntero[0] = '0';
        }
        --primerNro.entero;
        --segundoNro.entero;
    }

    NumeroAstronomico nuevoNa;
    nuevoNa.entero = sumaEntero;
    nuevoNa.longitudError = longitudAbsoluta;
    return nuevoNa;
}