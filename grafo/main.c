#include <locale.h>

#include "headers/GeradorArquivo.h"
#include "headers/ControleArquivoGrafo.h"
#include "headers/Grafo.h"
#include "headers/Stack.h"

int main(int argc, char *argv[]) {
//	criaArquivoEntrada();

	Grafo *grafo = readGrafoFromFile();
	if (grafo == NULL) {
		return 0;
	}

	Stack *minimunPath = getMinimumPathGrafo(grafo, 4, 1);
	printStack(minimunPath);

	free(grafo);
	free(minimunPath);

	return 0;
}