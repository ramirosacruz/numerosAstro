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
#include <arithmetic.h>


int esSecuenciaNula(NumeroAstronomico nro){
    if(longitudDeArreglo(nro.entero))
        return TRUE;
    else
        return FALSE;  
}

int esOverFlow(NumeroAstronomico nro){
    if(longitudDeArreglo(nro.entero) <= 100)
        return FALSE;
    else
        return TRUE;  
}

int esSecuenciaInvalida(NumeroAstronomico nro){
    while(*nro.entero != '\0'){
        int entero;
        entero = caracterAEntero(*nro.entero);
        if (entero < 0 || entero > 9)
            return TRUE;
        *nro.entero++;
    }
    return FALSE;
}

int esError(NumeroAstronomico nro){
    int error1 = esSecuenciaNula(nro);
    int error2 = esSecuenciaInvalida(nro);
    int error3 = esOverFlow(nro);
    if(error1 + error2 + error3)
        return TRUE;
    else
        return FALSE; 
}

int main(){
    
    return 0;
}