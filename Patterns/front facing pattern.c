/*
C program to print this Facing pattern

	*      *
	**    **
	***  ***
	********
	***  ***
	**    **
	*      *

*/

#include<stdio.h>

int main()
{
	int size = 4;
	int s,space = size;
	int i,j;

	//Upper Triangle
	for(s=1;s<=size;s++) {
		
		for(i=1;i<=s;i++) {
			printf("*");
		}
		
		for(j=space;j>1;j--) {
			printf("  ");  //2 spaces 
		}
		
		for(i=s;i>=1;i--) {
			printf("*");
		}
		printf("\n");
		space--;
	}
	
	//Lower Triangle
	space = 2;
	for(s=size-1;s>=1;s--) {
		
		for(i=1;i<=s;i++) {
			printf("*");
		}
		
		for(j=space;j>1;j--) {
			printf("  ");  //2 spaces 
		}
		
		for(i=s;i>=1;i--) {
			printf("*");
		}
		printf("\n");
		space++;
	}
	return 0;
}