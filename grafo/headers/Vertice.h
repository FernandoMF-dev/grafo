#include <stdio.h>
#include <stdlib.h>

#include "Cidade.h"

#ifndef GRAFO_VERTICE_H
#define GRAFO_VERTICE_H

typedef struct Vertice {
    int index;
    Cidade *value;
} Vertice;

Vertice *newVertice();

Vertice *readVertice(int index, Cidade *value);

Vertice **buildGrafoVerticesArray(int size);

void printVertice(Vertice *vertice);

#endif //GRAFO_VERTICE_H
