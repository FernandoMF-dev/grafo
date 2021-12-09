#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef GRAFO_ARRAYUTILS_H
#define GRAFO_ARRAYUTILS_H

int arrayContainsChar(char needle, char *haystack);

int arrayContainsInteger(int needle, const int *haystack, int haystackSize);

float **newRegularMatrixFloat(int size);

float **newMatrixFloat(int rows, int colmuns);

int **newIntegerMatrix(int rows, int colmuns);

int *newIntegerArray(int size);

int getMinNonZeroWithBlackListArrayFloat(const float *array, int arraySize,
										 const int *blackList, int blackListSize);

#endif //GRAFO_ARRAYUTILS_H
