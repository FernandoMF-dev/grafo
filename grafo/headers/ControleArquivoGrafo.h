#include <stdio.h>
#include <stdlib.h>

#include "Cidade.h"
#include "StringUtils.h"
#include "RandomUtils.h"
#include "Grafo.h"

#ifndef GRAFO_CONTROLEARQUIVOGRAFO_H
#define GRAFO_CONTROLEARQUIVOGRAFO_H

void criaArquivoEntrada();

Grafo *readGrafoFromFile();

#endif //GRAFO_CONTROLEARQUIVOGRAFO_H