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

void printTable(int** table, int row, int col){
	for(int i = 0; i < col; i++){
		printf("[%d]",i );
		for (int j = 0; j < row; j++){
			printf("%d",table[j][i] );
		}
		printf("\n");
	}
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

int** getTableOfOutput(int degree){
	int row = pow(2,degree);
	int col = pow(2,pow(2,degree));
	int m = col;
	int** outputTable = initTwoDArr(row, col);
	for(int i = 0; i < row; i++){
		m = m/2;
		printf("%d\n",m );
		for(int j = 0; j < col; j++){
			int k = (int)floor(j/m) % 2;
			//printf("%d\n",k );
			if (k == 0)
				outputTable[i][j] = 1;
			else
				outputTable[i][j] = 0;
		}
	}
	return outputTable;
}



int** funcTable(int degree){
	//int** inputTable = getTableOfInput(degree);
	//printTable(inputTable,pow(2,degree),degree);
	int** outputTable = getTableOfOutput(degree);
	printTable(outputTable,pow(2,degree), pow(2,pow(2,degree)));
}



void main(){
	int** table = funcTable(3);
	return;
}

