#include "headers/Edge.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define ERRO_FALHA_ALOCACAO "\n\tERRO: Erro durante alocação de memória!\n"

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

/*
 * Inicializa e retorna uma nova instância de 'Edge'.
 * */
Edge *newEdge() {
	Edge *edge = (Edge *) malloc(sizeof(Edge));

	if (edge == NULL) {
		printf(ERRO_FALHA_ALOCACAO);
		return NULL;
	}

	edge->originIndex = -1;
	edge->destinyIndex = -1;
	edge->weight = (float) 0.0;
	edge->origin = NULL;
	edge->destiny = NULL;

	return edge;
}

/*
 * Retorna uma nova instância de 'Edge' preenchido com os valores passados por parâmetro.
 * */
Edge *readEdge(int originIndex, int destinyIndex, float weight) {
	Edge *edge = newEdge();

	if (edge == NULL) {
		return NULL;
	}

	edge->originIndex = originIndex;
	edge->destinyIndex = destinyIndex;
	edge->weight = weight;

	return edge;
}

/*
 * Retorna uma nova instância de 'Edge' preenchido com os valores passados por parâmetro.
 * */
Edge *readDetailEdge(Vertice *origin, Vertice *destiny, float weight) {
	Edge *edge = newEdge();

	if (edge == NULL) {
		return NULL;
	}

	edge->origin = origin;
	edge->destiny = destiny;
	edge->weight = weight;

	if (origin != NULL) {
		edge->originIndex = origin->index;
	}

	if (destiny != NULL) {
		edge->destinyIndex = destiny->index;
	}

	return edge;
}

/*
 * Imprimi uma struct 'Edge'
 * */
void printEdge(Edge *edge) {
	printf("%d -[%.2f]-> %d\n", edge->originIndex, edge->weight, edge->destinyIndex);
}

/*
 * Imprimi uma struct 'Edge' com os valores de seus vértices
 * */
void printDetailEdge(Edge *edge) {
	printVertice(edge->origin);
	printf(" -[%.2f]-> ", edge->weight);
	printVertice(edge->destiny);
}
