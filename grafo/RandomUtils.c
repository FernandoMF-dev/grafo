#include "headers/RandomUtils.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

int getRandomInt(int ceil) {
    return rand() % ceil;
}

double getRandomDecimal() {
    int r1 = rand();
    int r2 = rand();

    if (r1 < r2) {
        return ((double) r1) / ((double) r2);
    }
    return ((double) r2) / ((double) r1);
}