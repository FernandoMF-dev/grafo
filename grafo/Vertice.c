#include "headers/Vertice.h"

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

/*
 * Inicializa e retorna uma nova instância de 'Vertice'.
 * */
Vertice *newVertice() {
    Vertice *vertice = (Vertice *) malloc(sizeof(Vertice));

    vertice->index = -1;
    vertice->value = NULL;

    return vertice;
}

/*
 * Retorna uma nova instância de 'Vertice' preenchido com os valores passados por parâmetro.
 * */
Vertice *readVertice(int index, Cidade *value) {
    Vertice *vertice = newVertice();

    vertice->index = index;
    vertice->value = value;

    return vertice;
}

/*
 * Retorna um vetor de ponteiros de 'Vertice' com tamanho [size].
 *
 * Os valores são iniciados como NULL.
 * */
Vertice **newVerticeArray(int size) {
    Vertice **verticeArray = (Vertice **) malloc(size * sizeof(Vertice *));

    for (int i = 0; i < size; i++) {
        verticeArray[i] = NULL;
    }

    return verticeArray;
}

/*
 * Imprimi uma struct 'Vertice'
 * */
void printVertice(Vertice *vertice) {
    if (vertice == NULL) {
        printf("[NULL]\n");
        return;
    }

    printf("%d - ", vertice->index);
    printCidade(vertice->value);
    printf("\n");
}