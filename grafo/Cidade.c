#include "headers/Cidade.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define MAX_NOME 15

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

Cidade *newCidade(int codigo, char *nome) {
    Cidade *n = (Cidade *) malloc(sizeof(Cidade));

    n->codigo = codigo;
    n->nome = (char *) malloc(MAX_NOME * sizeof(char));
    strcpy(n->nome, nome);

    return n;
}