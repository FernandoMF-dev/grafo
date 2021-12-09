#include <stdio.h>
#include <stdlib.h>

#include "Vertice.h"

#ifndef GRAFO_EDGE_H
#define GRAFO_EDGE_H

typedef struct Edge {
	int originIndex;
	int destinyIndex;
	float weight;
	Vertice *origin;
	Vertice *destiny;
} Edge;

Edge *newEdge();

Edge *readEdge(int originIndex, int destinyIndex, float weight);

Edge *readDetailEdge(Vertice *origin, Vertice *destiny, float weight);

void printEdge(Edge *edge);

void printDetailEdge(Edge *edge);

#endif //GRAFO_EDGE_H
