//Level order traversal of binary tree
#include<stdio.h>
#define size 30
//structure is declared to store the no. of unexplored vertices
struct queue
{
	int front,rear;
	int items[size];
};
void bft(int adj[][size],int visited[size],int n);
void bfs(int adj[][size],int visited[size],int i,int n);
void setdata(int adj[][size],int n);
void getdata(int adj[][size],int n);
void insert(struct queue *pq,int x,int n);
int del(struct queue *pq);
int full(struct queue *pq,int n);
int empty(struct queue *pq);
main()
{
	int n,visited[size],i,adj[size][size];    
	printf("\nEnter the no. of vertices");
	scanf("%d",&n);
	//for any node i,visited[i]=1 if i has already been visited
	
	printf("Conditions\n");
	printf("\nvalue=0,if it is the same vertex\n");
	printf("\nvalue=1,if an edge exists\n");
	printf("\nvalue=999,if no edge exists\n");
	
	//adjacency matrix tells whether the edge exists or not between the vertices 
	printf("\nEnter the value in the adjacency matrix");   
	setdata(adj,n);
	
	//to print the value of adjacency matrix
	printf("\n\nValue of the adjacency matrix");   
	getdata(adj,n);
	
	printf("\n\nBreadth first traversal of a graph is\n");
	//breadth first traversal of a graph
	bft(adj,visited,n);                      
	
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
	  	  printf("%d\t",adj[i][j]);
	  }	  
   }  
}


void bft(int adj[][size],int visited[size],int n)
{
	int i,j;
	for(i=1;i<=n;i++)
      visited[i]=0;   //initially all the vertex are unvisited
    for(i=1;i<=n;i++)
    {
    	 //to check whether whether the vertex[i] has been visited or not
    	if(visited[i]==0)  
    	{
    	  	//breadth first search of a graph is carried out for beggining vertex i
    	   bfs(adj,visited,i,n);
        }
	}          
}
void bfs(int adj[][size],int visited[size],int i,int n)
{

	int x,k;
	struct queue q;                 //q is a queue of unexplored vertices
	q.rear=-1;
	q.front=0;
	visited[i]=1;
	insert(&q,i,n);
	printf("\n");
	while((!empty(&q)))             //to check whether q is empty or not
	{
		x=del(&q);                  //get first unexplored vertex
		printf("%d\t",x);
		for(k=1;k<=n;k++)
		{
			if(visited[k]==0 && adj[k][x]==1)
			{
				visited[k]=1;
			    insert(&q,k,n);       //k is unexplored vertex
		    }
		}
	}	
}
void insert(struct queue *pq,int x,int n)
{
	if(!full(pq,n))        
	{
		++(pq->rear);
		pq->items[pq->rear]=x;
	}
	else 
	  return;
}
int del(struct queue *pq)
{
	int x=-1;
	if(!empty(pq))   //to check if there is no unexplored vertex
	{
	   x=(pq->items[pq->front]);
	   (pq->front++);	
	
	}
	return x;
}
int full(struct queue *pq,int n)
{
	if((pq->rear)==n-1)
	   return 1;
	return 0;
}
int empty(struct queue *pq)
{
	if((pq->rear) < (pq->front))
	   return 1;
	return 0;
}


