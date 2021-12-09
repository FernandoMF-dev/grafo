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

DijkstraNode *newDijkstraNode();

DijkstraNode **prepareDijkstraNodeArray(int size);

void setOriginPathDijkstra(DijkstraNode **dijkstra, int origin);

int isVisitedDijkstra(DijkstraNode **dijkstra, int index);

void setNextDijkstra(DijkstraNode **dijkstra, int target, int previous, float edgeWeight);

int findNextNodeToVisitDijkstra(DijkstraNode **dijkstra, int dijkstraSize);

void updatePreviousVerticeDijkstra(DijkstraNode **dijkstra, int target, int previous, float edgeWeight);

void rotulateNodeDijkstra(DijkstraNode **dijkstra, int index);

#endif //GRAFO_DIJKSTRANODE_H
