#include<stdio.h>
#include<stdlib.h>
void input(int[],int,int[]);
void sunion(int[],int,int,int);
int sfind(int[],int,int);
void wunion(int[],int,int,int,int[]);
int cfind(int[],int,int);
main()
{
	int a[20],count[20],n,i,j,choice;
	printf("enter the size of the array");
	scanf("%d",&n);
    input(a,n,count);
    do
    {
    	printf("\n1.Simple union");
    	printf("\n2.Simple find");
    	printf("\n3.Weighted Union");
    	printf("\n4.Collapsing find");
    	printf("\n5.exit");
    	printf("\nenter your choice..");
    	scanf("%d",&choice);
    	switch(choice)
    	{
    		case 1:printf("\nEnter the root1");
    		       scanf("%d",&i);
    		       printf("\nEnter the root2");
    		       scanf("%d",&j);
    		       sunion(a,n,i,j);
    		       break;
    		case 2:printf("\nEnter the node you want to search");
    		       scanf("%d",&i);
    		       j=sfind(a,n,i);
    		       printf("\nroot of the node %d is %d",i,j);
    		       break;
    		case 3:printf("\nEnter the root1  ");
    		       scanf("%d",&i);
    		       printf("\nEnter the root2  ");
    		       scanf("%d",&j);
    		       wunion(a,n,i,j,count);
    		       break;
    		case 4:printf("\nEnter the node you want to search");
    		       scanf("%d",&i);
    		       printf("\nroot of the node%d is %d",i,cfind(a,n,i));
    		       break;
    		       
    	   default :printf("\nInvalid choice");
    	            break;
		}
	}while(choice!=5);
}
void input(int a[],int n,int count[])
{
	int i,x;
	for(i=1;i<=n;i++)
	{
		printf("\nfor root node enter -1");
		printf("\nenter parent of %d  : ",i);
		scanf("%d",&a[i]);
		
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]==-1)
		{
			printf("\nenter the count of nodes in root %d  ",i);
			scanf("%d",&x);
			count[i]==x;
		}
	}
}
void sunion(int a[],int n,int i,int j)
{
	a[i]=j;
}
int sfind(int a[],int n,int i)
{
	while(a[i]>=0)
	  i=a[i];
	return i;
}
void wunion(int a[],int n,int i,int j,int count[])
{
	int temp;
	a[i]=-count[i];
	a[j]=-count[j];
	temp=a[i]+a[j];
	if(a[i]>a[j])
	{
		a[i]=j;
		a[j]=temp;
	}
	else
	{
		a[j]=i;
		a[i]=temp;
	}
}
int cfind(int a[],int n,int i)
{
	int r,s;
	r=i;
	while(a[r]>0)
	   r=a[r];
    while(i!=r)
    {
    	s=a[i];
    	a[i]=r;
    	i=s;
	}
	return r;
}
