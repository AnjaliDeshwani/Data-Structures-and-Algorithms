#include<stdio.h>
int binarySearch(int arr[],int l,int r,int key)
{
	int mid;
	if(r>=l)
	{
		mid=l+(r-l)/2;
		
		if(key==arr[mid])
		   return mid;
	    
	    if(key<arr[mid])
	       return binarySearch(arr,l,mid-1,key);
	       
	    if(key>arr[mid])
	       return binarySearch(arr,mid+1,r,key);
	}
	return -1;
}
void printArray(int arr[],int n)
{
	int i;
    for(i=0;i<n;i++)
      printf("%d ",arr[i]);
    printf("\n");
}
main()
{
	int arr[20],n,i,key,result;
	printf("\nEnter the size of array");
    scanf("%d",&n);
    printf("\nEnter an array");
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    printf("\nEnter an element you want to search");
    scanf("%d",&key);  
    printf("\nGiven array is ");
    printArray(arr,n);
    result=binarySearch(arr,0,n-1,key);
    (result==-1)?printf("\nelement not found"):printf("\nelement fount at index %d",result); 
}
