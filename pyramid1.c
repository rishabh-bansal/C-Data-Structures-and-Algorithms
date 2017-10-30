#include<stdio.h>
#include<conio.h>
void main()
{
    int i,j;
    int n;
    printf("enter a no.");
    scanf("%d",&n);
    for(i=0;i<n;i=i+2)
    {
        for(j=0;j<(n-i-1)/2;j++)
        {
            printf(" ");
        }
        for(j=(n-i-1)/2;j<=(n+i-1)/2;j++)
        {
            printf("*");
        }
        for(j=((n+i-1)/2)+1;j<n;j++)
        {
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}
