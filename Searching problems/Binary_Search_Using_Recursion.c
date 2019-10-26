#include<stdlib.h>
#include<stdio.h>

int BinarySearch(int A[],int ele,int first,int last){
	
int mid=(first+last)/2;

if(A[mid]==ele) {
    return mid;
}

if(A[mid]!=ele){

    if(A[mid]>ele && first<=last){
        return BinarySearch(A,ele,first,mid-1);
    } else if(A[mid]<ele && first<=last){
        return BinarySearch(A,ele,mid+1,last);
    }
    
}

printf("Searched Element Not Found");

return -1;
}
int main(){

int i ,size,ele,loc,A[20];

printf("Enter the size:");
scanf("%d",&size);

printf("\nEnter the Array:");
for(i=0;i<size;i++){
    scanf("%d",&A[i]);
}

printf("\nEnter the no. to be searched :");
scanf("%d",&ele);

loc=BinarySearch(A,ele,0,size-1);

if(loc!=-1){
    printf("\nThe searched element %d is present at location:%d",ele,loc+1);
}

return 0;
}
