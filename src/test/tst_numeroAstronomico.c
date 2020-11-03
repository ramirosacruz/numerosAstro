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
    printf("\n --- 🧪  TEST NUMERO ASTRONÓMICO 🧪 --- \n");
    printf("\n 🔃 Cargando Test... \n");

    test_esMenor();
    test_sumar();
    test_sonIguales();
    printf("\n ✅ Todos los test corrieron  \n");
}
