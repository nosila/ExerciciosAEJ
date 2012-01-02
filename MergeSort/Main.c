#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 50

#pragma region method_signature
int insertValuesInArray(int array[], int* count);
int printArray2(int array[], int count);
int mergeSort(int arrayA[], int sizeA, int arrayB[], int sizeB, int arrayC[]);
#pragma endregion method_signature

int main(){
	int arrayA[ARRAY_SIZE];
	int arrayB[ARRAY_SIZE];
	int arrayResult[ARRAY_SIZE];

	int value = 1;
	int i = 0;
	int countA = 0;
	int countB = 0;
	printf("<MERGE SORT>\n\n");
	
	printf("ArrayA:\n");
	insertValuesInArray(arrayA, &countA);
	printf("\nArrayB:\n");
	insertValuesInArray(arrayB, &countB);

	mergeSort(arrayA,countA,arrayB,countB,arrayResult);

	printf("Array final:\n");
	printArray2(arrayResult, countA+countB);

	return 0;
}

#pragma region method_implementation
int insertValuesInArray(int array[], int* count){
	int value = 1;
	(*count) = 0;
	do{
		printf("Insira um numero (0 para terminar):");
		scanf("%d",&value);

		if(value != 0){
			array[*count] = value;
			++(*count);
		}

		printArray2(array, *count);
	}while(value); //sai caso o valor seja 0
}

int printArray2(int array[], int count){
	int i = 0;

	printf("\nnumeros [ ");	 
	for(i = 0; i<count; i++){
		printf("%d ",array[i]);	 
	}
	printf("]\n");

	return;
}


int mergeSort(int arrayA[], int sizeA, int arrayB[], int sizeB, int arrayC[]) {
	int arrayAIndex = 0, arrayBIndex = 0, arrayCIndex = 0;

	while (arrayAIndex < sizeA && arrayBIndex < sizeB)
		if (arrayA[arrayAIndex] < arrayB[arrayBIndex])
			arrayC[arrayCIndex++] = arrayA[arrayAIndex++];
		else
			arrayC[arrayCIndex++] = arrayB[arrayBIndex++];

	while (arrayAIndex < sizeA)
		arrayC[arrayCIndex++] = arrayA[arrayAIndex++];

	while (arrayBIndex < sizeB)
		arrayC[arrayCIndex++] = arrayB[arrayBIndex++];
}
#pragma endregion method_implementation
