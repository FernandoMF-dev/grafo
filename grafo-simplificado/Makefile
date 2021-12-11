CC = gcc
flags = -c -Wall
CFLAGS = -lm
ARQUIVOS = *.o
OBJS = main.o Grafo.o GeradorArquivo.o ControleArquivoGrafo.o Stack.o Edge.o Vertice.o DijkstraNode.o Cidade.o StringUtils.o InputUtils.o ArrayUtils.o RandomUtils.o
EXE = main
MAIN = main.c

all: main.o
	$(CC) $(OBJS) -o $(EXE) -lm
	./main

main.o: main.c Grafo.o GeradorArquivo.o ControleArquivoGrafo.o Stack.o InputUtils.o
	$(CC) $(flags) $(MAIN) $(CLFLAGS)

Grafo.o: Grafo.c ArrayUtils.o Cidade.o Vertice.o Edge.o Stack.o DijkstraNode.o
	$(CC) $(flags) Grafo.c

GeradorArquivo.o: GeradorArquivo.c Cidade.o StringUtils.o RandomUtils.o
	$(CC) $(flags) GeradorArquivo.c

ControleArquivoGrafo.o: ControleArquivoGrafo.c Cidade.o Grafo.o
	$(CC) $(flags) ControleArquivoGrafo.c

Stack.o: Stack.c Edge.o
	$(CC) $(flags) Stack.c

Edge.o: Edge.c Vertice.o
	$(CC) $(flags) Edge.c

Vertice.o: Vertice.c Cidade.o
	$(CC) $(flags) Vertice.c

DijkstraNode.o: DijkstraNode.c
	$(CC) $(flags) DijkstraNode.c

Cidade.o: Cidade.c
	$(CC) $(flags) Cidade.c

StringUtils.o: StringUtils.c ArrayUtils.o RandomUtils.o
	$(CC) $(flags) StringUtils.c

InputUtils.o: InputUtils.c ArrayUtils.o
	$(CC) $(flags) InputUtils.c

ArrayUtils.o: ArrayUtils.c
	$(CC) $(flags) ArrayUtils.c

RandomUtils.o: RandomUtils.c
	$(CC) $(flags) RandomUtils.c

passos: main.c
	gcc -E main.c -o main.i
	gcc -S main.i -o main.s
	gcc -c main.s -o main.o
	gcc main.o Grafo.o GeradorArquivo.o ControleArquivoGrafo.o Stack.o Edge.o Vertice.o DijkstraNode.o Cidade.o StringUtils.o InputUtils.o ArrayUtils.o RandomUtils.o -o -lm main

run:
	./main

listar:
	ls $(ARQUIVOS)

clean:
	rm -f *.o *.i *.s
	rm -f $(EXE)