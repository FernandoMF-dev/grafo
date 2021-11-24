#include "headers/ArrayUtils.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

int arrayContainsChar(char agulha, char *palheiro) {
    int lenght = (int) strlen(palheiro);

    for (int i = 0; i < lenght; ++i) {
        if (agulha == palheiro[i]) {
            return 1;
        }
    }

    return 0;
}