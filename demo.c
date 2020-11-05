#include <stdio.h>
#include "./src/arithmetic.h"
#include "./src/numeroAstronomico.h"
#include "./src/astroFile.h"
#include "./src/errorHandling.h"

NumeroAstronomico ingresarNumeros();
NumeroAstronomico primerOp();
NumeroAstronomico segundaOp();
NumeroAstronomico tercerOp();
void imprimir(NumeroAstronomico nro);
void sumaNA();
void esMenorNA();
void sonIgualesNA();
void mostrarNA();

int main()
{
  int rta;
  int verificacion = TRUE;
  printf("Bienvenidos a la biblioteca NumerosAstronomicos.h, presione... \n");
  printf("(1) Para saber si un numero es menor que otro.\n");
  printf("(2) Para saber si dos numeros son iguales.\n");
  printf("(3) Para sumar dos numeros.\n");
  printf("(4) Mostrar numero.\n");

  do
  {
    scanf("%d", &rta);

    switch (rta)
    {
    case 1:
      esMenorNA();
      verificacion = TRUE;
      break;
    case 2:
      sonIgualesNA();
      verificacion = TRUE;
      break;
    case 3:
      sumaNA();
      verificacion = TRUE;
      break;
    case 4:
      mostrarNA();
      verificacion = TRUE;
      break;
    default:
      printf("\nIntroduzca una opcion valida\n");
      verificacion = FALSE;
      break;
    }
  } while (verificacion == FALSE);

  system("PAUSE");
  return 0;
}

void mostrarNA()
{
  int gruposEnPrimeraLinea;
  NumeroAstronomico a;
  FILE *flujo;
  flujo = stdout;

  a = ingresarNumeros();
  printf("\n ingrese cantidad de grupos en primera linea \n");
  scanf("%d", &gruposEnPrimeraLinea);
  mostrar(a, gruposEnPrimeraLinea, flujo);
  printf("\n");
}

void sumaNA()
{
  NumeroAstronomico a;
  NumeroAstronomico b;
  NumeroAstronomico c;
  a = ingresarNumeros();
  printf("\n ingrese otro numero \n");
  b = ingresarNumeros();
  c = sumar(a, b);
  show(c);
  imprimir(c);
}
void esMenorNA()
{
  NumeroAstronomico a;
  NumeroAstronomico b;
  int c;
  a = ingresarNumeros();
  printf("\n ingrese otro numero \n");
  b = ingresarNumeros();
  c = esMenor(a, b);
  if (c)
    printf("\n El primero es menor que el segundo \n");
  else
    printf("\n El primero no es menor que el segundo \n");
}

void sonIgualesNA()
{
  NumeroAstronomico a;
  NumeroAstronomico b;
  int c;
  a = ingresarNumeros();
  printf("\n ingrese otro numero \n");
  b = ingresarNumeros();
  c = sonIguales(a, b);
  if (c)
    printf("\n Los numeros son iguales \n");
  else
    printf("\n Los numeros no son iguales \n");
}

NumeroAstronomico ingresarNumeros()
{
  int rta;
  int verificacion = TRUE;
  NumeroAstronomico nro;

  printf("Presione... \n");
  printf("(1) Crear un numero astronomico a partir de cadena\n");
  printf("(2) Crear un numero astronomico aleatorio\n");
  printf("(3) Crear un numero astronomico desde cifras seguidas de cero\n");
  do
  {
    scanf("%d", &rta);

    switch (rta)
    {
    case 1:
      nro = primerOp();
      verificacion = TRUE;
      break;
    case 2:
      nro = segundaOp();
      verificacion = TRUE;
      break;
    case 3:
      nro = tercerOp();
      verificacion = TRUE;
      break;
    default:
      printf("\nIntroduzca una opcion valida\n");
      verificacion = FALSE;
      break;
    }
  } while (verificacion == FALSE);

  return nro;
}

void imprimir(NumeroAstronomico nro)
{
  FILE *flujo1 = fopen("FlujoNATexto.txt", "w+");
  printNA(nro, flujo1);
  fclose(flujo1);
}
NumeroAstronomico primerOp()
{
  int verificacion = TRUE;
  char str[100];
  NumeroAstronomico nro;
  printf("\n Escriba la cadena que desea crear \n");

  do
  {
    scanf("%s", str);

    nro = crearDesdeCadena(str);

    if (esError(nro))
    {
      verificacion = FALSE;
      printf("\n Vuelva a ingresar la cadena \n");
    }
    else
      verificacion = TRUE;
  } while (verificacion == FALSE);

  imprimir(nro);
  return nro;
}

NumeroAstronomico segundaOp()
{
  NumeroAstronomico nro = crearAleatorio();
  show(nro);
  imprimir(nro);
  return nro;
}

NumeroAstronomico tercerOp()
{
  int cifra;
  int ceros;
  int verificacion = TRUE;
  NumeroAstronomico nro;

  do
  {
    printf("\n Escriba la cifra\n");

    scanf("%d", &cifra);

    printf("\n Escriba la cantidad de ceros\n");

    scanf("%d", &ceros);

    nro = crearDesdeCifraSeguidaDeCeros(cifra, ceros);

    if (esError(nro))
    {
      verificacion = FALSE;
      printf("\n Vuelva a ingresar los numeros \n");
    }
    else
      verificacion = TRUE;

  } while (verificacion == FALSE);

  imprimir(nro);
  return nro;
}
