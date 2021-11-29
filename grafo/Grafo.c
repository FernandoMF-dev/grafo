#include "headers/Grafo.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

double **buildGrafoEdgeMatrix(int size);

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

double **buildGrafoEdgeMatrix(int size) {
    double **edgeMatrix = (double **) malloc(size * sizeof(double *));

    for (int i = 0; i < size; ++i) {
        edgeMatrix[i] = (double *) malloc(size * sizeof(double));
        for (int j = 0; j < size; ++j) {
            edgeMatrix[i][j] = 0.0;
        }
    }

    return edgeMatrix;
}

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

Grafo *newGrafo(char *label, int size) {
    Grafo *grafo = (Grafo *) malloc(sizeof(Grafo));

    grafo->label = label;
    grafo->size = size;
    grafo->vertices = buildGrafoVerticesArray(size);
    grafo->edges = buildGrafoEdgeMatrix(size);

    return grafo;
}

void printGrafo(Grafo *grafo) {
    printf("\n=-=-=-=-=-=-=-= %s =-=-=-=-=-=-=-=\n", grafo->label);
    printVerticesGrafo(grafo);
    printf("\n");
    printEdgesGrafo(grafo);
}

void printVerticesGrafo(Grafo *grafo) {
    for (int i = 0; i < grafo->size; ++i) {
        printVertice(grafo->vertices[i]);
    }
}

void printEdgesGrafo(Grafo *grafo) {
    for (int i = 0; i < grafo->size; ++i) {
        for (int j = 0; j < grafo->size; ++j) {
            printf("%d -[%.2lf]-> %d\n", grafo->vertices[i]->index, grafo->edges[i][j], grafo->vertices[j]->index);
        }
    }
}