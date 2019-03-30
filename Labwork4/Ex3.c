#include <stdio.h>
#include <stdlib.h>
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
		printf("%d\n",m );
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

void printKmap3(int** table, int row, int col){
	printf("\tyz\ty!z\t!y!z\t!yz\n");
	printf("x\t");
	for(int i = 0; i < col; i++){
		printf("%d\t",table[0][i]);
	}
	printf("\n");
	printf("!x\t");
	for(int i = 0; i < col; i++){
		printf("%d\t",table[1][i]);
	}
	printf("\n");
}

int** getKmap3(int A[], int size){
	if (size != 8){
		printf("Invalid input\n");
		return NULL;
	}
	int** Kmap = initTwoDArr(2,4);
	int row = 0;
	int col = 0;
	int** input = getTableOfInput(3);
	for(int i = 0; i < size; i++){
		if(A[i] == 1){
			if(input[i][1] == 0)
				row = 1;
			int sum = input[i][2] + input[i][3];
			int diff = input[i][2] + input[i][3];
			if(diff == 0){
				if(sum == 0)
					col = 2;
				else
					col = 0;
			}
			else if (diff = 1)
				col = 1;
			else
				col = 3;
		Kmap[row][col] = 1;
		}
	}
	return Kmap;
}

void main(){
	int A[] = {0,0,1,0,1,0,0,1};
	printKmap3(getKmap3(A, sizeof(A)/sizeof(int)), 2,4);
	return;
}