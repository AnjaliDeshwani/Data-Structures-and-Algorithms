#include<stdio.h>
#define size 50
int select(int[size],int,int,int);
int partition(int[size],int,int);
void swap(int*,int*);
main()
{
	int a[size],n,i,k,s,low,up;
	printf("\nEnter the size of an array");
	scanf("%d",&n);
	printf("\nEnter the elements of an array");
	for(i=0;i<n;i++)
	   scanf("%d",&a[i]);
	printf("\nEnter the position of the element");
	scanf("%d",&k);   
	low=0;
	up=n-1;
	s=select(a,low,up,k);	
	printf("%dth smallest element is %d",s,a[s]);
}
int select(int a[size],int low,int up,int k)
{
	int j;
	do{
			printf("\n1.hbhjbhb");
		j=partition(a,low,up);
		printf("%d",j);
		if(k==j)
		  return j;
		else if(k<j)
		  up=j-1;
		else if(k>j)
		  low=j+1;
	}while(1);
}
int partition(int a[size],int low,int up)
{
	int pivot,i,j;
	pivot=a[up];
	i=low-1;
	for(j=low;j<=up-1;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[up]);
	return i+1;
}
void swap(int* p1,int* p2)
{
	int temp;
	temp=*p1;
	*p1=*p2;
	*p2=temp;
	
}
