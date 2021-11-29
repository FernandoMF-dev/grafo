#include <stdio.h>
#include <stdlib.h>

#include "Cidade.h"

#ifndef GRAFO_GRAFO_H
#define GRAFO_GRAFO_H

typedef struct Vertice {
    int index;
    Cidade *value;
} Vertice;

typedef struct Grafo {
    Vertice *vertices;
    int verticesLenght
    double **edges;
} Grafo;

#endif //GRAFO_GRAFO_H
