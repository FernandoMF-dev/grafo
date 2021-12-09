#include "headers/DestroyUtils.h"

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

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