#include <stdio.h>
#include "../utils/general.h"
#include <assert.h>
#include "../arithmetic.h"
#include "../numeroAstronomico.h"
#include "../astroFile.h"

void test_sumar();
void test_esMenor();
void test_sonIguales();

int main()
{
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
    NumeroAstronomico nro_uno = crearDesdeCadena("203");
    NumeroAstronomico nro_dos = crearDesdeCadena("202");

    NumeroAstronomico suma_uno = crearDesdeCadena("405");

    assert(sonIguales(sumar(nro_uno, nro_dos), suma_uno));

    NumeroAstronomico nro_tres = crearDesdeCadena("203");
    NumeroAstronomico nro_cuatro = crearDesdeCadena("402");

    NumeroAstronomico suma_dos = crearDesdeCadena("405");

    assert(!sonIguales(sumar(nro_tres, nro_cuatro), suma_dos));
}
