#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int** initTwoDArr(int row, int col){
	int** TwoDArr = (int**)malloc(row*sizeof(int*));
	for (int i = 0; i < row; i++){
		TwoDArr[i] = (int*)malloc(col*sizeof(int));
	}
	return TwoDArr;
}

int** getTableOfInput(int degree){
	int n = pow(2,degree);
	int m = n;
	int** inputTable = initTwoDArr(n, degree);
	for(int i = 0; i < degree; i++){
		m = m/2;
		for(int j = 0; j < n; j++){
			int k = (int)floor(j/m) % 2;
			if (k == 0)
				inputTable[j][i] = 1;
			else
				inputTable[j][i] = 0;
		}
	}
	return inputTable;
}


void getBoolFunc(int A[], int degree, int size){
	int** input = getTableOfInput(degree);
	if (size != pow(2,degree)){
		printf("Invalid number of values\n");
		return;
	}
	else {
		printf("List of minterms for this function:\n");
		for(int i = 0; i < size; i++){
			if(A[i] == 1){
				for(int j = 0; j < degree; j++){
					if(input[i][j] == 1)
						printf("x(%d)",j);
					else
						printf("(!x(%d))",j);
				}
				printf("\n");
			}
		}
	}
	free(input);
}

void main(){
	int A[] = {0,1,0,0,1,0,1,0};
	getBoolFunc(A,3, sizeof(A)/sizeof(int));

}