#include "headers/Stack.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define ERRO_ALOCACAO "\n\tERRO: Falha de alocação de memória!\n"
#define ERRO_PILHA_VAZIA "\n\tERRO: Stack Vazia!\n"

// =-=-=-=-= MÉTODOS PÚBLICOS =-=-=-=-=

/*
 * Inicializa e retorna uma nova instância de 'Stack'.
 * */
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

/*
 * Insere novo valor no topo de uma pilha [stack]
 * */
void insertStack(Stack *stack, Edge *value) {
	StackNode *aux = (StackNode *) malloc(sizeof(StackNode));

	if (aux == NULL) {
		printf("\n\tERRO: Erro de alocação de nó!\n");
		return;
	}

	aux->value = value;
	aux->next = stack->top;
	stack->top = aux;
	stack->size++;
}

/*
 * Remove e retorna o valor topo de uma pilha [stack]
 *
 * Se a pilha estiver vazia, retorna NULL
 * */
Edge *removeStack(Stack *stack) {
	StackNode *aux = stack->top;
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

/*
 * Imprimi uma struct 'Stack'
 * */
void printStack(Stack *stack) {
	StackNode *aux = stack->top;

	printf("\n%s", stack->label);
	while (aux != NULL) {
		printf("\n");
		printDetailEdge(aux->value);
		aux = aux->next;
	}
	printf("\n");
}