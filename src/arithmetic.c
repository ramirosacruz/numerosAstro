
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
 *@return A partir de dos NAs se fija si estos son iguales y devuelve TRUE(1) si lo son o FALSE(0) si no
 * Además se determina el valor de verdad si primerNro y segundoNro si:
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

    int longitudAbsoluta = max(primerNro.longitudError, segundoNro.longitudError) ;

    char *sumaEntero;

    sumaEntero = (char *)malloc((longitudAbsoluta + 1) * sizeof(char));

    primerNro.entero += primerNro.longitudError + 1;
    segundoNro.entero += segundoNro.longitudError + 1;
    
    sumaEntero[longitudAbsoluta + 1] = '\0'; 
    int nuevaLongitud = 0;
    int carry = 0;
    for (int i = longitudAbsoluta; i >= 0; i--)
    {
          int suma = caracterAEntero(*primerNro.entero) + caracterAEntero(*segundoNro.entero);
        
        if (suma + carry >= 10)
        {
            sumaEntero[i] = enteroACaracter(suma - 10 + carry);
            carry = 1;
        }
        else
        {
            
            sumaEntero[i] = enteroACaracter(suma + carry);
            carry = 0;
             
        }  
        
        --primerNro.entero;
        --segundoNro.entero;

        printf("&//////////\nLETRA 2 = %c   \nI = %d \n|||", *primerNro.entero, i);
        printf("&//////////\nLETRA 1= %c   \nI = %d \n|||", *segundoNro.entero, i);

    }

    char* nuevaCadena = generarCadenaDeNumeroAstronomico(sumaEntero, 0, 0);
    printf(" HHHH\nresulado = %s  |", nuevaCadena);

    NumeroAstronomico nuevoNa;
    nuevoNa.entero = nuevaCadena;
    nuevoNa.longitudError = longitudDeArreglo(nuevaCadena) - 2;
    return nuevoNa;
}