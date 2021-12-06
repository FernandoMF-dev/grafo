CC = gcc
flags = -c -Wall
CFLAGS = -lm
ARQUIVOS = *.o
OBJS = main.o Grafo.o GeradorArquivo.o ControleArquivoGrafo.o StringUtils.o ArrayUtils.o RandomUtils.o Vertice.o Edge.o Cidade.o
EXE = main
MAIN = main.c

all: main.o
	$(CC) $(OBJS) -o $(EXE) -lm
	./main

main.o: main.c Grafo.o GeradorArquivo.o ControleArquivoGrafo.o
	$(CC) $(flags) $(MAIN) $(CLFLAGS)

Grafo.o: Grafo.c ArrayUtils.o Cidade.o Vertice.o Edge.o
	$(CC) $(flags) Grafo.c

GeradorArquivo.o: GeradorArquivo.c Cidade.o StringUtils.o RandomUtils.o
	$(CC) $(flags) GeradorArquivo.c

ControleArquivoGrafo.o: ControleArquivoGrafo.c Cidade.o Grafo.o
	$(CC) $(flags) ControleArquivoGrafo.c

StringUtils.o: StringUtils.c ArrayUtils.o RandomUtils.o
	$(CC) $(flags) StringUtils.c

ArrayUtils.o: ArrayUtils.c
	$(CC) $(flags) ArrayUtils.c

RandomUtils.o: RandomUtils.c
	$(CC) $(flags) RandomUtils.c

Vertice.o: Vertice.c Cidade.o
	$(CC) $(flags) Vertice.c

Edge.o: Edge.c
	$(CC) $(flags) Edge.c

Cidade.o: Cidade.c
	$(CC) $(flags) Cidade.c

passos: main.c
	gcc -E main.c -o main.i
	gcc -S main.i -o main.s
	gcc -c main.s -o main.o
	gcc main.o Grafo.o GeradorArquivo.o ControleArquivoGrafo.o StringUtils.o ArrayUtils.o RandomUtils.o Vertice.o Edge.o Cidade.o -o -lm main

run:
	./main

listar:
	ls $(ARQUIVOS)

clean:
	rm -f *.o *.i *.s
	rm -f $(EXE)