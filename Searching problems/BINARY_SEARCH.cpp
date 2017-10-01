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
	scanf("%d",&m);
	//The array in which we are looking for the given integer M has to be sorted.
	sort(arr,arr+n);
	
	int low=0;
	int midd=0;
	int high=n-1;
	while(low<=high)
	{
		//Setting the middle of the interval using the values low and high
		midd=(low+high)>>1;
		//If our number at position midd is higher than the m that means that our
		//number is in the left side of the array, so we are putting the high to be midd -1
		//We checked that midd isn't our wanted element, so the element with tha highest id that we didn't
		//check is midd -1 so we are putting high to that value.
		//Because we are dividing our array by two each time we are getting complexity of O(log(N))
		if(arr[midd]>m)high=midd-1;
		else low=midd;
	}
	//Complexity of the given solution is O(log(N))
	if(arr[low]==m)
		printf("Found it on the %d-th position.\n",low+1);
	else 
		printf("We didn't find it.\n");
	return 0;
}
