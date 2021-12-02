#include "headers/Grafo.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

Edge *findMinimalEdgeGrafo(Grafo *grafo, const int *verticeArray, int verticeArraySize);

void copyVerticesGrafo(Grafo *target, Grafo *origin);

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

Edge *findMinimalEdgeGrafo(Grafo *grafo, const int *verticeArray, int verticeArraySize) {
    Edge *minEdge = readEdge(-1, -1, (float) 0.0);
    float floatWeight;
    int index;

    for (int i = 0; i < verticeArraySize; i++) {
        index = getMinNonZeroWithBlackListArrayFloat(grafo->edges[verticeArray[i]], grafo->size,
                                                     verticeArray, verticeArraySize);

        if (index != -1) {
            floatWeight = grafo->edges[i][index];
            if (minEdge->weight == 0.0 || minEdge->weight > floatWeight) {
                minEdge->origin = i;
                minEdge->destiny = index;
                minEdge->weight = floatWeight;
            }
        }
    }

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

Grafo *getMinimumSpanningTree(Grafo *origin) {
    Grafo *grafo = newGrafo(origin->label, origin->size);
    int *visitedIndex = newIntegerArray(grafo->size + 1);
    int counter = 1;

    copyVerticesGrafo(grafo, origin);

    insertEdgeGrafo(grafo, findMinimalEdgeGrafo(origin, newIntegerArray(1), 1));
    while (counter <= grafo->size) {
        Edge *visited = findMinimalEdgeGrafo(origin, visitedIndex, counter);
        insertEdgeGrafo(grafo, visited);
        visitedIndex[counter] = visited->destiny;
        counter++;
        free(visited);
    }

    free(visitedIndex);
    return grafo;
}