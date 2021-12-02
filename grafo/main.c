#include <stdio.h>

#include "headers/GeradorArquivo.h"
#include "headers/ControleArquivoGrafo.h"
#include "headers/Grafo.h"

int main(int argc, char *argv[]) {
    criaArquivoEntrada();

    Grafo *grafo = readGrafoFromFile();
    Grafo *min = getMinimumSpanningTree(grafo);

    printGrafo(min);
    printf("\n\n\t%.2f | %.2f", getTotalTwoWayEdgeWeight(grafo), getTotalTwoWayEdgeWeight(min));

    free(grafo);
    free(min);
}