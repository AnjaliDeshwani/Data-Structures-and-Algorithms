#include<stdio.h>
#define size 30

void dft(int adj[][size],int visited[size],int n);
void dfs(int adj[][size],int visited[size],int i,int n);
void setdata(int adj[][size],int n);
void getdata(int adj[][size],int n);

main()
{
	int n,visited[size],i,adj[size][size];
	printf("\nEnter the no. of vertices");
	scanf("%d",&n);
	
	printf("CONDITIONS\n");
	printf("\nvalue=0,if it is the same vertex\n");
	printf("\nvalue=1,if an edge exists\n");
	printf("\nvalue=999,if no edge exists\n");
	
	printf("\nEnter the value in the adjacency matrix");
	setdata(adj,n);
	
	printf("\nValue of the adjacency matrix");
	getdata(adj,n);
	
	printf("\n\n");
	
	dft(adj,visited,n);
	
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
	  for(j=1;j<=n;j++)
	  {
	  	  printf("\t%d",adj[i][j]);
	  }	  
   }  
}
void dft(int adj[][size],int visited[size],int n)
{
	int i,j;
	for(i=1;i<=n;i++)
      visited[i]=0;
    for(i=1;i<=n;i++)
    {
    	if(visited[i]==0)
    	{
    	   dfs(adj,visited,i,n);
        }
	}          
}
void dfs(int adj[][size],int visited[size],int i,int n)
{
   int j,k;
   visited[i]=1;
   printf("%d\t",i);
   for(k=1;k<=n;k++)
   {
   	   if(adj[i][k]==1 && visited[k]==0)
   	   {
   	   	     dfs(adj,visited,k,n);
	   }
   }
}


