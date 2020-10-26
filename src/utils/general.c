#include "general.h"

char enteroACaracter(int numero){
    return numero + '0';
}

int caracterAEntero(char caracter){
    int x = caracter + 0;
    return x - 48;
}//Esta funcion te devuelve el ASCII del caracter menos 48 asi que si pones letras o simbolos tambien te va a devolver un numero tenelo en cuenta.

int longitudDeArreglo(const char* puntero){
    int longitud = 0;
    while(*puntero != '\0'){
        longitud ++;
        *puntero ++;
    }
    return longitud;
}

void printError(NumeroAstronomico numero){
    switch (getTipoDeError(numero))
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