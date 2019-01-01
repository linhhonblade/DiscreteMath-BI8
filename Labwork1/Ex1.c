#include <stdio.h>
#include <math.h>
int A[] = {1,3,5,7,22,25,35,44,57,75,88,124};

int search(int a, int left, int right){
	int mid = ceil((left+right)/2);
	if (a==A[mid]){
		return mid;
	}
	if (mid==right){
		return -1;
	}
	else if(a > A[mid]){
		search(a, mid+1, right);
	}
	else if(a < A[mid]){
		search(a, left, mid-1);
	}
}

int main(){
	int a;
	printf("a = ");
	scanf("%d", &a);
	int lastIndx = sizeof(A)/sizeof(int);
	int ind = search(a, 0, lastIndx);
	printf("%d\n",ind );
	return 0;
}