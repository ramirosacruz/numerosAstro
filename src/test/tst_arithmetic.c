#include <stdio.h>
#include "../utils/general.h"
#include "../arithmetic.h"
#include "../numeroAstronomico.h"
#include "../astroFile.h"
#include <assert.h>

void test_sumar();
void test_esMenor();
void test_sonIguales();

int main()
{
    printf("\n --- 🧪  TEST ARITHMETICS 🧪 --- \n");
    printf("\n 🔃 Cargando Test... \n");

    test_esMenor();
    test_sumar();
    test_sonIguales();
    printf("\n ✅ Todos los test corrieron  \n");
}

void test_sonIguales()
{
    NumeroAstronomico a = crearDesdeCadena("200");

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
    NumeroAstronomico a = crearDesdeCadena("953");
    NumeroAstronomico b = crearDesdeCadena("362");

    NumeroAstronomico suma_ab = crearDesdeCadena("1315");

    assert(sonIguales(sumar(a, b), suma_ab));

    NumeroAstronomico c = crearDesdeCadena("203");
    NumeroAstronomico d = crearDesdeCadena("402");

    NumeroAstronomico suma_cd = crearDesdeCadena("405");

    assert(!sonIguales(sumar(c, d), suma_cd));

    NumeroAstronomico e = crearDesdeCadena("1");
    NumeroAstronomico f = crearDesdeCadena("1");

    NumeroAstronomico suma_ef = crearDesdeCadena("2");

    assert(!sonIguales(sumar(e, f), suma_ef));

    NumeroAstronomico g = crearDesdeCadena("9999999");
    NumeroAstronomico h = crearDesdeCadena("9999999");

    NumeroAstronomico suma_gh = crearDesdeCadena("19999999");

    assert(!sonIguales(sumar(g, h), suma_gh));
}
