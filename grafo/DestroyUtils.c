#include "headers/DestroyUtils.h"

void destroyIntegerMatrix(int **matrix, int rows) {
	if (matrix == NULL) {
		return;
	}

	int i;
	for (i = 0; i < rows; ++i) {
		free(matrix[rows]);
	}
	free(matrix);
}