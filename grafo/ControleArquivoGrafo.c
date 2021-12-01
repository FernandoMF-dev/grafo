#include "headers/ControleArquivoGrafo.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define QTD_CID 100
#define LINE_MAX_LENGTH 255
#define DIRETORIO_ARQUIVO_ENTRADA "../entrada/entrada.txt"
#define DELIMITER ";"

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

double geraDistancia(int linha, int coluna);

double *gerarDistancias();

void imprimirCidades(FILE *inputFile);

void imprimirMatriz(FILE *inputFile, double *distancias);

Cidade *readNextCidadeFromFile(FILE *inputFile);

Vertice *readNextVerticeFromFile(FILE *inputFile, int index);

double *readNextVerticeEdgesFromFile(FILE *inputFile, int size);

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

double geraDistancia(int linha, int coluna) {
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
double *gerarDistancias() {
    int tamVetDist = (QTD_CID * QTD_CID - QTD_CID) / 2;
    double *distancias = (double *) malloc(tamVetDist * sizeof(double));
    int i = 0;

    for (int l = 0; l < QTD_CID; l++) {
        for (int c = l + 1; c < QTD_CID; c++) {
            distancias[i] = geraDistancia(l, c);
            i++;
        }
    }

    return distancias;
}

/*
 * Nesse laço imprimo as cidades. Os códigos das cidades serão inteiros sequenciais de zero a qtd-1
 * */
void imprimirCidades(FILE *inputFile) {
    Cidade cid;

    fprintf(inputFile, "%d\n", QTD_CID);
    for (int i = 0; i < QTD_CID; i++) {
        cid.nome = getRandomWord();
        cid.codigo = i; //geraCodigo(usado, qtd);
        fprintf(inputFile, "%d;%s\n", cid.codigo, cid.nome);
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
    for (int l = 0; l < QTD_CID; l++) {
        for (int c = 0; c < QTD_CID - 1; c++) {
            if (l == c) {
                fprintf(inputFile, "%.2lf;", 0.0);
            } else if (l < c) {
                fprintf(inputFile, "%.2lf;", distancias[l * QTD_CID - (l * l + l) / 2 + c - l - 1]);
            } else {
                fprintf(inputFile, "%.2lf;", distancias[c * QTD_CID - (c * c + c) / 2 + l - c - 1]);
            }
        }

        if (l == (QTD_CID - 1)) {
            fprintf(inputFile, "%.2lf\n", 0.0);
        } else {
            fprintf(inputFile, "%.2lf\n", distancias[l * QTD_CID - (l * l + l) / 2 + QTD_CID - l]);
        }
    }
}

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

double *readNextVerticeEdgesFromFile(FILE *inputFile, int size) {
    double *edges = (double *) malloc(size * sizeof(double));
    char *line = (char *) malloc((LINE_MAX_LENGTH + 1) * sizeof(char));
    char *ptr;
    int counter = 0;

    fscanf(inputFile, " %[^\n]%*c", line);
    ptr = strtok(line, DELIMITER);
    do {
        edges[counter] = atof(ptr);
        ptr = strtok(NULL, DELIMITER);
        counter++;
    } while (counter < size);

    return edges;
}

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

void criaArquivoEntrada() {
    FILE *inputFile = fopen(DIRETORIO_ARQUIVO_ENTRADA, "w");
    double *distancias = gerarDistancias();

    imprimirCidades(inputFile);
    imprimirMatriz(inputFile, distancias);

    fclose(inputFile);
}

Grafo *readGrafoFromFile() {
    FILE *inputFile = fopen(DIRETORIO_ARQUIVO_ENTRADA, "r");
    int size;

    fscanf(inputFile, " %d", &size);

    Grafo *grafo = newGrafo("Grafo", size);

    int index = 0;
    for (int i = 0; i < grafo->size; ++i) {
        grafo->vertices[i] = readNextVerticeFromFile(inputFile, index);
        index++;
    }

    for (int i = 0; i < grafo->size; ++i) {
        grafo->edges[i] = readNextVerticeEdgesFromFile(inputFile, grafo->size);
    }

    fclose(inputFile);
    return grafo;
}
