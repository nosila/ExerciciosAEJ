#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 50

#pragma region method_signature
int printArray(int array[], int count);
int insertionSort(int array[], int count);
#pragma endregion method_signature

int main(){
	int array[ARRAY_SIZE];

	int value = 1;
	int i = 0;
	int count = 0;
	printf("<INSERTION SORT>\n\n");
	do{
		printf("Insira um numero (0 para terminar):");
		scanf("%d",&value);

		if(value != 0){
			array[count] = value;
			++count;
			insertionSort(array,count);	
		}
		printArray(array, count);
	}while(value); //sai caso o valor seja 0

	return 0;
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

int insertionSort(int array[], int count){
	int i = 0;

	for(i = 0; i<count; i++){
		int j, v = array[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (array[j] <= v) break;
			array[j + 1] = array[j];
		}
		array[j + 1] = v;
	}
}
#pragma endregion method_implementation
