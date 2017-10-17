#include<stdio.h>
int main()
{
 int a[101],i,n,k,c=0,j;

 printf("Enter the value of n not more than 100\n");
 scanf("%d",&n);

 printf("Enter n numbers \n");

 for(i=0;i<n;i++)
 scanf("%d",&a[i]);

 for(i=0;i<n;i++)
 {
     for(j=i+1;j<n;)
     {
         if(a[i]==a[j])
         {

             for(k=j;k<n-1;k++)
             a[k]=a[k+1];
             n--;
         }
         else
            j++;

     }
 }
 for(i=0;i<n;i++)
 printf("%d\t",a[i]);
}
