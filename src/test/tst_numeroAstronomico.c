#include <stdio.h>
#include "../utils/general.h"
#include "../arithmetic.h"
#include "../numeroAstronomico.h"
#include "../astroFile.h"
#include <assert.h>

int main()
{
    printf("\n --- 🧪  TEST NUMERO ASTRONÓMICO 🧪 --- \n");
    printf("\n 🔃 Cargando Test... \n");
    FILE *flujo;
    flujo = stdout;
    NumeroAstronomico a = crearDesdeCadena("12");
    int bool = esSecuenciaInvalida(a);
    //mostrar(a, 1, flujo);
    printf("%d  \n", bool);
    //printf("%s", a.entero);
    printf("\n ✅ Todos los test corrieron  \n");
}
