#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n,j,m;
    printf("Enter the no.");
    scanf("%d", &n);
  	// Complete the code to print the pattern.
      for(int i=0;i<n;i++)
      {
          for(j=n;j>=n-i;j--)
          {
              
              printf("%d ",j);
          }
          j=j+1;
            
          for(int k=0;k<2*n-3-2*i;k++)
          {
              if(j==1)
              {
                  break;
              }
              printf("%d ",j);
          }
          for(int l=j;l<=n;l++)
          {
              if(l==1)
              {
                  l=l+1;
              }
            printf("%d ",l);
          }
          printf("\n");
      }
      for(int z=0;z<n-1;z++)
      {
      for(m=n;m>z+1;m--)
      {
          printf("%d ",m);
      }
      m=m+1;
      for(int o=0;o<2*m-3;o++)
      {
          printf("%d ",m);
      }
      for(int q=m;q<=n;q++)
      {
          printf("%d ",q);
      }
      printf("\n");
      }  
      

    return 0;
}

