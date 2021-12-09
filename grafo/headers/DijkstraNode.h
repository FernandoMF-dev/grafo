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

#endif //GRAFO_DIJKSTRANODE_H
