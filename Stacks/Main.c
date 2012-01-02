#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma region data_structure
typedef struct _stackNode StackNode;

struct _stackNode{
	int value;
	StackNode * nextNode;
};

StackNode * _head;
#pragma endregion data_structure

#pragma region methods_signature
/************
*	Constructors n Destructors
*************/
StackNode * StackNode_new(void);
void StackNode_delete( StackNode * node);
StackNode * newNode(int value, StackNode * next);

/************
*	Data operations
*************/
void push(int value);
void pop();
void popAll();

/************
*	Misc.
*************/
void stackToString();
void pause();
void printMenu();
#pragma endregion methods_signature

int main(){
	int value = 0;

	do{
		printf("\nInsira um numero (0 para terminar) > ");
		scanf("%d", &value);
		
		if(value != 0)
			push(value);

		
	}while(value);
	
	stackToString();

	printf("\n\tTodos os numeros serao eliminados!\n");
	popAll();
	stackToString();
	
	pause();
}

#pragma region methods_implementation
StackNode * StackNode_new(void) {
	StackNode * novo;

	if ((novo = ( StackNode*)malloc(sizeof( StackNode))) == NULL) { 
		exit(1);
	}
	//memset(novo,0xda,sizeof( StackNode));

	return novo;
}

void StackNode_delete( StackNode * node) {

	node->value = -1;

	//memset(node,0xdd,sizeof( StackNode));
	free(node);
}

StackNode * newNode(int value, StackNode * next){
	StackNode * newNode = StackNode_new();

	newNode->value=value;
	newNode->nextNode = next;

	return newNode;
}

void push(int value){
	StackNode * novo = newNode(value, _head);


	_head = novo;
}

void pop(){
	StackNode * node;

	if(_head == NULL)
		return;

	node = _head;

	_head = _head->nextNode;

	StackNode_delete(node);
}

void popAll(){
	while(_head != NULL)
		pop();
}


void stackToString(){
	StackNode * current = _head;

	printf("\nStack [ ");
	while(current != NULL){
		printf("%d ",current->value);
		current = current->nextNode;
	}
	printf("]\n");
}

void pause(){
	printf("Press any key to continue . . .");
	scanf("%c");
}

void printMenu(){
	printf("*************");
	printf("      MENU        ");
	printf(" 1.Adicionar um elemento (push)        ");
	printf(" 2.Remover elemento do topo da pilha (pop)        ");
	printf(" 3.Remover todos os elementos da pilha");
	printf("*************");
}
#pragma endregion methods_implementation