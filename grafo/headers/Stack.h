#include <stdio.h>
#include <stdlib.h>

#include "Edge.h"

#ifndef GRAFO_STACK_H
#define GRAFO_STACK_H

typedef struct NodeStack {
	Edge *value;
	struct NodeStack *next;
} NodeStack;

typedef struct Stack {
	char *label;
	int size;
	NodeStack *top;
} Stack;

Stack *newStack(char *label);

void insertStack(Stack *stack, Edge *value);

Edge *removeStack(Stack *stack);

void printStack(Stack *stack);

#endif //GRAFO_STACK_H
