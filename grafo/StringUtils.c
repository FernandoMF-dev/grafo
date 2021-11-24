#include "headers/StringUtils.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define TAM_NOME 11

char VOGAIS[10] = "aeiouAEIOU";

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

char gerarLetraMaiuscula();

char gerarLetraMinuscula();

char gerarVogal();

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

char gerarLetraMaiuscula() {
    return (char) (getRandomInt(26) + 65);
}

char gerarLetraMinuscula() {
    return (char) (getRandomInt(26) + 97);
}

char gerarVogal() {
    return VOGAIS[getRandomInt((int) strlen(VOGAIS))];
}

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

char *getRandomWord() {
    int i;
    char *palavra = (char *) malloc(TAM_NOME * sizeof(char));

    palavra[0] = gerarLetraMaiuscula();
    for (i = 1; i < TAM_NOME; i++) {
        if (arrayContainsChar(palavra[i - 1], VOGAIS)) {
            palavra[i] = gerarLetraMinuscula();
        } else {
            palavra[i] = gerarVogal();
        }
    }
    palavra[i] = '\0';

    return palavra;
}