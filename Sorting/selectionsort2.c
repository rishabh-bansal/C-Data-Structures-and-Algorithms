/*Selection Sort - C program to sort an Array 
in Ascending and Descending Order.*/
 
#include <stdio.h>
 
#define MAX 100
 
int main()
{
    int arr[MAX],limit;
    int i,j,temp,position;
     
    printf("Enter total number of elements: ");
    scanf("%d",&limit);
     
    /*Read array*/
    printf("Enter array elements: \n");
    for(i=0; i<limit; i++)
    {
        printf("Enter element %3d: ",i+1);
        scanf("%d",&arr[i]);
    }
     
    /*sort elements in Ascending Order*/
    for(i=0; i<(limit); i++)
    {
        position=i;
        // finding the minimum element in [i+1,limit] and swapping with arr[i]
        for(j=i+1; j<limit; j++)
        {
            if(arr[position]>arr[j])
            {
                position=j;
            }
            if(position!=i)
            {
                temp=arr[i];
                arr[i]=arr[position];
                arr[position]=temp;                
            }
        }
    }
    // printing the sorted array 
    printf("Array elements in Ascending Order:\n");
    for(i=0; i<limit; i++)
        printf("%d ",arr[i]);
     
    printf("\n");
         
    /*sort elements in Descending Order*/
    for(i=0; i<(limit); i++)
    {
        position=i;
        // finding the maximum element in [i+1,limit] and swapping it with arr[i]
        for(j=i+1; j<limit; j++)
        {
            if(arr[position]<arr[j])
            {
                position=j;
            }
            if(position!=i)
            {
                temp=arr[i];
                arr[i]=arr[position];
                arr[position]=temp;                
            }
        }
    }
    
    // printing the sorted array
    printf("Array elements in Descending Order:\n");
    for(i=0; i<limit; i++)
        printf("%d ",arr[i]);
         
    printf("\n");
     
    return 0;
}
