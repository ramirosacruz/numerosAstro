#include <stdio.h>
#include <stdlib.h>
#include <general.h>
#include <arithmetic.h>
#include <astroFile.h>

NumeroAstronomico read(FILE* flujo);
FILE* write(NumeroAstronomico nroAstronomico,FILE* flujo);

NumeroAstronomico scan(FILE* flujo);
FILE* print(NumeroAstronomico nroAstronomico,FILE* flujo);