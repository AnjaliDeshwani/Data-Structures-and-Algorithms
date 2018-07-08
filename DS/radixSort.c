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
  radixSort(arr,n);
  printArray(arr,n);
}
void radixSort(int arr[],int n)
{
   int bucket[10][10],numdigits=0,max,i,j,divisor=1,count[10],digit=0,k,l;
   max=maximum(arr,n);
   while(max>0)
   {
   	  numdigits++;
   	  max=max/10;
   }
   for(i=0;i<numdigits;i++)
   {
   	   for(j=0;j<10;j++)
   	     count[j]=0;
   	    
   	    for(j=0;j<n;j++)
   	    {
   	       digit=(arr[j]/divisor)%10;
		   bucket[digit][count[digit]]=arr[j];
		   count[digit]+=1;
		}
		j=0;
		for(k=0;k<10;k++)
		{
			for(l=0;l<count[k];l++)
			{
				arr[j]=bucket[k][l];
				j++;
			}
		}
		divisor*=10;
   }
}
int maximum(int arr[],int n)
{
  int i,max;
  max=arr[0];
  for(i=0;i<n;i++)
    if(arr[i]>max)
      max=arr[i];
   return max;

}
void printArray(int arr[],int n)
{
	int i;
    for(i=0;i<n;i++)
      printf("%d ",arr[i]);
    printf("\n");
}

