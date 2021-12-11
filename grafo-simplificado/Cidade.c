#include "headers/Cidade.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define MAX_NOME 15

#define ERRO_FALHA_ALOCACAO "\n\tERRO: Erro durante alocação de memória!\n"

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

/*
 * Inicializa e retorna uma nova instância de 'Cidade'.
 * */
Cidade *newCidade() {
	Cidade *cidade = (Cidade *) malloc(sizeof(Cidade));

	if (cidade == NULL) {
		printf(ERRO_FALHA_ALOCACAO);
		return NULL;
	}

	cidade->codigo = -1;
	cidade->nome = (char *) malloc(MAX_NOME * sizeof(char));

	if (cidade->nome == NULL) {
		printf(ERRO_FALHA_ALOCACAO);
		return NULL;
	}

	return cidade;
}

/*
 * Retorna uma nova instância de 'Cidade' preenchido com os valores passados por parâmetro.
 * */
Cidade *readCidade(int codigo, char *nome) {
	Cidade *cidade = newCidade();

	if (cidade == NULL) {
		printf(ERRO_FALHA_ALOCACAO);
		return NULL;
	}

	cidade->codigo = codigo;
	strcpy(cidade->nome, nome);

	return cidade;
}

/*
 * Imprimi uma struct 'Cidade'
 * */
void printCidade(Cidade *cidade) {
	if (cidade == NULL) {
		printf("[NULL]");
		return;
	}

	printf("{ 'codigo': %d, 'nome': '%s' }", cidade->codigo, cidade->nome);
}
