#include <stdio.h>
#include "../utils/general.h"
#include <assert.h>

void test_enteroACaracter();
int main( int argc, const char* argv[] )
{
    test_enteroACaracter();
}

void test_enteroACaracter(){
    char a = enteroACaracter(11);
    assert(a == ';');
}

