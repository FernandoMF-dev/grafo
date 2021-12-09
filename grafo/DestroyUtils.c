#include "headers/DestroyUtils.h"

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

void destroyDijkstraNodeArray(DijkstraNode **dijkstraNodeArray, int size) {
	if (dijkstraNodeArray == NULL) {
		return;
	}

	int i;
	for (i = 0; i < size; ++i) {
		free(dijkstraNodeArray[size]);
	}
	free(dijkstraNodeArray);
}