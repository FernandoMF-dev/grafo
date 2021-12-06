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

	edge->origin = -1;
	edge->destiny = -1;
	edge->weight = (float) 0.0;

	return edge;
}

/*
 * Retorna uma nova instância de 'Edge' preenchido com os valores passados por parâmetro.
 * */
Edge *readEdge(int origin, int destiny, float weight) {
	Edge *edge = newEdge();

	if (edge == NULL) {
		return NULL;
	}

	edge->origin = origin;
	edge->destiny = destiny;
	edge->weight = weight;

	return edge;
}

/*
 * Imprimi uma struct 'Edge'
 * */
void printEdge(Edge edge) {
	printf("%d -[%.2f]-> %d\n", edge.origin, edge.weight, edge.destiny);
}
