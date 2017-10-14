/*program to print the following pattern:-
          *
         * *
        * * *
       * * * * 
      * * * * *
 ----------------------------------------------------------       

 first loops for number of rows
second loop for printing spaces
third loops for printing '*' */



#include <stdio.h>
#include <conio.h>
void main() {
	int i,j,k,t=0;
	clrscr();
	for (i=1; i<=5; i++) {
		for (k=t; k<5; k++) {
			printf(" ");
		}
		for (j=0; j< i; j++) {
			printf(" * ");
			t = t + 1;
		}
		printf("\n");
	}
	getch();
