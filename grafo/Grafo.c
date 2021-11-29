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

Grafo *newGrafo(int size) {
    Grafo *grafo = (Grafo *) malloc(sizeof(Grafo));

    grafo->size = size;
    grafo->vertices = buildGrafoVerticesArray(size);
    grafo->edges = buildGrafoEdgeMatrix(size);

    return grafo;
}
