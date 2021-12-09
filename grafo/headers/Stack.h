#include <stdio.h>
#include <stdlib.h>

#include "Edge.h"

#ifndef GRAFO_STACK_H
#define GRAFO_STACK_H

typedef struct StackNode {
	Edge *value;
	struct StackNode *next;
} StackNode;

typedef struct Stack {
	char *label;
	int size;
	StackNode *top;
} Stack;

Stack *newStack(char *label);

void insertStack(Stack *stack, Edge *value);

Edge *removeStack(Stack *stack);

void printStack(Stack *stack);

#endif //GRAFO_STACK_H
