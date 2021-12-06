#include "headers/RandomUtils.h"

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

/*
 * Retorna um 'int' aleatório entre 0 (incluso) e [ceil] (não incluso).
* */
int getRandomInteger(int ceil) {
	return rand() % ceil;
}

/*
 * Retorna um 'double' aleatório entre 0 e 1.
 * */
double getRandomDecimal() {
	int r1 = rand();
	int r2 = rand();

	if (r1 < r2) {
		return ((double) r1) / ((double) r2);
	}
	return ((double) r2) / ((double) r1);
}
