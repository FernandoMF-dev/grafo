#include "headers/Edge.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

Edge *newEdge() {
    Edge *edge = (Edge *) malloc(sizeof(Edge));

    edge->origin = -1;
    edge->destiny = -1;
    edge->weight = 0.0;

    return edge;
}

Edge **newEdgeArray(int size) {
    Edge **edgeArray = (Edge **) malloc(size * sizeof(Edge *));

    for (int i = 0; i < size; ++i) {
        edgeArray[i] = NULL;
    }

    return edgeArray;
}

Edge *readEdge(int origin, int destiny, double weight) {
    Edge *edge = newEdge();

    edge->origin = origin;
    edge->destiny = destiny;
    edge->weight = weight;

    return edge;
}

void printEdge(Edge edge) {
    printf("%d -[%.2lf]-> %d\n", edge.origin, edge.weight, edge.destiny);
}
