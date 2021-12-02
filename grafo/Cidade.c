#include "headers/Cidade.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define MAX_NOME 15

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

Cidade *newCidade() {
    Cidade *cidade = (Cidade *) malloc(sizeof(Cidade));

    cidade->codigo = -1;
    cidade->nome = (char *) malloc(MAX_NOME * sizeof(char));

    return cidade;
}

Cidade *readCidade(int codigo, char *nome) {
    Cidade *cidade = newCidade();

    cidade->codigo = codigo;
    strcpy(cidade->nome, nome);

    return cidade;
}

void printCidade(Cidade *cidade) {
    if (cidade == NULL) {
        printf("[NULL]");
        return;
    }

    printf("{'codigo': %d; 'nome': '%s'}", cidade->codigo, cidade->nome);
}
