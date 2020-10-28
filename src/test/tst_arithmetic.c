#include <stdio.h>
#include "../utils/general.h"
#include <assert.h>
#include "../arithmetic.h"
#include "../numeroAstronomico.h"

void test_sumar();
void test_esMenor();
void test_sonIguales();

int main()
{
    test_esMenor();
    test_sumar();
    test_sonIguales();
}

void test_sonIguales()
{
    NumeroAstronomico a = crearDesdeCadena("200");
    printf("NUMERO %s y longitud de %d", a.entero, a.longitudError);

    NumeroAstronomico b = crearDesdeCadena("200");

    assert(sonIguales(a, b));

    NumeroAstronomico c = crearDesdeCadena("200");

    NumeroAstronomico d = crearDesdeCadena("201");

    assert(!sonIguales(c, d));
}

void test_esMenor()
{
    NumeroAstronomico a = crearDesdeCadena("200");
    NumeroAstronomico b = crearDesdeCadena("201");
    assert(esMenor(a, b));

    NumeroAstronomico c = crearDesdeCadena("203");
    NumeroAstronomico d = crearDesdeCadena("202");

    assert(!esMenor(c, d));
}

void test_sumar()
{
    /*  NumeroAstronomico miNumero;
    miNumero.entero = "120";
    miNumero.longitudError = 10;

    NumeroAstronomico miNumeroDos;
    miNumeroDos.entero = "820";
    miNumeroDos.longitudError = 10;
    *miNumero.entero+=2;
         
    printf("->es %c \n", *miNumero.entero);
    assert(miNumero.entero == "10"); */
}
