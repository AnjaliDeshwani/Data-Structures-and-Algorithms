#include<stdio.h>
#define size 20
void mColoring(int,int adj[][size],int n,int x[size],int m);
void nextValue(int,int adj[][size],int n,int x[size],int m);
void setdata(int adj[][size],int n);
void getdata(int adj[][size],int n);
main()
{
	int n,x[size],adj[size][size],m,i;
	printf("Enter the no. of vertices");
	scanf("%d",&n);
	printf("\nEnter the no. of colors");
	scanf("%d",&m);
	
	printf("\nvalue=0,if no edge exits\n");
	printf("\nvalue=1,if an edge exists\n");
	
	printf("\nEnter the value in the adjacency matrix");
	setdata(adj,n);
	
	printf("\nValue of the adjacency matrix");
	getdata(adj,n);
	
	for(i=1;i<=n;i++)
	   x[i]=0;
	mColoring(1,adj,n,x,m);
	
}
void setdata(int adj[][size],int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
	  for(j=i+1;j<=n;j++)
	  {
	  	  printf("\nEnter the value of vertex %d\t%d",i,j);
	  	  scanf("%d",&adj[i][j]);
	  	  adj[j][i]=adj[i][j];
	  }
	  adj[i][i]=0;	  
   }  
}
void getdata(int adj[][size],int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
	  printf("\n");
	  for(j=1;j<=n;j++)
	  {
	  	  printf("\t%d",adj[i][j]);
	  }	  
   }  
}

void mColoring(int k,int adj[][size],int n,int x[size],int m)
{

	int i;
	do
	{
		nextValue(k,adj,n,x,m);
		if(x[k]==0)
		{
			return;
		}
		if(k==n)
		{
			printf("\n");
		   for(i=1;i<=n;i++)
		     printf("%d",x[i]);	
		}
		else
		 mColoring(k+1,adj,n,x,m);
	}while(1);
}

void nextValue(int k,int adj[][size],int n,int x[size],int m)
{

	int j;
	do
	{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0)
		{
			return;
		}
		for(j=1;j<=n;j++)
		{
			if((adj[j][k]!=0) && (x[k]==x[j]))
			   break;
		}
		if(j==n+1)
		  return;
	}while(1);
}
