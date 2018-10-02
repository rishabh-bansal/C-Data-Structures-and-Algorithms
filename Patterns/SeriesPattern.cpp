#include<stdio.h>
int main()
{
	int i,j,n,k=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
			if(i%2==0)                     // if i is even then print in decreasing order ex- ifi=2--(3,2)
		{
			k=k+i;
			for(j=1;j<=i;j++)
			{
			printf("%d ",k);
			k--;
			}
			k=k+i;
		}
			else                            // if i is odd print in increasing order ex i=3--(4,5,6,7)
			{
				for(j=1;j<=i;j++)
				{
			      printf("%d ",++k);
		        }
		  }
		printf("\n");
		
	}
return 0;
}

/* Output:
6           // input
1
3 2
4 5 6
10 9 8 7
11 12 13 14 15
21 20 19 18 17 16

*/




