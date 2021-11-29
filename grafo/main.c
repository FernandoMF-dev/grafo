#include <stdio.h>

#include "headers/ControleArquivoGrafo.h"
#include "headers/Grafo.h"

int main(int argc, char *argv[]) {
    criaArquivoEntrada();

    Grafo *grafo = newGrafo("Grafo", 5);

    printGrafo(grafo);
}