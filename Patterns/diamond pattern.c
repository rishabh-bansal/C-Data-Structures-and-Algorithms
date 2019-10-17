/*  program to print following pattern
5 //user input
***** *****
****   ****
***     ***
**       **
*         *
*         *
**       **
***     ***
****   ****
***** *****

*/

#include<stdio.h>   //header file for input and output
#include<conio.h>  //header file for direct run
int main()   //main function execute from here
{

    int i,j,l; //decelerations of the variables
    scanf("%d",&l);   //input from user
    for(i=1;i<=l;i++)  //loop for upper triangle
    {

  for(j=0;j<=2*l;j++)
  {

    if((((j>=0)&&(j<=(l-i))))||(((j>=(l+i))&&(j<=2*l))))
       printf("*"); //printing star
    else
        printf(" "); //printing spaces
  }
    printf("\n"); //for new line
   }
/*
5
***** *****
****   ****
***     ***
**       **
*         *
*/

    for(i=1;i<=l;i++) //loop for lower triangle
    {

  for(j=0;j<=2*l;j++)
  {

    if(((j<=(i-1))&&(j>=0))||((j>=((2*l)-i+1))&&(j<=2*l)))
       printf("*"); //printing star
    else
        printf(" "); //printing space
  }
    printf("\n"); //for new line
   }


/*
5
*         *
**       **
***     ***
****   ****
***** *****
*/
}


