#include <stdio.h>
#include "../utils/general.h"
#include <assert.h>
#include "../arithmetic.h"
#include "../numeroAstronomico.h"

void test_cadenaVacia();

int main()
{
    test_cadenaVacia();
    system("PAUSE");
}

void test_cadenaVacia(){
    NumeroAstronomico nro = crearDesdeCadena("153");
    assert(*nro.entero == '1');
}
