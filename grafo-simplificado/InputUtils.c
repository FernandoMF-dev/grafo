#include "headers/InputUtils.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define CHAR_AFIRMATIVO "Ss1"
#define CHAR_NEGATIVO "Nn0"

#define ERRO_ENTRADA_INVALIDA "\n\tERRO: Entrada inválida!\n"

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

/*
 * Imprime [message] e lê uma entrada de um inteiro entre [minValue] e [maxValue] inclusos.
 *
 * Repita a leitura até que uma entrada válida seja recebida.
 *
 * Retorna o valor lido.
 * */
int inputIntegerInterval(char *message, int minValue, int maxValue) {
	int input;

	while (1) {
		printf("\n%s (%d - %d): ", message, minValue, maxValue);
		scanf(" %d", &input);

		if (minValue <= input && input <= maxValue) {
			return input;
		}

		printf(ERRO_ENTRADA_INVALIDA);
	}
}

/*
 * Imprime [message] e lê uma entrada de "Afirmativo" ou "Negativo".
 *
 * Repita a leitura até que uma entrada válida seja recebida.
 *
 * Se a entrada corresponder a "Afirmativo", retorna 1;
 * Se a entrada corresponder a "Negativo", retorna 1;
 * */
int inputYesOrNo(char *message) {
	char input;

	while (1) {
		printf("\n%s", message);
		printf("\n%c - Sim", CHAR_AFIRMATIVO[0]);
		printf("\n%c - Nao", CHAR_NEGATIVO[0]);
		printf("\nRESPOSTA: ");
		scanf(" %c", &input);

		if (arrayContainsChar(input, CHAR_AFIRMATIVO)) {
			return 1;
		}

		if (arrayContainsChar(input, CHAR_NEGATIVO)) {
			return 0;
		}

		printf(ERRO_ENTRADA_INVALIDA);
	}
}
