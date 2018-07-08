#include<stdio.h>
#define max 50
void setdata(float[max][max],int);
void getdata(float[max][max],int);
float prims(float[max][max],int,int[max][2]);
main()
{
	int n,t[max][2],i,j;
	float cost[max][max],k;
	
	printf("\nenter the number of vertices");
	scanf("%d",&n);
	setdata(cost,n);
	getdata(cost,n);
	k=prims(cost,n,t);
	printf("\nminimum cost is");
	printf("%d",k);
	
	printf("\nspanning tree is");
	for(i=1;i<=n;i++)
	printf("\n");
	  for(j=1;j<=2;j++)
	  {
	  	  printf("%d\t",t[i][j]);
	  }

}
void setdata(float cost[][max],int n)
{
	int i,j;
	printf("\nenter the cost adjacency matrix");
    
	for(i=1;i<=n;i++)
	  for(j=i+1;j<=n;j++)
	  {
	  	  printf("\nenter the cost of vertex %d,%d\t",i,j);
	  	  scanf("%f",&cost[i][j]);
	  	  
	  	  cost[j][i]=cost[i][j];
	  }
}
void getdata(float cost[][max],int n)
{
	int i,j;
	
	for(i=1;i<=n;i++)
	{
		printf("\n");
		for(j=1;j<=n;j++)
		{
			printf("%f\t",cost[i][j]);
		}
	}
}
float prims(float cost[max][max],int n,int t[max][2])
{
	int i,j,k,l,near[max]={0},m;
	float min=cost[1][2],mincost=0.0;
	for(i=1;i<=n;i++)
	  for(j=i+1;j<=n;j++)
	  {
	  	  if(cost[i][j]<min)
	  	  {
	  	  	 min=cost[i][j];
	  	  	 k=i;
	  	  	 l=j;
		  }
	  }
	  printf("\nmin%f",min);
	  mincost=mincost+cost[k][l];
	  t[1][1]=k;
	  t[1][2]=l;
	  for(i=1;i<=n;i++)
	  {
	     if(cost[i][k]<cost[i][l])
	       near[i]=k;
	     else
	       near[j]=l;
      }
      for(i=1;i<=n;i++)
        printf("%d",near[i]);
        
      near[k]=near[l]=0;
      for(i=2;i<=n-1;i++)
      {
      	 min=999;
      	 for(j=1;j<=n;j++)
      	 { 
		     if(near[j]!=0 && cost[j][near[j]]<min)
		     {
		     	  min=cost[j][near[j]];
		     	  m=j;
			 }
		 }
		 t[i][1]=m;
		t[i][2]=near[m];
		mincost=mincost+cost[m][near[m]];
		printf("\nmincost%f",mincost);
		near[m]=0;
		for(k=1;k<=n;k++)
		{
			if(near[k]!=0 && cost[k][near[k]]>cost[k][m])
			{
				near[k]=m;
			}
		}
	  }
	  return mincost; 
}







