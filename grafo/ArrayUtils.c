#include "headers/ArrayUtils.h"

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

/*
 * Verifica se o 'char' [needle] existe na 'string' [haystack].
 *
 * Se exixtir, retorna 1;
 * Se não existir, retorna 0.
 * */
int arrayContainsChar(char needle, char *haystack) {
	int lenght = (int) strlen(haystack);

	for (int i = 0; i < lenght; i++) {
		if (needle == haystack[i]) {
			return 1;
		}
	}

	return 0;
}

/*
 * Verifica se o 'int' [needle] existe no vetor [haystack] de tamanho [haystackSize].
 *
 * Se exixtir, retorna 1;
 * Se não existir, retorna 0.
 * */
int arrayContainsInteger(int needle, const int *haystack, int haystackSize) {
	for (int i = 0; i < haystackSize; i++) {
		if (needle == haystack[i]) {
			return 1;
		}
	}

	return 0;
}

/*
 * Retorna uma matriz de 'float' com [size] linhas e [size] colunas.
 *
 * Todos os valores são iniciados com '0.0'.
 * */
float **newMatrixFloat(int size) {
	float **matrix = (float **) malloc(size * sizeof(float *));

	for (int i = 0; i < size; i++) {
		matrix[i] = (float *) malloc(size * sizeof(float));
		for (int j = 0; j < size; ++j) {
			matrix[i][j] = (float) 0.0;
		}
	}

	return matrix;
}

/*
 * Retorna um vetor de 'int' de tamanho [size].
 *
 * Todos os valores são iniciados com '0'.
 * */
int *newIntegerArray(int size) {
	int *integerArray = (int *) malloc(size * sizeof(int));

	for (int i = 0; i < size; i++) {
		integerArray[i] = 0;
	}

	return integerArray;
}

/*
 * Retorna o menor 'float' diferente de '0.0' de um vetor [array], o qual tem tamanho [arraySize].
 *
 * Ignora os valores de índices presentes em [blackList], o qual tem tamanho [blackListSize].
 *
 * Se não encontrar nenhum valor diferente de '0.0', retorna '0.0'.
 * */
int getMinNonZeroWithBlackListArrayFloat(const float *array, int arraySize, const int *blackList, int blackListSize) {
	float minValue = (float) 0.0;
	int minIndex = -1;

	for (int i = 0; i < arraySize; i++) {
		if (!arrayContainsInteger(i, blackList, blackListSize)) {
			if (minValue == 0.0 || (array[i] != 0.0 && array[i] < minValue)) {
				minValue = array[i];
				minIndex = i;
			}
		}
	}

	return minIndex;
}