#include <stdio.h>

#include "headers/GeradorArquivo.h"
#include "headers/ControleArquivoGrafo.h"
#include "headers/Grafo.h"

#define NOME_GRAFO_SAIDA "viasAsfaltadas"

int main(int argc, char *argv[]) {
    criaArquivoEntrada();

    Grafo *grafo = readGrafoFromFile();
    Grafo *min = getMinimumSpanningTree(grafo);

    min->label = NOME_GRAFO_SAIDA;

    writeGrafoEdgesOnFile(min);

    free(grafo);
    free(min);
}