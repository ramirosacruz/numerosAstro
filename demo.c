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

int main()
{
  int rta;
  int verificacion = TRUE;
  printf("Bienvenidos a la biblioteca NumerosAstronomicos.h, presione... \n");
  printf("(1) Para saber si un numero es menor que otro.\n");
  printf("(2) Para saber si dos numeros son iguales.\n");
  printf("(3) Para sumar dos numeros.\n");

  do
  {
    scanf("%d", &rta);

    switch (rta)
    {
    case 1:
      esMenorNA();
      break;
    case 2:
      sonIgualesNA();
      break;
    case 3:
      sumaNA();
      break;
    default:
      printf("\nIntroduzca una opción válida\n");
      break;
    }
  } while (verificacion == FALSE);

  return 0;
}

void sumaNA()
{
  NumeroAstronomico a;
  NumeroAstronomico b;
  NumeroAstronomico c;
  a = ingresarNumeros();
  b = ingresarNumeros();
  c = sumar(a, b);
  c.entero += 2;
  printf("\n La suma es: \n %s", c.entero);
  imprimir(c);
}
void esMenorNA()
{
  NumeroAstronomico a;
  NumeroAstronomico b;
  int c;
  a = ingresarNumeros();
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
  printf("(1) Crear un número astronómico a partir de cadena\n");
  printf("(2) Crear un número astronómico aleatorio\n");
  printf("(3) Crear un número astronómico desde cifras seguidas de cero\n");
  do
  {
    scanf("%d", &rta);

    switch (rta)
    {
    case 1:
      nro = primerOp();
      break;
    case 2:
      nro = segundaOp();
      break;
    case 3:
      nro = tercerOp();
      break;
    default:
      printf("\nIntroduzca una opción válida\n");
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
  } while (verificacion == FALSE);

  imprimir(nro);
  return nro;
}

NumeroAstronomico segundaOp()
{
  NumeroAstronomico nro = crearAleatorio();
  nro.entero += 2;
  printf("\n La cadena aleatoria es: \n %s", nro.entero);
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

    scanf("%d", cifra);

    printf("\n Escriba la cantidad de ceros\n");

    scanf("%d", cifra);

    nro = crearDesdeCifraSeguidaDeCeros(cifra, ceros);

    if (esError(nro))
    {
      verificacion = FALSE;
      printf("\n Vuelva a ingresar los numeros \n");
    }
  } while (verificacion == FALSE);

  imprimir(nro);
  return nro;
}
