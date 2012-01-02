#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 50

#pragma region method_signature
int printArray(int array[], int count);
int bubbleSort(int array[], int count);
int swap(int *x, int *y);
#pragma endregion method_signature


int main(int argc, char **argv){
	int array[ARRAY_SIZE];

	int value = 1;
	int i = 0;
	int count = 0;

	printf("<BUBBLE SORT>\n\n");
	do{
		printf("Insira um numero (0 para terminar):");
		scanf("%d",&value);

		if(value != 0){
			array[count] = value;
			++count;
				
		}
		printArray(array, count);
	}while(value); //sai caso o valor seja 0

	bubbleSort(array,count);
	printArray(array, count);
}

#pragma region method_implementation
int printArray(int array[], int count){
	int i = 0;

	printf("\nnumeros [ ");	 
	for(i = 0; i<count; i++){
		printf("%d ",array[i]);	 
	}
	printf("]\n");

	return;
}


int bubbleSort(int array[], int count) 
{ 
	int i = 0, j = 0;
	for(i=0; i<count; i++){
		for(j=0; j<count-1; j++){
			if(array[j]>array[j+1]) {
				swap(&array[j],&array[j+1]);
			}
		}
	}

	return;
} 

int swap(int *x, int *y) {
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}
#pragma endregion method_implementation
