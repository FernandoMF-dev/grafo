#include "headers/DestroyUtils.h"

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

void destroyDijktraNodeArray(DijkstraNode **dijktraNodeArray, int size) {
	if (dijktraNodeArray == NULL) {
		return;
	}

	int i;
	for (i = 0; i < size; ++i) {
		free(dijktraNodeArray[size]);
	}
	free(dijktraNodeArray);
}