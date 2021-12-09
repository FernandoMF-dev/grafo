#include "headers/Grafo.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define INFO_CRIAR_ARVORE_GERADORA_MINIMA "\n\tINFO: Gerando Árvore Geradora Mínima\n"
#define DEBUG_CRIAR_ARVORE_GERADORA_MINIMA "\n\tDEBUG: Gerando Árvore Geradora Mínima: %.2f%%\n"
#define SUCCESS_CRIAR_ARVORE_GERADORA_MINIMA "\n\tSUCCESS: Árvore Geradora Mínima gerada com sucesso\n"
#define ERRO_FALHA_ALOCACAO "\n\tERRO: Erro durante alocação de memória!\n"

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
	int i;

	if (minEdge == NULL) {
		return NULL;
	}

	for (i = 0; i < sourceIndexSize; ++i) {
		aux->originIndex = sourceIndexArray[i];
		grafoEdgesArray = grafo->edges[aux->originIndex];
		aux->destinyIndex = getMinNonZeroWithBlackListArrayFloat(grafoEdgesArray, grafo->size,
																 sourceIndexArray, sourceIndexSize);

		if (aux->destinyIndex != 0.0) {
			aux->weight = grafoEdgesArray[aux->destinyIndex];

			if (minEdge->weight == 0 || minEdge->weight > aux->weight) {
				minEdge->originIndex = aux->originIndex;
				minEdge->destinyIndex = aux->destinyIndex;
				minEdge->weight = aux->weight;
			}
		}
	}

	free(aux);
	return minEdge;
}

/*
 * Copia os 'Vertice's do 'Grafo' [originIndex] e cola em [target]
 * */
void copyVerticesGrafo(Grafo *target, Grafo *origin) {
	int i;
	for (i = 0; i < target->size; ++i) {
		target->vertices[i] = origin->vertices[i];
	}
}

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

/*
 * Inicializa e retorna uma nova instância de 'Grafo'.
 * */
Grafo *newGrafo(char *label, int size) {
	Grafo *grafo = (Grafo *) malloc(sizeof(Grafo));

	if (grafo == NULL) {
		printf(ERRO_FALHA_ALOCACAO);
		return NULL;
	}

	grafo->label = label;
	grafo->size = size;
	grafo->vertices = newVerticeArray(size);
	grafo->edges = newRegularMatrixFloat(size);

	if (grafo->vertices == NULL || grafo->edges == NULL) {
		return NULL;
	}
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
	int i;

	for (i = 0; i < grafo->size; ++i) {
		printVertice(grafo->vertices[i]);
		printf("\n");
	}
}

/*
 * Imprime as arestas de um 'Grafo'.
 * */
void printEdgesGrafo(Grafo *grafo) {
	int row, column;

	for (row = 0; row < grafo->size; ++row) {
		for (column = 0; column < grafo->size; ++column) {
			if (grafo->edges[row][column] != 0.0) {
				printf("%s -[%.2f]-> %s\n", grafo->vertices[row]->value->nome, grafo->edges[row][column],
					   grafo->vertices[column]->value->nome);
			}
		}
	}
}

/*
 * Insere a aresta [edge] em [grafo].
 * */
void insertEdgeGrafo(Grafo *grafo, Edge *edge) {
	if (grafo->size <= edge->originIndex || grafo->size <= edge->destinyIndex || edge->originIndex < 0 ||
		edge->destinyIndex < 0) {
		return;
	}

	grafo->edges[edge->originIndex][edge->destinyIndex] = edge->weight;
}

/*
 * Insere a aresta [edge] em [grafo] como uma via dupla.
 * */
void insertTwoWayEdgeGrafo(Grafo *grafo, Edge *edge) {
	int origin = edge->originIndex;
	int destiny = edge->destinyIndex;

	insertEdgeGrafo(grafo, edge);
	edge->originIndex = destiny;
	edge->destinyIndex = origin;

	insertEdgeGrafo(grafo, edge);
	edge->originIndex = origin;
	edge->destinyIndex = destiny;
}

/*
 * Retorna um 'Grafo' com uma árvore geradora mínima de [originIndex]
 *
 * Não modifica [originIndex]
 * */
Grafo *getMinimumSpanningTreeGrafo(Grafo *origin) {
	printf(INFO_CRIAR_ARVORE_GERADORA_MINIMA);

	Grafo *minimumTree = newGrafo(origin->label, origin->size);

	if (minimumTree == NULL) {
		return NULL;
	}

	float progress = (float) 0.1;
	int *visitedIndex = newIntegerArray(minimumTree->size);
	int visitedIndexSize = 1;
	int row;

	copyVerticesGrafo(minimumTree, origin);

	for (row = 0; row < minimumTree->size; ++row) {
		Edge *edge = findMinimalEdgeGrafo(origin, visitedIndex, visitedIndexSize);

		if (edge == NULL) {
			return NULL;
		}

		if ((float) visitedIndexSize / (float) minimumTree->size >= progress) {
			printf(DEBUG_CRIAR_ARVORE_GERADORA_MINIMA, (progress * 100));
			progress += (float) 0.1;
		}

		insertTwoWayEdgeGrafo(minimumTree, edge);
		visitedIndex[row + 1] = edge->destinyIndex;
		visitedIndexSize++;
		free(edge);
	}
	printf(SUCCESS_CRIAR_ARVORE_GERADORA_MINIMA);

	free(visitedIndex);
	return minimumTree;
}

Stack *getMinimumPathGrafo(Grafo *grafo, int originIndex, int destinyIndex) {
	Stack *path = newStack("Caminho Mínimo");
	DijktraNode **dijkstra = prepareDijktraNodeArray(grafo->size);

	setOriginPathDijktra(dijkstra, originIndex);

	do {
		break;
	} while (!wasVisitedDijktra(dijkstra, destinyIndex));

	destroyDijktraNodeArray(dijkstra, grafo->size);
	return path;
}

/*
 * Retorna o tamanho total de todas as arestas de um grafo.
 * */
float getTotalEdgeWeightGrafo(Grafo *grafo) {
	float totalWeight = (float) 0.0;
	int row, column;

	for (row = 0; row < grafo->size; ++row) {
		for (column = 0; column < grafo->size; ++column) {
			totalWeight += grafo->edges[row][column];
		}
	}

	return totalWeight;
}

/*
 * Retorna o tamanho total de todas as arestas de um grafo assumindo que todas as arestas são de via dupla.
 * */
float getTotalTwoWayEdgeWeightGrafo(Grafo *grafo) {
	return getTotalEdgeWeightGrafo(grafo) / 2;
}
