#include <stdio.h>
#include "../utils/general.h"
#include <assert.h>
#include "../arithmetic.h"
void test_enteroACaracter();
int main()
{
    test_enteroACaracter();
}

void test_enteroACaracter(){
    char a = enteroACaracter(11);
    assert(a == ';');
}
 

