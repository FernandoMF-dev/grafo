#include <stdio.h>
#include <stdlib.h>

#include "ArrayUtils.h"
#include "DestroyUtils.h"
#include "Cidade.h"
#include "Vertice.h"
#include "Edge.h"
#include "Stack.h"
#include "DijkstraNode.h"

#ifndef GRAFO_GRAFO_H
#define GRAFO_GRAFO_H

typedef struct Grafo {
	char *label;
	Vertice **vertices;
	int size;
	float **edges;
} Grafo;

Grafo *newGrafo(char *label, int size);

void printGrafo(Grafo *grafo);

void printVerticesGrafo(Grafo *grafo);

void printEdgesGrafo(Grafo *grafo);

void insertEdgeGrafo(Grafo *grafo, Edge *edge);

void insertTwoWayEdgeGrafo(Grafo *grafo, Edge *edge);

Grafo *getMinimumSpanningTreeGrafo(Grafo *origin);

Stack *getMinimumPathGrafo(Grafo *grafo, int originIndex, int destinyIndex);

float getTotalEdgeWeightGrafo(Grafo *grafo);

float getTotalTwoWayEdgeWeightGrafo(Grafo *grafo);

#endif //GRAFO_GRAFO_H
