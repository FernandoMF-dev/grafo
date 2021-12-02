#include <stdio.h>
#include <stdlib.h>

#include "Cidade.h"
#include "Grafo.h"

#ifndef GRAFO_CONTROLEARQUIVOGRAFO_H
#define GRAFO_CONTROLEARQUIVOGRAFO_H

Grafo *readGrafoFromFile();

void writeGrafoEdgesOnFile(Grafo *grafo);

#endif //GRAFO_CONTROLEARQUIVOGRAFO_H