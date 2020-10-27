#include <stdio.h>
#include "../utils/general.h"
#include <assert.h>
#include "../arithmetic.h"
#include "../numeroAstronomico.h"

void test_sumar();
void test_esMenor();
void test_sonIguales();

int main()
{
    test_esMenor();
    test_sumar();
    test_sonIguales();
}
  
void test_sonIguales(){
    NumeroAstronomico a;
    a.entero = "220";
    a.longitudError = 3;

    NumeroAstronomico b;
    b.entero = "220";
    b.longitudError = 3;
         
    assert(sonIguales(a, b)); 

    NumeroAstronomico c;
    c.entero = "220";
    c.longitudError = 3;

    NumeroAstronomico d;
    d.entero = "230";
    d.longitudError = 3;
         
    assert(sonIguales(c, d)); 
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
    c.entero = "200";
    c.longitudError = 7;

    NumeroAstronomico d;
    d.entero = "322";
    d.longitudError = 5;
         
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
 