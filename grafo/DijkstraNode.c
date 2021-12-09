#include "headers/DijkstraNode.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define STATUS_UNVISITED 0
#define STATUS_NEXT 1
#define STATUS_VISITED 2

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

DijktraNode *newDijktraNode(int verticeIndex) {
	DijktraNode *node = (DijktraNode *) malloc(sizeof(DijktraNode));

	node->status = STATUS_UNVISITED;
	node->verticeIndex = verticeIndex;
	node->previousVertice = -1;
	node->routeLenght = INT_MAX;

	return node;
}

DijktraNode **prepareDijktraNodeArray(int size) {
	DijktraNode **nodeArray = (DijktraNode **) malloc(size * sizeof(DijktraNode *));

	for (int i = 0; i < size; ++i) {
		nodeArray[i] = newDijktraNode(i);
	}

	return nodeArray;
}

void setOriginPathDijktra(DijktraNode **dijktra, int origin) {
	dijktra[origin]->status = STATUS_NEXT;
	dijktra[origin]->routeLenght = 0;
}

int wasVisitedDijktra(DijktraNode **dijktra, int index) {
	return dijktra[index]->status == STATUS_VISITED;
}