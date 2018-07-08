#include<stdio.h>
#define size 20
void hamiltonian(int,int adj[][size],int n,int x[size]);
void nextValue(int,int adj[][size],int n,int x[size]);
void setdata(int adj[][size],int n);
void getdata(int adj[][size],int n);
main()
{
	int n,x[size],adj[size][size],m,i;
	printf("Enter the no. of vertices");
	scanf("%d",&n);
	
	printf("\nvalue=0,if no edge exits\n");
	printf("\nvalue=1,if an edge exists\n");
	
	printf("\nEnter the value in the adjacency matrix");
	setdata(adj,n);
	
	printf("\nValue of the adjacency matrix");
	getdata(adj,n);
	
	x[1]=1;
	for(i=2;i<=n;i++)
	   x[i]=0;
    hamiltonian(2,adj,n,x);
	
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

void hamiltonian(int k,int adj[][size],int n,int x[size])
{

	int i;
	do
	{
		nextValue(k,adj,n,x);
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
		hamiltonian(k+1,adj,n,x);
	}while(1);
}

void nextValue(int k,int adj[][size],int n,int x[size])
{

	int j;
	do
	{
		x[k]=(x[k]+1)%(n+1);
		if(x[k]==0)
		{
			   return;
		}
	    
	    if( adj[x[k-1]][x[k]] != 0)
	    {
	    	
	    	for(j=1;j<=k-1;j++)
	    	  if(x[j]==x[k])
	    	     break;
	    	
	    	if(j==k)
	    	   if((k<n) || ((k=n) && adj[x[k]][x[1]]!=0))
	    	       return;
		}
	
	}while(1);
}
