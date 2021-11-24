#include "headers/ControleArquivoGrafo.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define QTD_CID 100
#define DIRETORIO_ARQUIVO_ENTRADA "../entrada/entrada.txt"

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

double geraDistancia(int linha, int coluna);

double *gerarDistancias();

void imprimirCidades(FILE *arq_entrada);

void imprimirMatriz(FILE *arq_entrada, double *distancias);

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

double geraDistancia(int linha, int coluna) {
    double r;

    /*
     * Para garantir que o grafo ser� conexo garantirei que sempre haver� arestas entre vertices que o codigo diferem de 1
     * A distancia dessas arestas ser� um numero aleat�rio entre 10 e 110
     */
    if (coluna - linha == 1) {
        return (getRandomDecimal() + 0.1) * 100;
    }

    /*
     * Para os demais gero um aleat�rio entre 0 e 1. Se for menor que 0.5 n�o haver� aresta entre eles
     * caso contr�rio haver� aresta e a distancia da aresta ser� dada pelo numero gerado * 200 - 90, ou seja, ser� algo entre 10 e 110.
     */
    r = getRandomDecimal();
    if (r < 0.5) {
        return 0.0;
    }
    return r * 200 - 90;
}

/*
 * Vou gerar as distancias.
 * Como o grafo n�o ser� direcional e n�o tenho arestas ligando um vertice a ele mesmo
 * teria uma matriz de adjacencia na qual a diagonal principal � toda de zeros
 * e os elementos acima da diagonal s�o iguais aos abaixo, isso �, o elemento A(l,c) = A(c,l)
 * Assim vou gerar apenas os elementos que ficam acima da diagonal principal e armazenar num vetor
 * Esse vetor ter� seu tamanho dados por (qtd*qtd-qtd)/2 (resultado de uma somatoria onde a primeira lina tem qtd-1 elementos
 * e vai diminuindo de um em um at� que a �ltima tem zero.
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
 * Nesse la�o imprimo as cidades. Os codigos das cidades ser�o inteiros sequenciais de zero a qtd-1
 * */
void imprimirCidades(FILE *arq_entrada) {
    Cidade cid;

    fprintf(arq_entrada, "%d\n", QTD_CID);
    for (int i = 0; i < QTD_CID; i++) {
        cid.nome = getRandomWord();
        cid.codigo = i; //geraCodigo(usado, qtd);
        fprintf(arq_entrada, "%d;%s\n", cid.codigo, cid.nome);
    }
}

/*
 * Nos la�os abaixo imprimo a matriz de adjacencias completa, inclusive diagonal principal e elementos abaixo dela
 * Para achar no vetor a distancia entre elementos usei a formula que desenvolvi observado que a primeira linha tem qtd-1 elementos no vetor,
 * a segunda linha qtd-2 e assim sucessivamente at� que a �ltima linha tem zero.
 * Assim, vi que para obter o indice do primeiro elemento da linha no vetor bastava resolver uma soma de PA e que a partir dele
 * bastava somar a coluna menos linha -1. Vou tirar uma foto da dedu��o e colocar nesse diret�rio para referencia futura se necess�rio
 */
void imprimirMatriz(FILE *arq_entrada, double *distancias) {
    for (int l = 0; l < QTD_CID; l++) {
        for (int c = 0; c < QTD_CID - 1; c++) {
            if (l == c) {
                fprintf(arq_entrada, "%.2lf;", 0.0);
            } else if (l < c) {
                fprintf(arq_entrada, "%.2lf;", distancias[l * QTD_CID - (l * l + l) / 2 + c - l - 1]);
            } else {
                fprintf(arq_entrada, "%.2lf;", distancias[c * QTD_CID - (c * c + c) / 2 + l - c - 1]);
            }
        }

        if (l == (QTD_CID - 1)) {
            fprintf(arq_entrada, "%.2lf\n", 0.0);
        } else {
            fprintf(arq_entrada, "%.2lf\n", distancias[l * QTD_CID - (l * l + l) / 2 + QTD_CID - l]);
        }
    }
}

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

void criaArquivoEntrada() {
    FILE *arq_entrada = fopen(DIRETORIO_ARQUIVO_ENTRADA, "w");
    double *distancias = gerarDistancias();

    imprimirCidades(arq_entrada);
    imprimirMatriz(arq_entrada, distancias);
}