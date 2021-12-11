#include "headers/InputUtils.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define CHAR_AFIRMATIVO "Ss1"
#define CHAR_NEGATIVO "Nn0"

#define ERRO_ENTRADA_INVALIDA "\n\tERRO: Entrada inválida!\n"

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

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