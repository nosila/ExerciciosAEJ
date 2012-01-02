#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma region data_structure
typedef struct _node Node;

struct _node{
	int value;
	Node * next;
	Node * prev;
};

Node * _head;
Node * _tail;
#pragma endregion data_structure

#pragma region methods_signature
/************
*	Constructors n Destructors
*************/
Node * Node_new(void);
void Node_delete( Node * node);
Node * newNode(int value, Node * prev, Node * next );

/************
*	Data operations
*************/
void enqueue(int value);
void dequeue();
void removeNode(Node * node);
void removeAll();

/************
*	Misc.
*************/
void queueToString();
void pause();
#pragma endregion methods_signature

int main(){

	int value = 0;
	_head = NULL;
	_tail = NULL;

	printf("\t**** QUEUE **** \n");
	do{
		printf("\nInsira um numero (0 para terminar) > ");
		scanf("%d", &value);
		
		if(value != 0)
			enqueue(value);
	}while(value);
	
	queueToString();

	printf("\n\tTodos os numeros serao eliminados!\n");
	removeAll();
	queueToString();
	
	pause();
	return 0;
}

#pragma region method_implementations
Node * Node_new(void) {
	Node * novo;

	if ((novo = ( Node*)malloc(sizeof(Node))) == NULL) { 
		exit(1);
	}
	//memset(novo,NULL,sizeof( Node));

	return novo;
}

void Node_delete( Node * node) {

	node->value = -1;

	//memset(node,0xdd,sizeof( Node));
	free(node);
}

Node * newNode(int value, Node * prev, Node * next ){
	Node * newNode = Node_new();

	newNode->value=value;
	newNode->next = next;
	newNode->prev = prev;

	return newNode;
}

void enqueue(int value){
	Node * n = newNode(value, NULL,_head);

	if(_head != NULL){ //caso haja mais do que 1 no na lista
		_head->prev = n;
	}

	_head = n;


	if(_tail == NULL)
		_tail = n;

}

void dequeue(){
	Node * n = _tail;
	if(_tail == NULL)
		return;

	if(_tail->prev == NULL){
		_tail = NULL;
		_head = NULL;
	}
	else{
		_tail = _tail->prev;
		_tail->next = NULL;
	}
	Node_delete(n);
}

void queueToString(){
	Node * current = _head;

	printf("\nQueue [ ");
	while(current != NULL){
		printf("%d ",current->value);
		current = current->next;
	}
	printf("]\n");
}

void removeNode(Node * node){
	if(node == NULL)
		return;

	if(node == _head){
		_head = node->next;
		_head->prev = NULL;
	}
	else if(node == _tail){
		_tail = node->prev;
		_tail->next = NULL;
	}
	else //significa que o no esta no meio da lista
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
	}


	Node_delete(node);
}

void removeAll(){
	while(_tail != NULL)
		dequeue();
}

void pause(){
	printf("Press any key to continue . . .");
	scanf("%c");
}
#pragma endregion method_implementations
