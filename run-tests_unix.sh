#!/bin/sh

gcc src/test/tst_arithmetic.c && ./a.out

gcc src/test/tst_astroFile.c && ./a.out

gcc src/test/tst_errorHandling.c && ./a.out

gcc src/test/tst_numeroAstronomico.c && ./a.out

gcc src/test/tst_general.c && ./a.out

