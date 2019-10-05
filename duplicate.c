#include<stdio.h>

int main() {
  int a[101], i, n, k, c = 0, j;

  printf("Enter the value of n not more than 100:\n");
  scanf("%d", & n);                                  //Number of values we want to enter

  printf("Enter n numbers :\n");

  for (i = 0; i < n; i++)
    scanf("%d", & a[i]);                             //Enter the values

  for (i = 0; i < n; i++) {                          //Outer Loop Starting from 0 to N-1 
    for (j = i + 1; j < n;) {                        //Inner Loop Starting from i+1 to N-1
      if (a[i] == a[j]) {                            // Check if values are equal 

        for (k = j; k < n - 1; k++)                  //Inner Loop Starting from J to N-2;
          a[k] = a[k + 1];                           
        n--;                                         //Reduce the value of N by one
      } else
        j++;                                         // if value not matched then increment the value of inner j loop

    }
  }
  for (i = 0; i < n; i++)
    printf("%d\" "", a[i]);                          //Print the array that contain all distinct values
}
  
           
  /*
      SAMPLE INPUT:
      Enter the value of n not more than 100:
      10
      Enter n numbers:
      1 5 4 2 4  4 2 1 3 6
      
      SAMPLE OUTPUT:
       1  5  4  2  3  6
   
     */
