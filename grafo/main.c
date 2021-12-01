#include <stdio.h>

#include "headers/ControleArquivoGrafo.h"
#include "headers/Grafo.h"

int main(int argc, char *argv[]) {
//    criaArquivoEntrada();

    Grafo *grafo = readGrafoFromFile();
    Grafo *min = getMinimumSpanningTree(grafo);

    printGrafo(min);

    free(grafo);
    free(min);
}