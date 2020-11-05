#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @return A partir de un numero de tipo int devuelve ese mismo numero como un caracter
*/
char enteroACaracter(int numero)
{
    return numero + '0';
}

/**
 * @return A partir de un caracter devuelve el valor de este en ASCII menos 48, con este se asegura que cada vez que se le pase un numero como caracter, devuelve el valor entero de ese numero 
*/
int caracterAEntero(char caracter)
{
    int x = caracter + 0;
    return x - 48;
}

/**
 * @return A partir de un arreglo devuelve la longitud de este
 */
int longitudDeArreglo(const char *cadena)
{
    int longitud = 0;
    while (cadena[longitud] != 0)
    {
        longitud++;
    }
    return longitud;
}
/* 
char *crearCadenaPorCaracter(int longitud, const char caracter)
{
    char *ptr;
    ptr = (char *)malloc(longitud * sizeof(char)); // allocate memory to store 10 characters

    for (int i = 0; i < longitud; i++)
        ptr[i] = caracter;

    return ptr;
}
 */