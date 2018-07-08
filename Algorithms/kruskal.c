#include<stdio.h>
# define size 50
struct node 
{
   int u,v;
   float cost;
};

int create(float cost[][size], int n,struct node edge[] )
{
	int f, i, j,c=0;

	for(i=1;i<=n;i++)
 	     for(j=i;j<=n;j++)
 	     {
 	     	if(i!=j)
 	     	{
 	     		printf("\nif edge exists,enter 1\n");
 	     		printf("\nif no edge exists,enter 0\n");
 	     		printf("\nDo you have an edge between %d and %d", i, j);
 	     		scanf("%d", &f);
 	     		
 	     		if(f)
 	     		{
 	     			printf("\nEnter the cost of the edge: ");
 	     			scanf("%f", &cost[i][j]);

 	     			cost[j][i]=cost[i][j];
 	     			c++;
               edge[c].u=i;
 	     			edge[c].v=j;
 	     			edge[c].cost=cost[i][j];
                
                }
 	     		else
				 	cost[i][j]=cost[j][i]=999;
     		}
     		else
     			cost[i][j]=0;
		 }
 	     
   
	return c;
}

void adjust(struct node edge[],int i,int n)
{
	int j;struct node item;
	j=2*i;
	item=edge[i];
	while(j<=n)
	{
		if((j<n) && edge[j].cost>edge[j+1].cost)
		j++;
		if(item.cost<edge[j].cost)
		break;
		edge[j/2]=edge[j];
		j=2*j;
	}
	edge[j/2]=item;
}


void heapify(struct node edge[],int n)
{
	int i;
	for(i=n/2;i>=1;i--)
	adjust(edge,i,n);
}

int find(int parent[], int i)
{
   while(parent[i]>0)
     i=parent[i];
     
     return i;
     
}

void union1(int parent[],int i, int j)
{
   parent[i]=j;
   
}

int del(struct node edge[], int n)
{
   if(n==0)
   {printf("heap empty");
   return  0;
   }
   else
   {
      edge[1]=edge[n];
      n=n-1;
      adjust(edge,1,n);
      return n;
   }
   
}

float kruskal(struct node edge[], float cost[][size], int n, int t[][size],int e)
{
   int i,j,a,b,u,v,parent[size];
   float mincost=0.0;
      for(i=1;i<=n;i++)
	    parent[i]=-1;
	i=0;j=1;
	while((i<n-1)&&(e!=0))
	{
	   u=edge[j].u;
	   v=edge[j].v;
	   e=del(edge,e);
         
	   a=find(parent,u);
	   b=find(parent,v);
	   
	   if(a!=b)
	   {
	      i++;
	      t[i][1]=u;
	      t[i][2]=v;
	      
	      mincost=mincost+cost[u][v];
	      
	      union1(parent,a,b);
	      
      }
	   
   }
   if(i!=n-1)
	printf("No spanning tree");
	else
	return mincost;

}

int main()
{
	int n, j,e,i,parent[size],t[size][size];
	struct node edge[size];
	float cost[size][size],mincost=0.0;
	
	printf("Enter no of vertices:");
	scanf("%d",&n);
	
	e=create(cost,n,edge);

   heapify(edge,e);
  
   mincost=kruskal(edge,cost,n, t,e);
   
   printf("\nEdges included are:");
	for(i=1;i<=n-1;i++)
		printf("\n(%d, %d)", t[i][1], t[i][2]);
   
   printf("\n Minimum cost is %f", mincost);

}



