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
  selectionSort(arr,n);
  printArray(arr,n);
}
void selectionSort(int arr[],int n)
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		  if(arr[j]<arr[min])
		    min=j;
		    
		swap(&arr[i],&arr[min]);
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
