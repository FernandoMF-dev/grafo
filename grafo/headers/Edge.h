#include <stdio.h>
#include <stdlib.h>

#ifndef GRAFO_EDGE_H
#define GRAFO_EDGE_H

typedef struct Edge {
	int origin;
	int destiny;
	float weight;
} Edge;

Edge *newEdge();

Edge *readEdge(int origin, int destiny, float weight);

void printEdge(Edge *edge);

#endif //GRAFO_EDGE_H
