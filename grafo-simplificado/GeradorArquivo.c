#include "headers/GeradorArquivo.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define QUANTIDADE_CIDADES 25
#define TAMANHO_NOME_CIDADE 10

#define DIRETORIO_ARQUIVO_ENTRADA "../entrada/entrada.txt"
#define DELIMITER ";"

#define INFO_CRIAR_ARQUIVO "\n\tINFO: Criando arquivo de entrada\n"
#define INFO_PREENCHER_ARQUIVO "\n\tINFO: Preenchendo arquivo de entrada\n"
#define SUCCESS_PREENCHER_ARQUIVO "\n\tSUCCESS: Arquivo de entrada criado com sucesso\n"
#define ERRO_CRIAR_ARQUIVO "\n\tERRO: Falha na criação de arquivo\n"

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=


double gerarDistancia(int linha, int coluna);

double *gerarDistanciasCidade();

void imprimirCidades(FILE *inputFile);

void imprimirMatriz(FILE *inputFile, double *distancias);

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

double gerarDistancia(int linha, int coluna) {
	double r;

	/*
	 * Para garantir que o grafo será conexo garantirei que sempre haverá arestas entre vertices que o código diferem de 1
	 * A distancia dessas arestas será um numero aleatório entre 10 e 110
	 */
	if (coluna - linha == 1) {
		return (getRandomDecimal() + 0.1) * 100;
	}

	/*
	 * Para os demais, gero um aleatório entre 0 e 1. Se for menor que 0,5 não haverá aresta entre eles
	 * caso contrário haverá aresta e a distância da aresta será dada pelo número gerado * 200 – 90, ou seja, será algo entre 10 e 110.
	 */
	r = getRandomDecimal();
	if (r < 0.5) {
		return 0.0;
	}
	return r * 200 - 90;
}

/*
 * Vou gerar as distâncias.
 * Como o grafo não será direcional e não tenho arestas ligando um vértice a ele mesmo
 * teria uma matriz de adjacência onde a diagonal principal é toda de zeros
 * e os elementos acima da diagonal são iguais aos abaixo, isso é, o elemento A(l,c) = A(c,l)
 * Assim vou gerar apenas os elementos que ficam acima da diagonal principal e armazenar num vetor
 * Esse vetor terá o seu tamanho dados por (qtd*qtd-qtd)/2 (resultado de uma somatória onde a primeira lina tem qtd-1 elementos
 * e vai a diminuir a cada um até que a última tem zero.
 * */
double *gerarDistanciasCidade() {
	int tamVetDist = (QUANTIDADE_CIDADES * QUANTIDADE_CIDADES - QUANTIDADE_CIDADES) / 2;
	double *distancias = (double *) malloc(tamVetDist * sizeof(double));
	int i = 0;
	int row, column;

	for (row = 0; row < QUANTIDADE_CIDADES; ++row) {
		for (column = row + 1; column < QUANTIDADE_CIDADES; ++column) {
			distancias[i] = gerarDistancia(row, column);
			i++;
		}
	}

	return distancias;
}

/*
 * Nesse laço imprimo as cidades. Os códigos das cidades serão inteiros sequenciais de zero a qtd-1
 * */
void imprimirCidades(FILE *inputFile) {
	fprintf(inputFile, "%d\n", QUANTIDADE_CIDADES);

	int i;
	for (i = 0; i < QUANTIDADE_CIDADES; ++i) {
		Cidade *cidade = readCidade(i, getRandomWord(TAMANHO_NOME_CIDADE));
		fprintf(inputFile, "%d;%s\n", cidade->codigo, cidade->nome);
		free(cidade);
	}
}

/*
 * Nos laços abaixo imprimo a matriz de adjacências completa, inclusive diagonal principal e elementos abaixo dela
 * Para achar no vetor a distância entre elementos usei a fórmula que desenvolvi observado que a primeira linha tem qtd-1 elementos no vetor,
 * a segunda linha qtd-2 e assim sucessivamente até que a última linha tem zero.
 * Assim, vi que para obter o índice do primeiro elemento da linha no vetor bastava resolver uma soma de PA e que a partir dele
 * bastava somar a coluna menos linha -1. Vou fotografar a dedução e colocar nesse diretório para referência futura se necessário
 */
void imprimirMatriz(FILE *inputFile, double *distancias) {
	int row, column;

	for (row = 0; row < QUANTIDADE_CIDADES; ++row) {
		for (column = 0; column < QUANTIDADE_CIDADES - 1; ++column) {
			if (row == column) {
				fprintf(inputFile, "%.2lf%s", 0.0, DELIMITER);
			} else if (row < column) {
				fprintf(inputFile, "%.2lf%s",
						distancias[row * QUANTIDADE_CIDADES - (row * row + row) / 2 + column - row - 1],
						DELIMITER);
			} else {
				fprintf(inputFile, "%.2lf%s",
						distancias[column * QUANTIDADE_CIDADES - (column * column + column) / 2 + row - column - 1],
						DELIMITER);
			}
		}

		if (row == (QUANTIDADE_CIDADES - 1)) {
			fprintf(inputFile, "%.2lf\n", 0.0);
		} else {
			fprintf(inputFile, "%.2lf\n",
					distancias[row * QUANTIDADE_CIDADES - (row * row + row) / 2 + QUANTIDADE_CIDADES - row]);
		}
	}
}

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

/*
 * Cria um arquivo com vertices e arestas aleatórios para um grafo
 * */
void criaArquivoEntrada() {
	printf(INFO_CRIAR_ARQUIVO);
	FILE *inputFile = fopen(DIRETORIO_ARQUIVO_ENTRADA, "w");
	double *distancias = gerarDistanciasCidade();

	if (inputFile == NULL) {
		printf(ERRO_CRIAR_ARQUIVO);
		return;
	}

	printf(INFO_PREENCHER_ARQUIVO);
	imprimirCidades(inputFile);
	imprimirMatriz(inputFile, distancias);
	printf(SUCCESS_PREENCHER_ARQUIVO);

	free(distancias);
	fclose(inputFile);
}
