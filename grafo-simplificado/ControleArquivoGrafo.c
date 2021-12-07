#include "headers/ControleArquivoGrafo.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define DIRETORIO_ARQUIVO_ENTRADA "entrada/entrada.txt"
#define DIRETORIO_ARQUIVO_SAIDA "saida/"
#define FILE_NAME_MAX_LENGTH 15
#define CIDADE_MAX_STRING_LENGTH 64
#define EDGE_MAX_STRING_LENGTH 8
#define DELIMITER ";"

#define INFO_ABRIR_ARQUIVO_ENTRADA "\n\tINFO: Abrindo arquivo de entrada\n"
#define INFO_LER_GRAFO_ARQUIVO "\n\tINFO: Lendo nova instância de 'Grafo' de arquivo\n"
#define INFO_LER_VERTICE_ARQUIVO "\n\tINFO: Lendo vértices de arquivo\n"
#define INFO_LER_ARESTA_ARQUIVO "\n\tINFO: Lendo arestas de arquivo\n"
#define INFO_CRIAR_ARQUIVO_SAIDA "\n\tINFO: Criando arquivo de saida\n"
#define INFO_IMPRIMIR_GRAFO_ARQUIVO "\n\tINFO: Imprimindo 'Grafo' em arquivo\n"
#define SUCCESS_LER_GRAFO_ARQUIVO "\n\tSUCCESS: Nova instância de 'Grafo' iniciado com sucesso\n"
#define SUCCESS_IMPRIMIR_GRAFO_ARQUIVO "\n\tSUCCESS: Sucesso ao imprimir de 'Grafo' em arquivo\n"
#define ERRO_ABRIR_ARQUIVO_ENTRADA "\n\tERRO: Falha ao tentar abrir arquivo de entrada\n"
#define ERRO_CRIAR_ARQUIVO "\n\tERRO: Falha na criação de arquivo\n"

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

int getLineLenghtEdges(int edgeAmount);

Cidade *readNextCidadeFromFile(FILE *inputFile);

Vertice *readNextVerticeFromFile(FILE *inputFile, int index);

int readAllVerticesFromFile(FILE *inputFile, Grafo *grafo);

void readNextEdgesFromFile(FILE *inputFile, Grafo *grafo, int index);

void readAllEdgesFromFile(FILE *inputFile, Grafo *grafo);

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

/*
 * Retorna o comprimento máximo de uma linha do arquivo responsável por guardar as arestas do grafo
 * */
int getLineLenghtEdges(int edgeAmount) {
	return ((EDGE_MAX_STRING_LENGTH + (int) strlen(DELIMITER)) * edgeAmount) + 1;
}

/*
 * Lê a próxima linha de [inputFile] e preencha dados de 'Cidade'.
 *
 * Retorna nova 'Cidade'.
 * */
Cidade *readNextCidadeFromFile(FILE *inputFile) {
	Cidade *cidade = newCidade();
	char *line = (char *) malloc(CIDADE_MAX_STRING_LENGTH * sizeof(char));
	char *ptr;

	if (cidade == NULL) {
		return NULL;
	}

	fscanf(inputFile, " %[^\n]%*c", line);
	ptr = strtok(line, DELIMITER);
	cidade->codigo = atoi(ptr);

	ptr = strtok(NULL, DELIMITER);
	strcpy(cidade->nome, ptr);

	free(line);

	return cidade;
}

/*
 * Retorna um 'Vertice' de índice [index] e com valor lido de [inputFile].
 * */
Vertice *readNextVerticeFromFile(FILE *inputFile, int index) {
	Cidade *cidade = readNextCidadeFromFile(inputFile);

	if (cidade == NULL) {
		return NULL;
	}

	return readVertice(index, cidade);
}

/*
 * Lê os 'Vertice's lidos do arquivo [inputFile] e os insere em [grafo].
 * */
int readAllVerticesFromFile(FILE *inputFile, Grafo *grafo) {
	printf(INFO_LER_VERTICE_ARQUIVO);

	int index = 0;
	int i;

	for (i = 0; i < grafo->size; ++i) {
		Vertice *vertice = readNextVerticeFromFile(inputFile, index);

		if (vertice == NULL) {
			return 0;
		}

		grafo->vertices[i] = vertice;
		index++;
	}

	return 1;
}

/*
 * Lê as arestas de um vértice de índice [index] de [inputFile] e insere em [grafo].
 * */
void readNextEdgesFromFile(FILE *inputFile, Grafo *grafo, int index) {
	char *line = (char *) malloc(getLineLenghtEdges(grafo->size) * sizeof(char));
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
 * Lê as arestas lidss do arquivo [inputFile] e os insere em [grafo].
 * */
void readAllEdgesFromFile(FILE *inputFile, Grafo *grafo) {
	printf(INFO_LER_ARESTA_ARQUIVO);

	int index = 0;
	int i;

	for (i = 0; i < grafo->size; ++i) {
		readNextEdgesFromFile(inputFile, grafo, index);
		index++;
	}
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
	printf(INFO_ABRIR_ARQUIVO_ENTRADA);

	FILE *inputFile = fopen(DIRETORIO_ARQUIVO_ENTRADA, "r");
	int size;

	if (inputFile == NULL) {
		printf(ERRO_ABRIR_ARQUIVO_ENTRADA);
		return NULL;
	}

	printf(INFO_LER_GRAFO_ARQUIVO);
	fscanf(inputFile, " %d", &size);
	Grafo *grafo = newGrafo("Grafo", size);
	int condition;

	if (grafo == NULL) {
		return NULL;
	}

	condition = readAllVerticesFromFile(inputFile, grafo);
	if (!condition) {
		return NULL;
	}
	readAllEdgesFromFile(inputFile, grafo);
	printf(SUCCESS_LER_GRAFO_ARQUIVO);

	fclose(inputFile);
	return grafo;
}

/*
 * Imprime as aréstas de um 'Grafo' num arquivo.
 * */
void writeGrafoEdgesOnFile(Grafo *grafo) {
	printf(INFO_CRIAR_ARQUIVO_SAIDA);

	int nomeArquivoSaidaLength = strlen(DIRETORIO_ARQUIVO_SAIDA) + FILE_NAME_MAX_LENGTH + 1;
	char *nomeArquivoSaida = (char *) malloc(nomeArquivoSaidaLength * sizeof(char));
	sprintf(nomeArquivoSaida, "%s%s", DIRETORIO_ARQUIVO_SAIDA, grafo->label);
	FILE *outputFile = fopen(nomeArquivoSaida, "w");
	int row, column;

	if (outputFile == NULL) {
		printf(ERRO_CRIAR_ARQUIVO);
		return;
	}

	printf(INFO_IMPRIMIR_GRAFO_ARQUIVO);
	for (row = 0; row < grafo->size; ++row) {
		for (column = 0; column < grafo->size; ++column) {
			if (grafo->edges[row][column] != 0.0) {
				writeNextVerticeOnFile(outputFile, grafo->vertices[row]);
				writeNextVerticeOnFile(outputFile, grafo->vertices[column]);
				fprintf(outputFile, "%.2f\n", grafo->edges[row][column]);
			}
		}
	}
	fprintf(outputFile, "%.2f", getTotalTwoWayEdgeWeight(grafo));
	printf(SUCCESS_IMPRIMIR_GRAFO_ARQUIVO);

	fclose(outputFile);
}
