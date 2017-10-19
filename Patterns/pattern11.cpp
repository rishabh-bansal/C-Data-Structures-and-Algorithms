/*program to print the following pattern-
                   1
                  2 2
                 3 3 3
                4 4 4 4
               5 5 5 5 5
-------------------------------------------------------------*/
    #include <stdio.h>
       void main() {
    	int i, j=5, k, x;
    	clrscr();
    	for (i=1;i<=5;i++) {            //iterating loop for rows
    		for (k=1;k<=j;k++) {    //iterating loop for spaces
    			printf(" ");    //printing spaces
    		}
    		for (x=1;x<=i;x++) {    //iterating loop for columns
    			printf("%d",i); //printing numbers
    			printf(" ");    //again printing spaces
    		}
    		printf("\n");          //for moving into next line
    		j=j-1;                 //decreamenting the value of j by 1
    	}
    
    }
