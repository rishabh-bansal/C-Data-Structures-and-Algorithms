#include<iostream>
using namespace std;

// A function to do counting sort of arr[] according to 
// the digit represented by exp. 

void countSort(int arr[], int n, int exp){
    int output[n+1];        // output array
    int i,freq[10] = {0}; 
    
    for(i=0;i<n;i++)        // Store count of occurrences in freq[] 
        freq[(arr[i]/exp)%10]++;
    
    for(i=1;i<10;i++)       //  Change count[i] so that count[i] now contains actual 
        freq[i]+=freq[i-1]; //  position of this digit in output[]
    
    for(i=n-1;i>=0;i--){
        output[freq[(arr[i]/exp)%10]-1]=arr[i];
        freq[(arr[i]/exp)%10]--;
    }
    
    for (i = 0; i < n; i++)  // Copy the output array to arr[], so that arr[] now 
                                // contains sorted numbers according to current digit 
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using  
// Radix Sort 

void radixsort(int arr[], int n)
{
    int m = arr[0];
    for(int i=1;i<n;i++)
        if(arr[i]>m)
            m=arr[i];
    
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
void print(int arr[],int n){
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

// Driver program to test above functions

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, n);
    print(arr, n);
    return 0;
}

