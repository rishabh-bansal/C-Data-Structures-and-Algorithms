/* This is program that makes the following output pattern

Input =5

output -

   *
  * *
 * * *
* * * *

*/
#include <stdio.h>

#include <stdlib.h>

int main() {
  int a, i, j, k;

  scanf("%d", & a);                     //taking the input of how many lines the pattern should run.

  for (i = 0; i < a; i++)                 //running The main loop for each line
  {
    for (j = 0; j < (a - 1) - i; j++)       //running the nested loop for indentation of the * .
      printf(" ");
    for (k = 0; k < i; k++)       //loop for producing * in each line as the ljne number correseponds to the number of stars in that line
    {
      printf("*");
      printf(" ");
    }
    printf("\n");
  }

  return 0;
}

