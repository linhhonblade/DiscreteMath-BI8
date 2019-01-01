#include <stdio.h>
int main(){
	int n;
	printf("n = ");
	scanf("%d", &n);
	int quart = (int)(n/25);
	n = n % 25;
	int dimes = (int)(n/10);
	n = n % 10;
	int nickels = (int)(n/5);
	int pennies = n % 5;
	printf("quart = %d\ndimes = %d\nnickels = %d\npennies = %d\n",quart, dimes, nickels, pennies);


}