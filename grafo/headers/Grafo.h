#include <stdio.h>
#include <stdlib.h>

#include "Cidade.h"
#include "Vertice.h"

#ifndef GRAFO_GRAFO_H
#define GRAFO_GRAFO_H

typedef struct Grafo {
    char *label;
    Vertice **vertices;
    int size;
    double **edges;
} Grafo;

Grafo *newGrafo(char *label, int size);

void printGrafo(Grafo *grafo);

void printVerticesGrafo(Grafo *grafo);

void printEdgesGrafo(Grafo *grafo);

#endif //GRAFO_GRAFO_H
