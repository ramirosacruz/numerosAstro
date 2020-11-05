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

/**
 *@return A partir de un NA se fija si este es nulo o existe y devuelve TRUE(1) si existiese o FALSE(0) si no
 */
int esSecuenciaNula(NumeroAstronomico nro)
{
    if (longitudDeArreglo(nro.entero))
        return FALSE;
    else
        return TRUE;
}

/**
 *@return A partir de un NA se fija si este excede la longitud maxima de caracteres(100) y devuelve TRUE(1) si la excede o FALSE(0) si no
 */
int esOverFlow(NumeroAstronomico nro)
{
    if (longitudDeArreglo(nro.entero) <= 102)
        return FALSE;
    else
        return TRUE;
}

/**
 *@return A partir de un NA se fija si este contiene un caracter invalido(cualquiera que no fuese un digito) y devuelve TRUE(1) si lo contiene o FALSE(0) si no
 */
int esSecuenciaInvalida(NumeroAstronomico nro)
{
    int entero;
    while (*nro.entero != '\0')
    {
        entero = caracterAEntero(*nro.entero);
        if (entero < 0 || entero > 9)
            return TRUE;
        nro.entero++;
    }
    return FALSE;
}

/**
 *@return A partir de un NA se fija si este tiene algun tipo de error(secuencia nula, secuencia invalida o overflow) y devuelve TRUE(1) si lo tiene o FALSE(0) si no
 */
int esError(NumeroAstronomico nro)
{
    int error1 = esSecuenciaNula(nro);
    int error2 = esSecuenciaInvalida(nro);
    int error3 = esOverFlow(nro);
    if (error1 + error2 + error3)
        return TRUE;
    else
        return FALSE;
}

/**
 *@return A partir de un NA se fija si este contiene algun error y devuelve SECUENCIA_NULA(-1), SECUENCIA_INVALIDA(-2), OVER_FLOW(-3), DOBLE_ERROR(-4)(este se produce cuando hay tanto secuencia invalida como overflow) o FALSE(0) si no se encontrase error
 */
int getTipoDeError(NumeroAstronomico nro)
{
    if (esSecuenciaNula(nro))
        return SECUENCIA_NULA;
    if (esOverFlow(nro))
    {
        if (esSecuenciaInvalida(nro))
            return DOBLE_ERROR;
        else
            return OVER_FLOW;
    }
    if (esSecuenciaInvalida(nro))
        return SECUENCIA_INVALIDA;
    return FALSE;
}

/**
 *@return A partir de un NA se fija que tipo de error tiene y muestra por pantalla un mensaje de error con el error correspondiente
 */
void printError(NumeroAstronomico numero)
{
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