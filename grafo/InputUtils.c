#include "headers/InputUtils.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define CHAR_AFIRMATIVO "sS"
#define CHAR_NEGATIVO "nN"

#define ERRO_ENTRADA_INVALIDA "\n\tERRO: Entrada inválida!\n"

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

int inputIntegerInterval(char *message, int minValue, int maxValue) {
	int input;

	while (1) {
		printf("\n%s", message);
		scanf(" %d", &input);

		if (minValue <= input && input >= maxValue) {
			return input;
		}

		printf(ERRO_ENTRADA_INVALIDA);
	}
}

int inputYesOrNo(char *message) {
	char input;

	while (1) {
		printf("\n%s", message);
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