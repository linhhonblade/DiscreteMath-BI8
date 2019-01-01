#include <stdio.h>
int countBubble(int A[], int lastIndx){
	int i = 0;
	int count=0;
	int j = lastIndx;
	int isSorted = 1;
	while(j>=1){
		if(isSorted==0){
			return count;
		}
		for(i =0; i<j; i++){
			isSorted = 0;
			if (A[i]>A[i+1]){
				count++;
				A[i] = A[i] + A[i+1];
				A[i+1] = A[i]-A[i+1];
				A[i] = A[i] - A[i+1];
				isSorted++;
			} count++;
		}
		j--;
	}
	return count;
}

int countInsertion(int A[], int size){
	int temp, j, i;
	int count = 0;
	for(i = 1; i < size; i++){
		j = i-1;
		temp = A[j];
		if(A[j] > A[i]){
			count++;
			while(j >= 0 && A[j]>A[j+1]){
				count++;
				A[j] = A[j+1];
				A[j+1] = temp;
				j--;
				temp = A[j];
			}count++;	
		}count++;
	}
	return count;
}

int main(){
	int A[] = {12, 34, 2,3 ,42,14, 64,32,1,5};
	//int A[] = {1, 3, 5, 6, 7, 12, 34};
	int count = countBubble(A, sizeof(A)/sizeof(int)-1);
	printf("%d\n",count);
	int countInsert = countInsertion(A, sizeof(A)/sizeof(int));
	printf("%d\n",countInsert );
	for(int i =0; i< sizeof(A)/sizeof(int);i++){
		printf("%d\t",A[i] );
	}
	printf("\n");

}