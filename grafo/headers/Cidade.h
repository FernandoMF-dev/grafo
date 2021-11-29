#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifndef GRAFO_CIDADE_H
#define GRAFO_CIDADE_H

typedef struct Cidade {
    char *nome;
    int codigo;
} Cidade;

Cidade *newCidade();

Cidade *readCidade(int codigo, char *nome);

void printCidade(Cidade *cidade);

#endif //GRAFO_CIDADE_H
