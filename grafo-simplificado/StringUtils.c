#include "headers/StringUtils.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

char VOGAIS[10] = "aeiouAEIOU";

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

char gerarLetraMaiuscula();

char gerarLetraMinuscula();

char gerarVogal();

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

/*
 * Retorna um 'char' com uma letra maiúscula aleatória
 * */
char gerarLetraMaiuscula() {
	return (char) (getRandomInteger(26) + 65);
}

/*
 * Retorna um 'char' com uma letra minúscula aleatória.
 * */
char gerarLetraMinuscula() {
	return (char) (getRandomInteger(26) + 97);
}

/*
 * Retorna um 'char' com uma vogal aleatória.
 *
 * A vogal pode ser tanto maiuscula quanto minuscula.
 * */
char gerarVogal() {
	return VOGAIS[getRandomInteger((int) strlen(VOGAIS))];
}

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

/*
 * Retorna uma 'string' de tamanho [lenght].
 *
 * O primeiro caractere será uma letra maiúscula;
 * A string não haverá duas consoantes consecutivas.
 * */
char *getRandomWord(int lenght) {
	int i;
	char *palavra = (char *) malloc((lenght + 1) * sizeof(char));

	palavra[0] = gerarLetraMaiuscula();
	for (i = 1; i < (lenght + 1); ++i) {
		if (arrayContainsChar(palavra[i - 1], VOGAIS)) {
			palavra[i] = gerarLetraMinuscula();
		} else {
			palavra[i] = gerarVogal();
		}
	}
	palavra[i] = '\0';

	return palavra;
}