#include <stdio.h>
#include "../utils/general.h"
#include <assert.h>
#include "../arithmetic.h"
#include "../numeroAstronomico.h"
void test_enteroACaracter();
int main()
{
    printf("\n --- 🧪 TEST GENERAL 🧪 --- \n");
    printf("\n 🔃 Cargando Test... \n");
    //test_enteroACaracter();
    //test_scanFlujoDeTexto();
    test_enteroACaracter();
    printf("\n ✅ Todos los test corrieron  \n");
    getchar();
}

void test_enteroACaracter()
{
    char a = enteroACaracter(11);
    assert(a == ';');
}
