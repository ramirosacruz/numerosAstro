#include <stdio.h>
#include "./arithmetic.h"
#include "./errorHandling.h"
#include "./utils/general.h"
#include "./numeroAstronomico.h"

/**
 * @author: Ramiro Flores y Nicolas Carson
 * @version: 1.0
 * @see: https://github.com/ramirosacruz/numerosAstro
*/

/**
 * @return Se genera el número astronómico con las banderas al comienzo
 * y posteriormente se colocan los números
 * */
char *generarCadenaDeNumeroAstronomico(char *cadena, int carry, int overflow)
{
    int longitudAbsoluta = longitudDeArreglo(cadena) + 2;
    char *nuevaCadena = (char *)malloc(longitudAbsoluta * sizeof(char));

    nuevaCadena[0] = enteroACaracter(carry);
    nuevaCadena[1] = enteroACaracter(overflow);

    for (int i = 2; i < longitudAbsoluta; i++)
    {
        nuevaCadena[i] = *cadena;
        cadena++;
    }

    return nuevaCadena;
}

/**
 * @return Recibe un número al cual se le elimina las banderas y los ceros
 */
char *obtenerSoloValor(NumeroAstronomico nro)
{
    char *ptr;

    int longitudAbsoluta = nro.longitudError - 2;

    ptr = (char *)malloc(longitudAbsoluta * sizeof(char)); // allocate memory to store 10 characters

    nro.entero += 2;

    for (int i = 0; i < nro.longitudError; i++)
    {
        ptr[i] = *nro.entero;
        nro.entero++;
    }

    return ptr;
}

/**
 *@return Recibe un NA y devuelve sus banderas
 */
char *obtenerBanderas(NumeroAstronomico nro)
{
    char *ptr;

    ptr = (char *)malloc(2 * sizeof(char)); // allocate memory to store 10 characters

    for (int i = 0; i < 2; i++)
    {
        ptr[i] = *nro.entero;
        nro.entero++;
    }

    return ptr;
}

/**
 * @return Recibe una cadena de caracteres y si es valida genera un NA con el contenido de esta
 * */
NumeroAstronomico crearDesdeCadena(char *cadena)
{
    NumeroAstronomico numeroNuevo;
    numeroNuevo.entero = cadena;
    /* printf("%s \n", numeroNuevo.entero); */
    if (esError(numeroNuevo))
    {
        numeroNuevo.longitudError = getTipoDeError(numeroNuevo);
        printError(numeroNuevo);
        return numeroNuevo;
    }
    numeroNuevo.longitudError = longitudDeArreglo(numeroNuevo.entero);
    numeroNuevo.entero = generarCadenaDeNumeroAstronomico(cadena, 0, 0);

    return numeroNuevo;
}

/**
 * @return Apartir de una cifra y una cantidad genera un NA al cual se le pone la cifra dada por delante y seguida de esta viene una serie de ceros dada por la cantidad
 * */
NumeroAstronomico crearDesdeCifraSeguidaDeCeros(int cifra, int cantCeros)
{
    NumeroAstronomico numeroNuevo;
    char *cadenaAux = (char *)malloc(sizeof(cifra) + sizeof(char) * cantCeros);
    char *punt = cadenaAux;
    sprintf(cadenaAux, "%d", cifra);
    int longitud = longitudDeArreglo(cadenaAux) + cantCeros;
    if (longitud > 100)
    {
        numeroNuevo.longitudError = OVER_FLOW;
        printError(numeroNuevo);
        return numeroNuevo;
    }

    while (*punt != '\0')
        punt++;

    for (int i = 0; i < cantCeros; i++)
    {
        *punt = '0';
        punt++;
        *punt = '\0';
    }
    numeroNuevo.entero = generarCadenaDeNumeroAstronomico(cadenaAux, 0, 0);
    numeroNuevo.longitudError = longitud;
    return numeroNuevo;
}

/**
 * @return Genera un NA aleatorio tanto es su longitud(100 como maximo) como en su contenido
 * */
NumeroAstronomico crearAleatorio()
{
    srand(time(NULL));
    int longitud = (rand() % 100) + 1;
    char *cadenaAux = (char *)malloc(longitud * sizeof(char));
    char *punt = cadenaAux;
    do
    {
        *punt = enteroACaracter(rand() % 10);
    } while (!*punt);
    punt++;
    for (int i = 0; i < longitud - 1; i++)
    {
        *punt = enteroACaracter(rand() % 10);
        punt++;
        *punt = '\0';
    }
    NumeroAstronomico numeroNuevo;
    numeroNuevo.entero = generarCadenaDeNumeroAstronomico(cadenaAux, 0, 0);
    numeroNuevo.longitudError = longitud;
    return numeroNuevo;
}

/**
 * @return Recibe un numero, una cantidad de grupos en la primer linea  y un flujo igualado a stdout por lo que apunta a la pantalla de la consola. Su funcion es mostrar el numero en consola de forma tal que aparecen en la primer linea la cantidad dada de grupos de 3 numeros (salvo el primero que puede ser de 3, 2 o 1) separados por un punto, en las siguientes lineas se muestran una cantidad de 1 menos que la primera de grupos por linea (siempre que la longitud lo permita), y termina con una linea con la cantidad de grupos sobrantes si estos existiesen. 
 * */
FILE *mostrar(NumeroAstronomico nro, int grupoEnPrimerLinea, FILE *flujo)
{
    nro.entero += 2;
    int modulo = nro.longitudError % 3;
    if (!modulo)
        modulo = 3;
    int longitudPrimerLinea = (grupoEnPrimerLinea - 1) * 3 + modulo;
    if (longitudPrimerLinea > nro.longitudError || (grupoEnPrimerLinea == 1 && nro.longitudError > 3))
    {
        printf("Error: Grupo/s en primera linea exceden la longitud del numero o es igual a 1. \n");
        return flujo;
    }
    nro.entero = mostrarLinea(flujo, nro.entero, longitudPrimerLinea);
    int gruposSobrantes = (nro.longitudError - longitudPrimerLinea) / 3;
    if (!gruposSobrantes)
    {
        fputc('\n', flujo);
        return flujo;
    }
    fputc('.', flujo);
    fputc('\n', flujo);
    modulo = gruposSobrantes % (grupoEnPrimerLinea - 1);
    int lineasSobrantes = (gruposSobrantes - modulo) / (grupoEnPrimerLinea - 1);
    for (int i = 0; i < lineasSobrantes; i++)
    {
        nro.entero = mostrarLinea(flujo, nro.entero, (grupoEnPrimerLinea - 1) * 3);
        if (i == lineasSobrantes - 1 && !modulo)
        {
            fputc('\n', flujo);
            return flujo;
        }
        fputc('.', flujo);
        fputc('\n', flujo);
    }
    nro.entero = mostrarLinea(flujo, nro.entero, modulo * 3);
    fputc('\n', flujo);
    return flujo;
}

/**
 * @return Recibe un flujo igualado a stdout, un puntero a char y una longitud, y muestra una linea la cantidad de numeros dada por la longitud comenzando por donde apunte el puntero, estos estan separados por un punto en grupos de 3 (salvo el primero que puede ser 3, 2 o 1)
 * */
const char *mostrarLinea(FILE *flujo, const char *ptr, int longitud)
{
    int modulo = longitud % 3;
    if (!modulo)
        modulo = 3;
    int aux = 3 - modulo;
    longitud = longitud + aux;
    fputc('\t', flujo);
    fputc('\t', flujo);
    for (int i = aux; i < longitud; i++)
    {
        fputc(*ptr, flujo);
        ptr++;
        if ((i % 3) == 2 && i != longitud - 1)
            fputc('.', flujo);
    }
    return ptr;
}
