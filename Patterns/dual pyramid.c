/*
C program to print this dual pattern

	**********
	****  ****
	***    ***
	**      **
	*        *

*/

#include<stdio.h>

int main()
{
	int size,s=1;
	int i,j;
	for(size=5;size>=1;size--) {
		
		for(i=1;i<=size;i++){
			printf("*");
		}
		
		for(j=s;j>1;j--) {
			printf("  "); //2 spaces
		}
		
		for(i=size;i>=1;i--) {
			printf("*");
		}
		printf("\n");
		s++;
	}
	return 0;
}