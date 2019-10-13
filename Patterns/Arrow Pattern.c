/*
C program to print this Arrow pattern

	  		*         
	          *       
	            *     
	              *   
	* * * * * * * * * 
	              *   
	            *     
	          *       
	        *

*/

#include<stdio.h>

int main()
{
	int n=9;
	int i,j;
	int c1 = (n-1)/2;
	int c2 = 3*n/2-1;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(j-i==c1||i==c1||i+j==c2) {
				printf("* ");
			}
			else {
				printf("  ");//2 spaces
			}
		}
		printf("\n");
	}
	return 0;
}