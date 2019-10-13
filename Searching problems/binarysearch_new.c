#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 1000;
int arr[N];
int n,m,k;
int main()
{
		scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&arr[i]);
	}
	
	scanf("%d",&m);
	
	sort(arr,arr+n);
	
	int low=0;
	int midd=0;
	int high=n-1;
	while(low<=high)
	{

		midd=(low+high)>>1;
		if(arr[midd]>m)high=midd-1;
		else low=midd;
	}

	if(arr[low]==m)
		printf("Found on the %d-th position.\n",low+1);
	else 
		printf("NOT FOUND\n");
	return 0;
}
