#include "testTabulky.h"

int testTabulky::getNahodnaHodnota(int paCislo)
{
	int random;
	random = rand() % paCislo + 1;
	return random;
}

int testTabulky::getNahodnyIndex(int paCislo)
{
	if (paCislo == 0)
		return 0;

	int random;
	random = rand() % paCislo;
	return random;
}
