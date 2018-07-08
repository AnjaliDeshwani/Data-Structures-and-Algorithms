// C program for insertion sort
#include<stdio.h>
main()
{
  int n,arr[10],i;
  printf("\nEnter the size of array"); 
  
  scanf("%d",&n);
  printf("\nEnter an array");
  for(i=0;i<n;i++)
  scanf("%d",&arr[i]);
  printArray(arr,n);
  insertionSort(arr,n);
  printArray(arr,n);
}
void insertionSort(int arr[],int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
		    arr[j+1]=arr[j];
			j=j-1;	
		}
		arr[j+1]=key;
	}
}
void printArray(int arr[],int n)
{
	int i;
    for(i=0;i<n;i++)
      printf("%d ",arr[i]);
    printf("\n");
}

