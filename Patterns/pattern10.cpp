/*program to print the following pattern-
1
23
456
------------------------------------------------------------------*/
   #include <stdio.h>
  
    void main() {
    	int rw, c, no=1 ,len;
    	clrscr();
    	printf("Enter number of rows: ");  //asking for the value from user
    	scanf("%d," &len);                 //taking value from the user
    	for (rw=1; rw<=len; rw++) {       //iterate the loop from 1 to len
    		printf("\n");            //for moving into next line
    		for (c=1; c<=rw; c++) {   //iterating loopfrom 1 to i
    			printf(" %2d ", no);  //printing number
    			no++;                 //increasing the number by
    		}
    	}
    	
    }
