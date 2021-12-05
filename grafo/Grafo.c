#include "headers/Grafo.h"

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

Edge *findMinimalEdgeGrafo(Grafo *grafo, const int *sourceIndexArray, int sourceIndexSize);

void copyVerticesGrafo(Grafo *target, Grafo *origin);

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

/*
 * Retorna a menor aresta 'Edge' de [grafo] com origem nos índices no vetor [sourceIndexArray], o quel tem tamanho [sourceIndexSize]
 *
 * Ignora as arestas com destino em algum índice que existam em [sourceIndexArray]
 * */
Edge *findMinimalEdgeGrafo(Grafo *grafo, const int *sourceIndexArray, int sourceIndexSize) {
    Edge *minEdge = readEdge(-1, -1, (float) 0.0);
    Edge *aux = newEdge();

    float *grafoEdgesArray;

    for (int i = 0; i < sourceIndexSize; ++i) {
        aux->origin = sourceIndexArray[i];
        grafoEdgesArray = grafo->edges[aux->origin];
        aux->destiny = getMinNonZeroWithBlackListArrayFloat(grafoEdgesArray, grafo->size,
                                                            sourceIndexArray, sourceIndexSize);

        if (aux->destiny != 0.0) {
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

/*
 * Copia os 'Vertice's do 'Grafo' [origin] e cola em [target]
 * */
void copyVerticesGrafo(Grafo *target, Grafo *origin) {
    for (int i = 0; i < target->size; i++) {
        target->vertices[i] = origin->vertices[i];
    }
}

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

/*
 * Inicializa e retorna uma nova instância de 'Grafo'.
 * */
Grafo *newGrafo(char *label, int size) {
    Grafo *grafo = (Grafo *) malloc(sizeof(Grafo));

    grafo->label = label;
    grafo->size = size;
    grafo->vertices = newVerticeArray(size);
    grafo->edges = newMatrixFloat(size);

    return grafo;
}

/*
 * Imprimi uma struct 'Grafo'.
 * */
void printGrafo(Grafo *grafo) {
    printf("\n=-=-=-=-=-=-=-= %s =-=-=-=-=-=-=-=\n", grafo->label);
    printVerticesGrafo(grafo);
    printf("\n");
    printEdgesGrafo(grafo);
}

/*
 * Imprime os vertices de um 'Grafo'.
 * */
void printVerticesGrafo(Grafo *grafo) {
    for (int i = 0; i < grafo->size; i++) {
        printVertice(grafo->vertices[i]);
    }
}

/*
 * Imprime as arestas de um 'Grafo'.
 * */
void printEdgesGrafo(Grafo *grafo) {
    for (int i = 0; i < grafo->size; i++) {
        for (int j = 0; j < grafo->size; ++j) {
            if (grafo->edges[i][j] != 0.0) {
                printf("%s -[%.2f]-> %s\n", grafo->vertices[i]->value->nome, grafo->edges[i][j],
                       grafo->vertices[j]->value->nome);
            }
        }
    }
}

/*
 * Insere a aresta [edge] em [grafo].
 * */
void insertEdgeGrafo(Grafo *grafo, Edge *edge) {
    if (grafo->size <= edge->origin || grafo->size <= edge->destiny || edge->origin < 0 || edge->destiny < 0) {
        return;
    }

    grafo->edges[edge->origin][edge->destiny] = edge->weight;
}

/*
 * Insere a aresta [edge] em [grafo] como uma via dupla.
 * */
void insertTwoWayEdgeGrafo(Grafo *grafo, Edge *edge) {
    int origin = edge->origin;
    int destiny = edge->destiny;

    insertEdgeGrafo(grafo, edge);
    edge->origin = destiny;
    edge->destiny = origin;

    insertEdgeGrafo(grafo, edge);
    edge->origin = origin;
    edge->destiny = destiny;
}

/*
 * Retorna um 'Grafo' com uma árvore geradora mínima de [origin]
 *
 * Não modifica [origin]
 * */
Grafo *getMinimumSpanningTree(Grafo *origin) {
    Grafo *minimumTree = newGrafo(origin->label, origin->size);
    int *visitedIndex = newIntegerArray(minimumTree->size);
    int visitedIndexSize = 1;
    Edge *edge;

    copyVerticesGrafo(minimumTree, origin);

    for (int i = 0; i < minimumTree->size; ++i) {
        edge = findMinimalEdgeGrafo(origin, visitedIndex, visitedIndexSize);
        insertTwoWayEdgeGrafo(minimumTree, edge);
        visitedIndex[i + 1] = edge->destiny;
        visitedIndexSize++;
    }

    free(edge);
    free(visitedIndex);
    return minimumTree;
}

/*
 * Retorna o tamanho total de todas as arestas de um grafo.
 * */
float getTotalEdgeWeight(Grafo *grafo) {
    float totalWeight = (float) 0.0;

    for (int i = 0; i < grafo->size; ++i) {
        for (int j = 0; j < grafo->size; ++j) {
            totalWeight += grafo->edges[i][j];
        }
    }

    return totalWeight;
}

/*
 * Retorna o tamanho total de todas as arestas de um grafo assumindo que todas as arestas são de via dupla.
 * */
float getTotalTwoWayEdgeWeight(Grafo *grafo) {
    return getTotalEdgeWeight(grafo) / 2;
}
