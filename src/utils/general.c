#include <stdio.h>

char enteroACaracter(int numero){
    return numero + '0';
}

int caracterAEntero(char caracter){
    int x = caracter + 0;
    return x - 48;
}//Esta funcion te devuelve el ASCII del caracter menos 48 asi que si pones letras o simbolos tambien te va a devolver un numero tenelo en cuenta.

int longitudDeArreglo(const char* cadena){
    int longitud = 0;
    while (cadena[longitud] != 0) {
    longitud++;
    }
    return longitud;
}
