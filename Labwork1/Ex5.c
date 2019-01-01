#include<stdio.h>

int searchLinear(int a, int A[], int size){
	int i = 0;
	int countLinear = 0;
	while(i < size){
		if (A[i] == a){
			countLinear++;
			return countLinear;
		}
		countLinear++;
		i++;
	}
	return -1;
}

void searchBinary(int a, int A[], int left, int right, int* countBinary){
	int mid = ((left+right)/2);
	if(right >= left){
		if(a == A[mid]){
			*countBinary++;
			return;
		}
		else if(a>A[mid]){
			*countBinary++;
			searchBinary(a, A, mid+1, right, countBinary);
		}
		else if(a < A[mid]){
			*countBinary++;
			searchBinary(a, A, left, mid-1, countBinary);
		}
	}
	else return;

}

int main(){
	int A[] = {1, 4, 5, 12, 23, 63};
	int countBinary = 0;
	int pos = searchLinear(5, A, sizeof(A)/sizeof(int));
	printf("%d\n",pos );
	searchBinary(45, A, 0, sizeof(A)/sizeof(int)-1, &countBinary);
	printf("%d\n",pos );
	return 0;
}