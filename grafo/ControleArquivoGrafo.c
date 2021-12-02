#include "headers/ControleArquivoGrafo.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define LINE_MAX_LENGTH 255
#define DIRETORIO_ARQUIVO_ENTRADA "../entrada/entrada.txt"
#define DIRETORIO_ARQUIVO_SAIDA "../saida/"
#define FILE_NAME_MAX_LENGTH 31
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

void writeNextVerticeOnFile(FILE *outputFile, Vertice *vertice) {
    fprintf(outputFile, "%d%s%s%s", vertice->value->codigo, DELIMITER, vertice->value->nome, DELIMITER);
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

void writeGrafoEdgesOnFile(Grafo *grafo) {
    int nomeArquivoSaidaLength = strlen(DIRETORIO_ARQUIVO_SAIDA) + FILE_NAME_MAX_LENGTH + 1;
    char *nomeArquivoSaida = (char *) malloc(nomeArquivoSaidaLength * sizeof(char));
    sprintf(nomeArquivoSaida, "%s%s", DIRETORIO_ARQUIVO_SAIDA, grafo->label);

    FILE *outputFile = fopen(nomeArquivoSaida, "w");

    for (int i = 0; i < grafo->size; ++i) {
        for (int j = 0; j < grafo->size; ++j) {
            if (grafo->edges[i][j] != 0.0) {
                writeNextVerticeOnFile(outputFile, grafo->vertices[i]);
                writeNextVerticeOnFile(outputFile, grafo->vertices[j]);
                fprintf(outputFile, "%.2f\n", grafo->edges[i][j]);
            }
        }
    }
    fprintf(outputFile, "%.2f", getTotalTwoWayEdgeWeight(grafo));

    fclose(outputFile);
}
