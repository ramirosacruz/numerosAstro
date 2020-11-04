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
    NumeroAstronomico a = crearAleatorio();
    mostrar(a,6,flujo);
    printf("\n ✅ Todos los test corrieron  \n");
}
