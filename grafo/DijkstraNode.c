#include "headers/DijkstraNode.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define STATUS_UNVISITED 0
#define STATUS_NEXT 1
#define STATUS_VISITED 2

#define ERRO_FALHA_ALOCACAO "\n\tERRO: Erro durante alocação de memória!\n"

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

/*
 * Inicializa e retorna uma nova instância de 'DijkstraNode'.
 * */
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

/*
 * Retorna um vetor de 'DijkstraNode' com tamanho [size] para ser usado num "Algorítimo de Dijkstra".
 *
 * Os vértices estarão ordenados de forma crescente no vetor.
 * */
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

/*
 * Prepara o vértice de índice [index] no vetor [dijkstra] para ser usado como ponto inicial no "Algorítimo de Dijkstra".
 * */
void setOriginPathDijkstra(DijkstraNode **dijkstra, int originIndex) {
	DijkstraNode *origin = dijkstra[originIndex];

	origin->status = STATUS_NEXT;
	origin->routeLenght = 0;
	origin->previousVertice = -1;
}

/*
 * Verifica se o vértice de índice [index] no vetor [dijkstra] já foi rotulado.
 *
 * Se sim, retorna 1.
 * Se não, retorna 0.
 * */
int isVisitedDijkstra(DijkstraNode **dijkstra, int index) {
	return dijkstra[index]->status == STATUS_VISITED;
}

/*
 * Muda o estado de um vértice de índice [index] no vetor [dijkstra] para "Pŕoximo".
 *
 * Vértices nesse estado poderão ser rotulados.
 * Vértices nesse estado poderão ter suas rotas modificadas quando forem rotulados.
 * Vértices nesse estado poderão ter suas rotas modificadas quando forem adjacentes a outros vértices sendo rotulados.
 * Vértices nesse estado não poderão ser usados em rotas de outros vértices.
 * */
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

/*
 * Retorna o índice do próximo vértice a ser rotulado vetor [dijkstra] de tamanho [dijkstraSize].
 *
 * Apenas vértices no estado de "Próximo" são considerados válidos.
 *
 * Se não encontrar qualquer vértice valido, retorna -1.
 * */
int findNextNodeToVisitDijkstra(DijkstraNode **dijkstra, int dijkstraSize) {
	DijkstraNode *next = dijkstra[0];
	DijkstraNode *aux;

	for (int i = 1; i < dijkstraSize; ++i) {
		aux = dijkstra[i];

		if (next->status == STATUS_VISITED || (aux->status == STATUS_NEXT && aux->routeLenght < next->routeLenght)) {
			next = aux;
		}
	}

	if (next->status == STATUS_VISITED) {
		return -1;
	}
	return next->verticeIndex;
}

/*
 * Verifica se é necessário alterar o vértice anterior na rota do vértice de índice [index] no vetor [dijkstra].
 *
 * O novo "vértice anterior" é o de índice [previous] e a distância entre eles é de [edgeWeight].
 * [previous] só será valido como caso ele seja um vértice "Rotulado"
 *
 * Caso [edgeWeight] mais o comprimento da rota de [previous] for maior que a rota de [index], realize a alteração.
 * Se não, manter [index] inalterado
 * */
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

/*
 * Muda o estado de um vértice de índice [index] no vetor [dijkstra] para "Rotulado".
 *
 * Vértices nesse estado não terão mais suas rotas modificadas.
 * Vértices nesse estado poderão ser usados em rotas de outros vértices.
 * */
void rotulateNodeDijkstra(DijkstraNode **dijkstra, int index) {
	dijkstra[index]->status = STATUS_VISITED;
}
