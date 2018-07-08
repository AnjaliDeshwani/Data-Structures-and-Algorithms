#include<stdio.h>
main()
{
  int n,arr[10],i;
  printf("\nEnter the size of array");
  scanf("%d",&n);
  printf("\nEnter an array");
  for(i=0;i<n;i++)
  scanf("%d",&arr[i]);
  printf("\nGiven array is ");
  printArray(arr,n);
  quickSort(arr,0,n-1);
  printf("\nSorted array is ");
  printArray(arr,n);
}
void quickSort(int arr[],int lb,int ub)
{ 
    int pi;
	if(lb<ub)
	{
	  pi=partition(arr,lb,ub);
	  quickSort(arr,lb,pi-1);
	  quickSort(arr,pi+1,ub);
	}
}

int partition(int arr[],int lb,int ub)
{
  int pivot,i,j;
  pivot=arr[ub];
  i=lb-1;
  for(j=lb;j<=ub-1;j++)
  {
  	if(arr[j]<=pivot)
  	{
  	    i++;
		swap(&arr[i],&arr[j]);	
	}
  }
   swap(&arr[i+1],&arr[ub]);
   return i+1;	
}
void printArray(int arr[],int n)
{
	int i;
    for(i=0;i<n;i++)
      printf("%d ",arr[i]);
    printf("\n");
}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

