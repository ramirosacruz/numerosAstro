#include <stdio.h>
#include "./src/arithmetic.h"
#include "./src/numeroAstronomico.h"
#include "./src/astroFile.h"
#include "./src/errorHandling.h"

void primerOp();
void segundaOp();
void terceraOp();
void imprimir(NumeroAstronomico nro);
int main()
{
  int rta;
  printf("Bienvenidos a la biblioteca NumerosAstronomicos.h \n");
  printf("(1) Crear un número astronómico a partir de cadena\n");
  printf("(2) Crear un número astronómico aleatorio\n");
  printf("(3) Crear un número astronómico desde cifras seguidas de cero\n");
  
  scanf("%d", &rta);

  switch(rta){
    case 1:
      primerOp();
      break;
    case 2: 
      segundaOp();
      break;
    default: 
      printf("\nIntroduzca una opción válida\n");
      break;
  }
}

void imprimir(NumeroAstronomico nro)
{
  char rta;
  printf("\n>>>> Se imprimio el resultado en ./FlujoNATexto.txt\n");
  FILE *flujo1 = fopen("FlujoNATexto.txt", "w+");
  printNA(nro, flujo1);
  fclose(flujo1);
}
void primerOp()
{
  char str[100];

  printf("\n Escriba la cadena que desea crear \n");

  scanf("%s", str);
  
  NumeroAstronomico nro = crearDesdeCadena(str);

  imprimir(nro);
}


void segundaOp(){
  char str[100];
  NumeroAstronomico nro = crearAleatorio();
  imprimir(nro);
}


void tercerOp(){
 char str[100];

  printf("\n Escriba la cadena aleatoriamente \n");

  scanf("%s", str);
  
  NumeroAstronomico nro = crearDesdeCifraSeguidaDeCeros(2,10);
  
  FILE *flujo1 = fopen("FlujoNATexto.txt", "w+");
  printNA(nro, flujo1);
}

