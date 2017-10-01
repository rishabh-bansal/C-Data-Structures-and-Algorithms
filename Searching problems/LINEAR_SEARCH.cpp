#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 1000;
int arr[N];
int n,m,k;
int main()
{
	//First we will load our array. It will be consisted of n integers.
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&arr[i]);
	}
	//Now we are searching for the number m in our input array. 
	//We are doing that using the linear search, because we are visiting each element once 
	//until we reach our goal. 
	//Complexity of the given solution is O(N)
	scanf("%d",&m);
	for(int i=0;i<n;++i)
	{
		if(arr[i]==m)
		{
			printf("Found it on the %d-th position.\n",i+1);
			break;
		}
	}
	return 0;
}
