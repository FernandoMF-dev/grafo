#include <locale.h>

#include "headers/GeradorArquivo.h"
#include "headers/ControleArquivoGrafo.h"
#include "headers/Grafo.h"

#define NOME_GRAFO_SAIDA "viasAsfaltadas"

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");

	criaArquivoEntrada();

	Grafo *grafo = readGrafoFromFile();
	if (grafo == NULL) {
		return 0;
	}

	Grafo *min = getMinimumSpanningTreeGrafo(grafo);
	if (min == NULL) {
		return 0;
	}

	min->label = NOME_GRAFO_SAIDA;
	writeGrafoEdgesOnFile(min);

	free(grafo);
	free(min);
}