#include <stdio.h>
#include "../utils/general.h"
#include <assert.h>
#include "../arithmetic.h"
#include "../numeroAstronomico.h"
#include "../astroFile.h"

void test_scanNA();
void test_printNA();
void test_writeNA_readNA();

int main()
{
    printf("\n --- 🧪 TEST ASTROFILE 🧪 --- \n");
    printf("\n 🔃 Cargando Test... \n");
    // test_scanNA();
    test_printNA();
    test_writeNA_readNA();

    printf("\n ✅ Todos los test corrieron  \n");
}
void test_writeNA_readNA()
{
    FILE *flujo1 = fopen("FlujoNABin.na", "w+");
    NumeroAstronomico nro1 = crearDesdeCadena("61223");
    writeNA(nro1, flujo1);
    fclose(flujo1);
    FILE *flujo2 = fopen("FlujoNABin.na", "rb");
    NumeroAstronomico nro2 = readNA(flujo2);
    assert(*nro1.entero == *nro2.entero);
    assert(nro1.longitudError == nro2.longitudError);
    fclose(flujo2);
}

void test_scanNA()
{
    FILE *flujo = fopen("FlujoNABinario.txt", "r");
    NumeroAstronomico a = scanNA(flujo);
    assert('0' == *a.entero);
    a.entero++;
    assert('0' == *a.entero);
    a.entero++;
    assert('1' == *a.entero);
    a.entero++;
    assert('2' == *a.entero);
    a.entero++;
    assert('3' == *a.entero);
    FILE *flujoError = fopen("FlujoConErrorBinario.txt", "r");
    NumeroAstronomico b = scanNA(flujoError);
    assert(-2 == b.longitudError);
}

void test_printNA()
{
    FILE *flujo1 = fopen("FlujoNATexto.txt", "w+");
    NumeroAstronomico nro1 = crearDesdeCadena("623");
    printNA(nro1, flujo1);
    fclose(flujo1);

    FILE *flujo2 = fopen("FlujoNATexto.txt", "r");

    NumeroAstronomico nro2 = scanNA(flujo2);
    assert(*nro1.entero == *nro2.entero);
    assert(nro1.longitudError == nro2.longitudError);
}