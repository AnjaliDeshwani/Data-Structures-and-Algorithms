#include<stdio.h>
#include<Math.h>
#define size 20
int place(int,int,int[]);
void nQueens(int,int,int[]);
main()
{
	int n,k,x[size],i;
	printf("Enter the value of n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	   x[i]=0;
	nQueens(1,n,x);
}
void nQueens(int k,int n,int x[size])
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		if(Place(k,i,x))
		{
			x[k]=i;
		
			if(k==n)
			{
					printf("\n");
			   for(j=1;j<=n;j++)
			      printf("%d\t",x[j]);
		    }
		    else
		      nQueens(k+1,n,x);
		}
	}
}

int Place(int k,int i,int x[size])
{
	int j;
	for(j=1;j<=k-1;j++)
	{
		if(x[j]==i || (abs(x[j]-i)==abs(j-k)))
		   return 0;
	}
	return 1;
}
