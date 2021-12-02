#include "headers/ControleArquivoGrafo.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define LINE_MAX_LENGTH 255
#define DIRETORIO_ARQUIVO_ENTRADA "../entrada/entrada.txt"
#define DELIMITER ";"

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

Cidade *readNextCidadeFromFile(FILE *inputFile);

Vertice *readNextVerticeFromFile(FILE *inputFile, int index);

void readNextVerticeEdgesFromFile(FILE *inputFile, Grafo *grafo, int index);

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

Cidade *readNextCidadeFromFile(FILE *inputFile) {
    Cidade *cidade = newCidade();
    char *line = (char *) malloc((LINE_MAX_LENGTH + 1) * sizeof(char));
    char *ptr;

    fscanf(inputFile, " %[^\n]%*c", line);
    ptr = strtok(line, DELIMITER);
    cidade->codigo = atoi(ptr);

    ptr = strtok(NULL, DELIMITER);
    strcpy(cidade->nome, ptr);

    return cidade;
}

Vertice *readNextVerticeFromFile(FILE *inputFile, int index) {
    return readVertice(index, readNextCidadeFromFile(inputFile));
}

void readNextVerticeEdgesFromFile(FILE *inputFile, Grafo *grafo, int index) {
    char *line = (char *) malloc((LINE_MAX_LENGTH + 1) * sizeof(char));
    char *ptr;
    int counter = 0;

    fscanf(inputFile, " %[^\n]%*c", line);
    ptr = strtok(line, DELIMITER);
    do {
        grafo->edges[index][counter] = (float) atof(ptr);
        ptr = strtok(NULL, DELIMITER);
        counter++;
    } while (counter < grafo->size);

    free(line);
    free(ptr);
}

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

Grafo *readGrafoFromFile() {
    FILE *inputFile = fopen(DIRETORIO_ARQUIVO_ENTRADA, "r");
    int size;

    fscanf(inputFile, " %d", &size);

    Grafo *grafo = newGrafo("Grafo", size);

    int index = 0;
    for (int i = 0; i < grafo->size; i++) {
        grafo->vertices[i] = readNextVerticeFromFile(inputFile, index);
        index++;
    }

    index = 0;
    for (int i = 0; i < grafo->size; i++) {
        readNextVerticeEdgesFromFile(inputFile, grafo, index);
        index++;
    }

    fclose(inputFile);
    return grafo;
}
