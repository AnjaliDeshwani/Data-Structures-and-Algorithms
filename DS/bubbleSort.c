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
  bubbleSort(arr,n);
  printArray(arr,n);
}
void bubbleSort(int arr[],int n)
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
	    for(j=0;j<n-1-i;j++)
	      if(arr[j]>arr[j+1])
		   swap(&arr[j],&arr[j+1]);
	}
}
void printArray(int arr[],int n)
{
	int i;
    for(i=0;i<n;i++)
      printf("%d ",arr[i]);
    printf("\n");
}
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
