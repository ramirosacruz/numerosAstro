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
    NumeroAstronomico a = crearDesdeCadena("1235496546848464646846848644548454684564866");
    mostrar(a,6,flujo);
    printf("\n ✅ Todos los test corrieron  \n");
}
