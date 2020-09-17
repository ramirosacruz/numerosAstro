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

typedef struct {
const char* entero;
int longitudError;
} NumeroAstronomico;

int caracterAEntero(char caracter){
    int x = caracter + 0;
    return x - 48;
}

int longitudDeArreglo(const char* puntero){
    int longitud = 0;
    while(*puntero != '\0'){
        longitud ++;
        *puntero ++;
    }
    return longitud;
}
int esSecuenciaNula(NumeroAstronomico nro){
    int bool;
    if(longitudDeArreglo(nro.entero)){
        bool = 0;
        return bool;
    }
    else{
        bool = 1;
        return bool;
    }  
}

int esOverFlow(NumeroAstronomico nro){
    int bool;
    if(longitudDeArreglo(nro.entero) <= 100){
        bool = 0;
        return bool;
    }
    else{
        bool = 1;
        return bool;
    }  
}

int esSecuenciaInvalida(NumeroAstronomico nro){
    int bool = 0;
    while(*nro.entero != '\0'){
        int caracter;
        caracter = caracterAEntero(*nro.entero);
        if (caracter < 0 || caracter > 9){
            bool = 1;
            return bool;
        }
        *nro.entero++;
    }
    return bool;
}

int esError(NumeroAstronomico nro){
    int bool;
    int error1 = esSecuenciaNula(nro);
    int error2 = esSecuenciaInvalida(nro);
    int error3 = esOverFlow(nro);
    if(error1 + error2 + error3){
        bool = 1;
        return bool;
    }
    else{
        bool = 0;
        return bool;
    }  
}

int main(){
    
    return 0;
}