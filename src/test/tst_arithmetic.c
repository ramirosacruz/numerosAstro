#include <stdio.h>
#include "../utils/general.h"
#include <assert.h>
#include "../arithmetic.h"

void test_sumar();
void test_esMenor();
void test_sonIguales();

int main()
{
    test_esMenor();
    test_sumar();
}
  
void test_sonIguales(){
    NumeroAstronomico miNumero;
    miNumero.entero = "120";
    miNumero.longitudError = 3;

    NumeroAstronomico otroNumero;
    otroNumero.entero = "220";
    otroNumero.longitudError = 3;
         
    assert(esMenor(miNumero, otroNumero)); 
}

  
void test_esMenor(){
    NumeroAstronomico a;
    a.entero = "1120";
    a.longitudError = 1000;

    NumeroAstronomico b;
    b.entero = "820";
    b.longitudError = 1000;
         
    assert(esMenor(a, b)); 

    NumeroAstronomico c;
    c.entero = "2200";
    c.longitudError = 1002;

    NumeroAstronomico d;
    d.entero = "1000";
    d.longitudError = 1001;
         
    assert(esMenor(d, c));
}

void test_sumar(){
   /*  NumeroAstronomico miNumero;
    miNumero.entero = "120";
    miNumero.longitudError = 10;

    NumeroAstronomico miNumeroDos;
    miNumeroDos.entero = "820";
    miNumeroDos.longitudError = 10;
    *miNumero.entero+=2;
         
    printf("->es %c \n", *miNumero.entero);
    assert(miNumero.entero == "10"); */
}
 