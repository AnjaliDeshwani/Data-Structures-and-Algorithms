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
  mergeSort(arr,0,n-1);
  printf("\nSorted array is ");
  printArray(arr,n);
}
void mergeSort(int arr[],int lb,int ub)
{ 
    int mid;
	if(lb<ub)
	{
	   mid=lb+(ub-lb)/2;
	   mergeSort(arr,lb,mid);
	   mergeSort(arr,mid+1,ub);
	   merge(arr,lb,mid,ub);
	}
}

void merge(int arr[],int lb,int mid,int ub)
{
   int i,j,k,temp[ub-lb+1];
   i=lb;
   j=mid+1;
   for(k=0;(i<=mid)&&(j<=ub);k++)
   {
   	   if(arr[i]<arr[j])
   	   	  temp[k]=arr[i++];
	    else
	       temp[k]=arr[j++];
	
   }
   while(i<=mid)
   {
   	   temp[k++]=arr[i++];   
   }
    while(j<=ub)
   {
   	   temp[k++]=arr[j++];	   
   }
   k=0;
   for(i=lb;i<=ub;i++)
   {
   	  arr[i]=temp[k++];
   }
}
void printArray(int arr[],int n)
{
	int i;
    for(i=0;i<n;i++)
      printf("%d ",arr[i]);
    printf("\n");
}

