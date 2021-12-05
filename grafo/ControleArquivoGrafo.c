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

void readNextEdgesFromFile(FILE *inputFile, Grafo *grafo, int index);

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

/*
 * Lê a próxima linha de [inputFile] e preencha dados de 'Cidade'.
 *
 * Retorna nova 'Cidade'.
 * */
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

/*
 * Retorna um 'Vertice' de índice [index] e com valor lido de [inputFile].
 * */
Vertice *readNextVerticeFromFile(FILE *inputFile, int index) {
    return readVertice(index, readNextCidadeFromFile(inputFile));
}

/*
 * Lê as arestas de um vértice de índice [index] de [inputFile] e insere em [grafo].
 * */
void readNextEdgesFromFile(FILE *inputFile, Grafo *grafo, int index) {
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

/*
 * Imprime um 'Vertice' no arquivo [outputFile].
 * */
void writeNextVerticeOnFile(FILE *outputFile, Vertice *vertice) {
    fprintf(outputFile, "%d%s%s%s", vertice->value->codigo, DELIMITER, vertice->value->nome, DELIMITER);
}

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

/*
 * Lê e retorna um 'Grafo' de um arquivo.
 * */
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
        readNextEdgesFromFile(inputFile, grafo, index);
        index++;
    }

    fclose(inputFile);
    return grafo;
}

/*
 * Imprime as aréstas de um 'Grafo' num arquivo.
 * */
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
