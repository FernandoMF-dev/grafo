#include "headers/Cidade.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define MAX_NOME 15

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

/*
 * Inicializa e retorna uma nova instância de 'Cidade'.
 * */
Cidade *newCidade() {
    Cidade *cidade = (Cidade *) malloc(sizeof(Cidade));

    cidade->codigo = -1;
    cidade->nome = (char *) malloc(MAX_NOME * sizeof(char));

    return cidade;
}

/*
 * Retorna uma nova instância de 'Cidade' preenchido com os valores passados por parâmetro.
 * */
Cidade *readCidade(int codigo, char *nome) {
    Cidade *cidade = newCidade();

    cidade->codigo = codigo;
    strcpy(cidade->nome, nome);

    return cidade;
}

/*
 * Imprimi uma struct 'Cidade'
 * */
void printCidade(Cidade *cidade) {
    if (cidade == NULL) {
        printf("[NULL]");
        return;
    }

    printf("{'codigo': %d; 'nome': '%s'}", cidade->codigo, cidade->nome);
}
