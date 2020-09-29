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
#include <general.h>

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
    if(longitudDeArreglo(nro.entero))
        return true;
    else
        return false;  
}

int esOverFlow(NumeroAstronomico nro){
    if(longitudDeArreglo(nro.entero) <= 100)
        return false;
    else
        return true;  
}

int esSecuenciaInvalida(NumeroAstronomico nro){
    while(*nro.entero != '\0'){
        int entero;
        entero = caracterAEntero(*nro.entero);
        if (entero < 0 || entero > 9)
            return true;
        *nro.entero++;
    }
    return false;
}

int esError(NumeroAstronomico nro){
    int error1 = esSecuenciaNula(nro);
    int error2 = esSecuenciaInvalida(nro);
    int error3 = esOverFlow(nro);
    if(error1 + error2 + error3)
        return true;
    else
        return false; 
}

int main(){
    
    return 0;
}