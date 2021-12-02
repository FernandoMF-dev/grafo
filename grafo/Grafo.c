#include "headers/Grafo.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

Edge *findMinimalEdgeGrafo(Grafo *grafo, const int *visitedIndexArray, int visitedIndexSize);

void copyVerticesGrafo(Grafo *target, Grafo *origin);

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

Edge *findMinimalEdgeGrafo(Grafo *grafo, const int *visitedIndexArray, int visitedIndexSize) {
    Edge *minEdge = readEdge(-1, -1, (float) 0.0);
    Edge *aux = newEdge();

    float *grafoEdgesArray;

    for (int i = 0; i < visitedIndexSize; ++i) {
        aux->origin = visitedIndexArray[i];
        grafoEdgesArray = grafo->edges[aux->origin];
        aux->destiny = getMinNonZeroWithBlackListArrayFloat(grafoEdgesArray, grafo->size,
                                                            visitedIndexArray, visitedIndexSize);

        if (aux->destiny != -1) {
            aux->weight = grafoEdgesArray[aux->destiny];

            if (minEdge->weight == 0 || minEdge->weight > aux->weight) {
                minEdge->origin = aux->origin;
                minEdge->destiny = aux->destiny;
                minEdge->weight = aux->weight;
            }
        }
    }

    free(aux);
    return minEdge;
}

void copyVerticesGrafo(Grafo *target, Grafo *origin) {
    for (int i = 0; i < target->size; i++) {
        target->vertices[i] = origin->vertices[i];
    }
}

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

Grafo *newGrafo(char *label, int size) {
    Grafo *grafo = (Grafo *) malloc(sizeof(Grafo));

    grafo->label = label;
    grafo->size = size;
    grafo->vertices = buildGrafoVerticesArray(size);
    grafo->edges = newMatrixFloat(size);

    return grafo;
}

void printGrafo(Grafo *grafo) {
    printf("\n=-=-=-=-=-=-=-= %s =-=-=-=-=-=-=-=\n", grafo->label);
    printVerticesGrafo(grafo);
    printf("\n");
    printEdgesGrafo(grafo);
}

void printVerticesGrafo(Grafo *grafo) {
    for (int i = 0; i < grafo->size; i++) {
        printVertice(grafo->vertices[i]);
    }
}

void printEdgesGrafo(Grafo *grafo) {
    for (int i = 0; i < grafo->size; i++) {
        for (int j = 0; j < grafo->size; ++j) {
            if (grafo->edges[i][j] != 0.0) {
//                printf("%d -[%.2f]-> %d\n", grafo->vertices[i]->index, grafo->edges[i][j], grafo->vertices[j]->index);
                printf("%s -[%.2f]-> %s\n", grafo->vertices[i]->value->nome, grafo->edges[i][j],
                       grafo->vertices[j]->value->nome);
            }
        }
    }
}

void insertEdgeGrafo(Grafo *grafo, Edge *edge) {
    if (grafo->size <= edge->origin || grafo->size <= edge->destiny || edge->origin < 0 || edge->destiny < 0) {
        return;
    }

    grafo->edges[edge->origin][edge->destiny] = edge->weight;
}

void insertTwoWaysEdgeGrafo(Grafo *grafo, Edge *edge) {
    int origin = edge->origin;
    int destiny = edge->destiny;

    insertEdgeGrafo(grafo, edge);
    edge->origin = destiny;
    edge->destiny = origin;

    insertEdgeGrafo(grafo, edge);
    edge->origin = origin;
    edge->destiny = destiny;
}

Grafo *getMinimumSpanningTree(Grafo *origin) {
    Grafo *minimumTree = newGrafo(origin->label, origin->size);
    int *visitedIndex = newIntegerArray(minimumTree->size);
    int visitedIndexSize = 1;

    copyVerticesGrafo(minimumTree, origin);

    for (int i = 0; i < minimumTree->size; ++i) {
        Edge *edge = findMinimalEdgeGrafo(origin, visitedIndex, visitedIndexSize);
        insertTwoWaysEdgeGrafo(minimumTree, edge);
        visitedIndex[i + 1] = edge->destiny;
        visitedIndexSize++;
        free(edge);
    }

    free(visitedIndex);
    return minimumTree;
}
