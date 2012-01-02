#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#pragma region data_structure
/************
*	Data structure
*************/
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
void addSorted(int value);
void addFirst(int value);
void addLast(int value);
void removeLast();
void removeFirst();
void removeNode(Node * node);
void removeAll();
int find(int value);

/************
*	Misc.
*************/
void toString();
void pause();
#pragma endregion methods_signature

int main(){

	int value = 0;
	_head = NULL;
	_tail = NULL;

	printf("\t**** DOUBLE LINKED LIST **** \n");
	do{
		printf("\nInsira um numero (0 para terminar) > ");
		scanf("%d", &value);
		
		if(value != 0){
			addSorted(value);
		toString();
		}

	}while(value);
	
	toString();

	printf("\nIndique o valor que deseja pesquisar na lista> ");
	scanf("%d", &value);
	
	switch(find(value)){
		case TRUE:
			printf("\n\tValor encontra-se na lista!\n\n"); break;
		case FALSE:
			printf("\n\tValor nao se encontra na lista...\n\n");break;
	}
	
	pause();
	return 0;
}

#pragma region method_implementations

/************
*	Method implementations
*************/

void Node_delete( Node * node) {

	node->value = -1;
	//memset(node,0xdd,sizeof( Node));
	free(node);
}

Node * Node_new(void) {
	Node * novo;

	if ((novo = ( Node*)malloc(sizeof(Node))) == NULL) { 
		exit(1);
	}
	//memset(novo,0xaa,sizeof( Node));

	return novo;
}


Node * newNode(int value, Node * prev, Node * next ){
	Node * newNode = Node_new();

	newNode->value=value;
	newNode->next = next;
	newNode->prev = prev;

	return newNode;
}

void addSorted(int value){
	Node * n = newNode(value, NULL,NULL);

	if(_head == NULL){
		_head = n;
		_tail = n;
	}
	else{
		Node * current = _head;
		int found = FALSE;

		while(found == FALSE && current != NULL ){
			if(current->value > value){ //achou um lugar se meter
				n->next = current;
				n->prev = current->prev;

				if(current == _head)
					_head = n;
				else
					current->prev->next = n;

				current->prev = n;

				found = TRUE;
			}

			current= current->next;
		}

		if(!found){
			_tail->next = n;
			n->prev = _tail;
			_tail = n;
		}
	}
}

void addFirst(int value){
	Node * n = newNode(value, NULL,_head);

	if(_head != NULL){ //caso haja mais do que 1 no na lista
		_head->prev = n;
	}

	_head = n;


	if(_tail == NULL)
		_tail = n;

}

void addLast(int value){
	Node * n = newNode(value, _tail, NULL);

	if(_tail != NULL){ //caso haja mais do que 1 no na lista
		_tail->next = n;
	}

	_tail = n;


	if(_head == NULL)
		_head = n;

}


void removeLast(){
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

void removeFirst(){
	Node * n = _head;
	if(_head == NULL)
		return;

	if(_head->next == NULL){ //Significa que so ha 1 elemento na lista
		_tail = NULL;
		_head = NULL;
	}
	else{
		_head = _head->next;
		_head->prev = NULL;
	}

	Node_delete(n);
}


void toString(){
	Node * current = _head;

	printf("\nList [ ");
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
		removeLast();
}

int find(int value){
	Node * current = _head;

	while(current != NULL){
		if(current->value == value) return TRUE;
		current = current->next;
	}

	return FALSE;
}

void pause(){
	printf("Press any key to continue . . .");
	scanf("%c");
}
#pragma endregion method_implementations