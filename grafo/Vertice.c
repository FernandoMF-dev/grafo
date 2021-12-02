#include "headers/Vertice.h"

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

Vertice *newVertice() {
    Vertice *vertice = (Vertice *) malloc(sizeof(Vertice));

    vertice->index = -1;
    vertice->value = NULL;

    return vertice;
}

Vertice *readVertice(int index, Cidade *value) {
    Vertice *vertice = newVertice();

    vertice->index = index;
    vertice->value = value;

    return vertice;
}

Vertice **buildGrafoVerticesArray(int size) {
    Vertice **verticeArray = (Vertice **) malloc(size * sizeof(Vertice *));

    for (int i = 0; i < size; i++) {
        verticeArray[i] = NULL;
    }

    return verticeArray;
}

void printVertice(Vertice *vertice) {
    if (vertice == NULL) {
        printf("[NULL]\n");
        return;
    }

    printf("%d - ", vertice->index);
    printCidade(vertice->value);
    printf("\n");
}