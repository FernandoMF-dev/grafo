#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef GRAFO_DIJKSTRANODE_H
#define GRAFO_DIJKSTRANODE_H

typedef struct DijkstraNode {
	int status;
	int verticeIndex;
	int previousVertice;
	float routeLenght;
} DijkstraNode;

DijkstraNode *newDijktraNode();

DijkstraNode **prepareDijktraNodeArray(int size);

void setOriginPathDijktra(DijkstraNode **dijktra, int origin);

int isVisitedDijktra(DijkstraNode **dijktra, int index);

void setNextDijktra(DijkstraNode **dijktra, int index, int previous, float edgeWeight);

int findNextNodeToVisitDijktra(DijkstraNode **dijktra, int dijktraSize);

void updatePreviousVertice(DijkstraNode **dijktra, int index, int previous, float edgeWeight);

void rotulateNodeDijktra(DijkstraNode **dijktra, int index);

#endif //GRAFO_DIJKSTRANODE_H
