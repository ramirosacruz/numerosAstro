#include <stdio.h>
#include "../utils/general.h"
#include <assert.h>
#include "../arithmetic.h"
#include "../numeroAstronomico.h"
void test_enteroACaracter();
void test_scanFlujoDeTexto();
int main()
{
    printf("\n --- 🧪 TEST GENERAL 🧪 --- \n");
    printf("\n 🔃 Cargando Test... \n");
    //test_enteroACaracter();
    test_scanFlujoDeTexto();
    printf("\n ✅ Todos los test corrieron  \n");
    system("PAUSE");
}
void test_scanFlujoDeTexto(){
    FILE *flujo = fopen("FlujoNA.txt","r");
    NumeroAstronomico a = scanFlujoDeTexto(flujo);
    assert('0' == *a.entero);
    a.entero++;
    assert('0'== *a.entero);
    a.entero++;
    assert('1' == *a.entero);
    a.entero++;
    assert('2'== *a.entero);
    a.entero++;
    assert('3'== *a.entero);
    FILE *flujoError = fopen("FlujoConError.txt","r");
    NumeroAstronomico b = scanFlujoDeTexto(flujoError);
    assert(-2 == b.longitudError);
}

void test_enteroACaracter()
{
    char a = enteroACaracter(11);
    assert(a == ';');
}
