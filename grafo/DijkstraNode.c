#include "headers/DijkstraNode.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define STATUS_UNVISITED 0
#define STATUS_NEXT 1
#define STATUS_VISITED 2

#define ERRO_FALHA_ALOCACAO "\n\tERRO: Erro durante alocação de memória!\n"

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

DijkstraNode *newDijkstraNode() {
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

DijkstraNode **prepareDijkstraNodeArray(int size) {
	DijkstraNode **nodeArray = (DijkstraNode **) malloc(size * sizeof(DijkstraNode *));
	DijkstraNode *node;

	if (nodeArray == NULL) {
		printf(ERRO_FALHA_ALOCACAO);
		return NULL;
	}

	int i;
	for (i = 0; i < size; ++i) {
		node = newDijkstraNode();

		if (node == NULL) {
			return NULL;
		}

		node->verticeIndex = i;
		nodeArray[i] = node;
	}

	return nodeArray;
}

void setOriginPathDijkstra(DijkstraNode **dijkstra, int origin) {
	dijkstra[origin]->status = STATUS_NEXT;
	dijkstra[origin]->routeLenght = 0;
}

int isVisitedDijkstra(DijkstraNode **dijkstra, int index) {
	return dijkstra[index]->status == STATUS_VISITED;
}

void setNextDijkstra(DijkstraNode **dijkstra, int target, int previous, float edgeWeight) {
	if (edgeWeight == 0 || dijkstra[target]->status == STATUS_VISITED) {
		return;
	}

	DijkstraNode *node = dijkstra[target];

	if (node->status == STATUS_NEXT && dijkstra[previous]->routeLenght + edgeWeight >= node->routeLenght) {
		return;
	}

	node->status = STATUS_NEXT;
	node->routeLenght = dijkstra[previous]->routeLenght + edgeWeight;
	node->previousVertice = previous;
}

int findNextNodeToVisitDijkstra(DijkstraNode **dijkstra, int dijkstraSize) {
	DijkstraNode *next = dijkstra[0];
	DijkstraNode *aux;

	for (int i = 1; i < dijkstraSize; ++i) {
		aux = dijkstra[i];

		if (next->status == STATUS_VISITED || (aux->status == STATUS_NEXT && aux->routeLenght < next->routeLenght)) {
			next = aux;
		}
	}

	return next->verticeIndex;
}

void updatePreviousVerticeDijkstra(DijkstraNode **dijkstra, int target, int previous, float edgeWeight) {
	DijkstraNode *vertice = dijkstra[target];
	DijkstraNode *previousVertice = dijkstra[previous];

	if (edgeWeight == 0
		|| target == previous
		|| vertice->status != STATUS_VISITED
		|| previousVertice->routeLenght == (float) INT_MAX) {
		return;
	}

	if (previousVertice->routeLenght + edgeWeight < vertice->routeLenght) {
		vertice->routeLenght = previousVertice->routeLenght + edgeWeight;
		vertice->previousVertice = previousVertice->verticeIndex;
	}
}

void rotulateNodeDijkstra(DijkstraNode **dijkstra, int index) {
	dijkstra[index]->status = STATUS_VISITED;
}
