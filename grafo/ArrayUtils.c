#include "headers/ArrayUtils.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

int arrayContainsChar(char needle, char *haystack) {
    int lenght = (int) strlen(haystack);

    for (int i = 0; i < lenght; ++i) {
        if (needle == haystack[i]) {
            return 1;
        }
    }

    return 0;
}

int arrayContainsInteger(int needle, const int *haystack, int haystackSize) {
    for (int i = 0; i < haystackSize; ++i) {
        if (needle == haystack[i]) {
            return 1;
        }
    }

    return 0;
}

float **newMatrixFloat(int size) {
    float **matrix = (float **) malloc(size * sizeof(float *));

    for (int i = 0; i < size; ++i) {
        matrix[i] = (float *) malloc(size * sizeof(float));
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = 0.0;
        }
    }

    return matrix;
}

int *newIntegerArray(int size) {
    int *integerArray = (int *) malloc(size * sizeof(int));

    for (int i = 0; i < size; ++i) {
        integerArray[i] = 0;
    }

    return integerArray;
}

int getMinNonZeroWithBlackListArrayFloat(const float *array, int arraySize, const int *blackList, int blackListSize) {
    float minValue = 0.0;
    int minIndex = -1;

    for (int i = 0; i < arraySize; ++i) {
        if (minValue == 0.0
            || (array[i] != 0.0
                && array[i] < minValue
                && !arrayContainsInteger(i, blackList, blackListSize))) {
            minValue = array[i];
            minIndex = i;
        }
    }

    if (minValue == 0.0) {
        return -1;
    }
    return minIndex;
}