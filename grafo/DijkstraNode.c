#include "headers/DijkstraNode.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define STATUS_UNVISITED 0
#define STATUS_NEXT 1
#define STATUS_VISITED 2

#define ERRO_FALHA_ALOCACAO "\n\tERRO: Erro durante alocação de memória!\n"

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

DijkstraNode *newDijktraNode() {
	DijkstraNode *node = (DijkstraNode *) malloc(sizeof(DijkstraNode));

	if (node == NULL) {
		printf(ERRO_FALHA_ALOCACAO);
		return NULL;
	}

	node->status = STATUS_UNVISITED;
	node->verticeIndex = -1;
	node->previousVertice = -1;
	node->routeLenght = (float) INT_MAX;

	return node;
}

DijkstraNode **prepareDijktraNodeArray(int size) {
	DijkstraNode **nodeArray = (DijkstraNode **) malloc(size * sizeof(DijkstraNode *));
	DijkstraNode *node;

	if (nodeArray == NULL) {
		printf(ERRO_FALHA_ALOCACAO);
		return NULL;
	}

	int i;
	for (i = 0; i < size; ++i) {
		node = newDijktraNode();

		if (node == NULL) {
			return NULL;
		}

		node->verticeIndex = i;
		nodeArray[i] = node;
	}

	return nodeArray;
}

void setOriginPathDijktra(DijkstraNode **dijktra, int origin) {
	dijktra[origin]->status = STATUS_NEXT;
	dijktra[origin]->routeLenght = 0;
}

int isVisitedDijktra(DijkstraNode **dijktra, int index) {
	return dijktra[index]->status == STATUS_VISITED;
}

void setNextDijktra(DijkstraNode **dijktra, int index, int previous, float edgeWeight) {
	if (dijktra[index]->status == STATUS_VISITED) {
		return;
	}

	DijkstraNode *node = dijktra[index];

	if (node->status == STATUS_NEXT && dijktra[previous]->routeLenght + edgeWeight >= node->routeLenght) {
		return;
	}

	node->status = STATUS_NEXT;
	node->routeLenght = dijktra[previous]->routeLenght + edgeWeight;
	node->previousVertice = previous;
}

int findNextNodeToVisitDijktra(DijkstraNode **dijktra, int dijktraSize) {
	DijkstraNode *next = dijktra[0];
	DijkstraNode *aux;

	for (int i = 1; i < dijktraSize; ++i) {
		aux = dijktra[i];

		if (next->status == STATUS_VISITED || (aux->status == STATUS_NEXT && aux->routeLenght < next->routeLenght)) {
			next = aux;
		}
	}

	return next->verticeIndex;
}

void updatePreviousVertice(DijkstraNode **dijktra, int index, int previous, float edgeWeight) {
	DijkstraNode *vertice = dijktra[index];
	DijkstraNode *previousVertice = dijktra[previous];

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

void rotulateNodeDijktra(DijkstraNode **dijktra, int index) {
	dijktra[index]->status = STATUS_VISITED;
}