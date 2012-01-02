
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define _true 1
#define _false 0

#define ARRAY_SIZE 50

#pragma region methods_signature
int printArray2(int array[], int count);
int selectionSort(int array[], int count);
int swap (int *x, int *y);
#pragma endregion methods_signature

int main(int argc, char **argv){
	int array[ARRAY_SIZE];

	int value = 1;
	int i = 0;
	int count = 0;

	printf("<SELECTION SORT>\n\n");
	do{
		printf("Insira um numero (0 para terminar):");
		scanf("%d",&value);
		
		if(value != 0){
				array[count] = value;
				++count;
				printArray2(array, count);
		}
		
	}while(value); //sai caso o valor seja 0
	selectionSort(array,count);	
	printArray2(array, count);

	return 0;
}

#pragma region methods_implementation
int printArray2(int array[], int count){
	int i = 0;

	printf("\nnumeros [ ");	 
	for(i = 0; i<count; i++){
		printf("%d ",array[i]);	 
	}
	printf("]\n");

	return;
}


int selectionSort(int array[], int count) 
{ 
	int i, j, min;
	for (i = 0; i < (count-1); i++) 
	{
		min = i;
		for (j = (i+1); j < count; j++) {
			if(array[j] < array[min]) 
				min = j;
		}

		if (i != min) 
			swap(&array[i],&array[min]);
		
	}

	return;
} 
int swap (int *x, int *y) {
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
}
#pragma endregion methods_implementation