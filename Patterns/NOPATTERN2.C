#include<stdio.h>
#include<conio.h>
void main()
{
    int i,n,j;
    clrscr();
    printf("\n eNTER The Value of N:  ");
    scanf("%d",&n);
    for(i=n;i>=1;i--)     // IT WILL START WITH 5 AND GOES TO 1(END ROW) AFTER THAT NEXT NUMBER WILL TAKES PLACE
    {
        for(j=i;j>=1;j--)
            printf("%d  ",j);
        printf("\n");
    }
    getch();
}
/* output:
eNTER The Value of N:  5


5  4  3  2  1
4  3  2  1
3  2  1
2  1
1

*/
