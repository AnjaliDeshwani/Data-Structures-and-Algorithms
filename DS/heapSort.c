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
  heapSort(arr,n);
  printArray(arr,n);
}
void heapSort(int arr[],int n)
{
	int i;
   for(i=n/2-1;i>=0;i--)
   {
   	   heapify(arr,n,i);
   }
   for(i=n-1;i>0;i--)
   {
   	 swap(&arr[i],&arr[0]);
   	 heapify(arr,i,0);
   }
}
void heapify(int arr[],int n,int i)
{
	int largest,l,r;
	largest=i;
	l=2*i+1;
	r=2*i+2;
    if(l<n && arr[l]>arr[largest])
       largest=l;
    
    if(r<n && arr[r]>arr[largest])
       largest=r;
    
    if(largest!=i)
    {
      swap(&arr[largest],&arr[i]);
    	
       heapify(arr,n,largest);
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
