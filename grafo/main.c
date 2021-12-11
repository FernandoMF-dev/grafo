#include "headers/GeradorArquivo.h"
#include "headers/ControleArquivoGrafo.h"
#include "headers/Grafo.h"
#include "headers/Stack.h"
#include "headers/InputUtils.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define MENSAGEM_CIDADE_ORIGEM "Código da cidade de origem"
#define MENSAGEM_CIDADE_DESTINO "Código da cidade de destino"
#define MENSAGEM_CONTINUAR "Deseja continuar?"

// =-=-=-=-= FUNÇÃO PRINCIPAL =-=-=-=-=

int main(int argc, char *argv[]) {
	criaArquivoEntrada();

	Grafo *grafo = readGrafoFromFile();
	if (grafo == NULL) {
		return 0;
	}

	int origem;
	int destino;

	do {
		origem = inputIntegerInterval(MENSAGEM_CIDADE_ORIGEM, 0, grafo->size - 1);
		destino = inputIntegerInterval(MENSAGEM_CIDADE_DESTINO, 0, grafo->size - 1);

		Stack *shortestPath = getShortestPathGrafo(grafo, origem, destino);

		if (shortestPath != NULL) {
			printShortestPathGrafo(shortestPath);
			free(shortestPath);
		}

		printf("\n");
	} while (inputYesOrNo(MENSAGEM_CONTINUAR));

	free(grafo);

	return 0;
}
