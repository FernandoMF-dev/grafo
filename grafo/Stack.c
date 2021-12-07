#include "headers/Stack.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define ERRO_ALOCACAO "\n\tERRO: Falha de alocação de memória!\n"
#define ERRO_PILHA_VAZIA "\n\tERRO: Stack Vazia!\n"

// =-=-=-=-= MÉTODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

// =-=-=-=-= MÉTODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

Stack *newStack(char *label) {
	Stack *stack = (Stack *) malloc(sizeof(Stack));

	if (stack == NULL) {
		printf(ERRO_ALOCACAO);
	}

	stack->label = label;
	stack->top = NULL;
	stack->size = 0;

	return stack;
}

void insertStack(Stack *stack, Edge *value) {
	NodeStack *aux = (NodeStack *) malloc(sizeof(NodeStack));

	if (aux == NULL) {
		printf("\n\tERRO: Erro de alocação de nó!\n");
		return;
	}

	aux->value = value;
	aux->next = stack->top;
	stack->top = aux;
	stack->size++;
}

Edge *removeStack(Stack *stack) {
	NodeStack *aux = stack->top;
	Edge *backup;

	if (aux == NULL) {
		printf(ERRO_PILHA_VAZIA);
		return NULL;
	}

	stack->top = aux->next;
	aux->next = NULL;
	backup = aux->value;
	stack->size--;

	free(aux);
	return (backup);
}

void printStack(Stack *stack) {
	NodeStack *aux = stack->top;

	printf("\n%s", stack->label);
	while (aux != NULL) {
		printf("\n");
		printEdge(aux->value);
		aux = aux->next;
	}
	printf("\n");
}