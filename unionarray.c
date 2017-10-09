#include<stdio.h>
#include<conio.h>
int main()
{
    int n1,n2;
    int a[20],b[20],c[20];
    int i,j;
    int d=0;
    int e=0;
    int g=0;
    int f=0;
    printf("enter a size of array 1: ");
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
       scanf("%d",&a[i]);
    }
    printf("enter a size of array 2: ");
    scanf("%d",&n2);

    for(i=0;i<n2;i++)
    {
       scanf("%d",&b[i]);
    }
    for(i=0;i<n1;i++)
    {
        for(j=0;j<g;j++)
        {
            if(a[i]==c[j])
            {
                f=f+1;
            }
        }
        if(f==0)
        {
            c[g]=a[i];
            g=g+1;
        }
        else
        {
            f=0;
        }
    }
    for(i=0;i<n2;i++)
    {
        for(j=0;j<n1+e;j++)
        {
            if(b[i]==c[j])
            {
                d=d+1;
            }
        }
        if(d==0)
        {
            c[g+e]=b[i];
            e=e+1;
        }
        else
        {
            d=0;
        }
    }
    printf("\n");
    printf("union of above two arrays is : ");
    for(i=0;i<e+g;i++)
    {
        printf("%d ",c[i]);
    }
    printf("\n");
    return 0;
}
