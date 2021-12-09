#include "headers/DijkstraNode.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define STATUS_UNVISITED 0
#define STATUS_NEXT 1
#define STATUS_VISITED 2

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

DijktraNode *newDijktraNode(int verticeIndex) {
	DijktraNode *node = (DijktraNode *) malloc(sizeof(DijktraNode));

	node->status = STATUS_UNVISITED;
	node->verticeIndex = verticeIndex;
	node->previousVertice = -1;
	node->routeLenght = (float) INT_MAX;

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

int isVisitedDijktra(DijktraNode **dijktra, int index) {
	return dijktra[index]->status == STATUS_VISITED;
}

void setNextDijktra(DijktraNode **dijktra, int index) {
	dijktra[index]->status = STATUS_NEXT;
}

int findNextNodeToVisitDijktra(DijktraNode **dijktra, int dijktraSize) {
	DijktraNode *next = dijktra[0];
	DijktraNode *aux;

	for (int i = 1; i < dijktraSize; ++i) {
		aux = dijktra[i];

		if (aux->status == STATUS_NEXT && aux->routeLenght < next->routeLenght) {
			next = aux;
		}
	}

	return next->verticeIndex;
}

void updatePreviousVertice(DijktraNode **dijktra, int index, int previous, float edgeWeight) {
	DijktraNode *vertice = dijktra[index];
	DijktraNode *previousVertice = dijktra[previous];

	if (edgeWeight == 0
		|| index == previous
		|| vertice->status != STATUS_VISITED
		|| previousVertice->routeLenght == (float) INT_MAX) {
		return;
	}

	if (previousVertice->routeLenght + edgeWeight < vertice->routeLenght) {
		vertice->routeLenght = previousVertice->routeLenght + edgeWeight;
		vertice->previousVertice = previousVertice->verticeIndex;
	}
}

void rotulateNodeDijktra(DijktraNode **dijktra, int index) {
	dijktra[index]->status = STATUS_VISITED;
}