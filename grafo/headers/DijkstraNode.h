#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef GRAFO_DIJKSTRANODE_H
#define GRAFO_DIJKSTRANODE_H

typedef struct DijktraNode {
	int status;
	int verticeIndex;
	int previousVertice;
	int routeLenght;
} DijktraNode;

DijktraNode *newDijktraNode(int verticeIndex);

DijktraNode **prepareDijktraNodeArray(int size);

void setOriginPathDijktra(DijktraNode **dijktra, int origin);

int wasVisitedDijktra(DijktraNode **dijktra, int index);

int findNextNodeToVisitDijktra(DijktraNode **dijktra, int dijktraSize);

void rotulateNodeDijktra(DijktraNode **dijktra, int index);

#endif //GRAFO_DIJKSTRANODE_H
