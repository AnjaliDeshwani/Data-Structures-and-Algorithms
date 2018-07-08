#include<stdio.h>
#define size 20
void SumofSubsets(float,int,float,int[size],float[size],int,int);
main()
{
	int n,i,x[size];
	float m,w[size],r=0.0;
	printf("\nenter the capacity m ");
	scanf("%f",&m);
	printf("\nenter the no. of objects");
	scanf("%d",&n);
	printf("\nenter the weights\n");
	for(i=1;i<=n;i++)
	{
	   scanf("%f",&w[i]);
	   r=r+w[i];
    }
	SumofSubsets(0.0,1,r,x,w,m,n);
}
void SumofSubsets(float s,int k,float r,int x[size],float w[size],int m,int n)
{
	//Generate left child
	int i;
	x[k]=1;
	if(s+w[k]==m)
	{
		printf("\n");
		for(i=1;i<=n;i++)
		  printf("%d",x[i]);
	}
	else if(s+w[k]+w[k+1]<=m)
	  SumofSubsets(s+w[k],k+1,r-w[k],x,w,m,n);
	
	//Generate right child
	
	if((s+r-w[k]>=m) && (s+w[k+1]<=m))
	{
		x[k]=0;
		SumofSubsets(s,k+1,r-w[k],x,w,m,n);
	}
}
