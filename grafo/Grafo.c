#include "headers/Grafo.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

Edge *findMinimalEdgeGrafo(Grafo *grafo, const int *verticeArray, int verticeArraySize);

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

Edge *findMinimalEdgeGrafo(Grafo *grafo, const int *verticeArray, int verticeArraySize) {
    Edge *minEdge = readEdge(-1, -1, 0.0);
    double doubleWeight;
    int index;

    for (int i = 0; i < verticeArraySize; ++i) {
        index = getMinNonZeroWithBlackListArrayDouble(grafo->edges[verticeArray[i]], grafo->size,
                                                      verticeArray, verticeArraySize);

        if (index != -1) {
            doubleWeight = grafo->edges[i][index];
            if (minEdge->weight == 0.0 || minEdge->weight > doubleWeight) {
                minEdge->origin = i;
                minEdge->destiny = index;
                minEdge->weight = doubleWeight;
            }
        }
    }

    return minEdge;
}

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

Grafo *newGrafo(char *label, int size) {
    Grafo *grafo = (Grafo *) malloc(sizeof(Grafo));

    grafo->label = label;
    grafo->size = size;
    grafo->vertices = buildGrafoVerticesArray(size);
    grafo->edges = newMatrixDouble(size);

    return grafo;
}

void printGrafo(Grafo *grafo) {
    printf("\n=-=-=-=-=-=-=-= %s =-=-=-=-=-=-=-=\n", grafo->label);
    printVerticesGrafo(grafo);
    printf("\n");
    printEdgesGrafo(grafo);
}

void printVerticesGrafo(Grafo *grafo) {
    for (int i = 0; i < grafo->size; ++i) {
        printVertice(grafo->vertices[i]);
    }
}

void printEdgesGrafo(Grafo *grafo) {
    for (int i = 0; i < grafo->size; ++i) {
        for (int j = 0; j < grafo->size; ++j) {
            if (grafo->edges[i][j] != 0.0) {
//                printf("%d -[%.2lf]-> %d\n", grafo->vertices[i]->index, grafo->edges[i][j], grafo->vertices[j]->index);
                printf("%s -[%.2lf]-> %s\n", grafo->vertices[i]->value->nome, grafo->edges[i][j],
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
    int *visitedIndex = newIntegerArray(grafo->size);
    int counter = 0;

    for (int i = 0; i < grafo->size; ++i) {
        grafo->vertices[i] = origin->vertices[i];
    }

    while (counter < grafo->size) {
        Edge *visited = findMinimalEdgeGrafo(grafo, visitedIndex, grafo->size);
        insertEdgeGrafo(grafo, visited);
        visitedIndex[counter] = visited->destiny;
        counter++;
        free(visited);
    }

    free(visitedIndex);
    return grafo;
}