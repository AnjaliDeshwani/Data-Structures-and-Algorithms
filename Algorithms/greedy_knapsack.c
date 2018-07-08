#include<stdio.h>
#include<stdlib.h>
void input(float[],float[],int);
void adjust(float[],float[],int);
void knapsack(float[],float[],int,float);
void swap(float*,float*);
main()
{
	int n;
	float m,w[20],p[20];
	printf("\nenter the capacity of the knapsack");
	scanf("%f",&m);
	printf("\nenter the no. of objects");
	scanf("%d",&n);
	printf("\nenter the weight and profit of each object");
	input(w,p,n);
	adjust(w,p,n);
	knapsack(w,p,n,m);
}
 void input(float w[],float p[],int n)
 {
   int i;
   for(i=0;i<n;i++)
    scanf("%f %f",&w[i],&p[i]); 	
 }
 void adjust(float w[],float p[],int n)
 {
     int i,j;
     float ratio[20];
     for(i=0;i<n;i++)
       ratio[i]=p[i]/w[i];
     
	 for(i=0;i<n-1;i++)
	 {
	   for(j=i+1;j<n;j++)
	   {
	   	  if(ratio[j]>ratio[i])
	   	  {
	   	  	swap(&ratio[j],&ratio[i]);
	   	  	
	   	  	swap(&w[j],&w[i]);
	   	  	
	   	  	swap(&p[j],&p[i]);
		  }
	   }
     }
     printf("\n\nprofit per unit weight ");
     for(i=0;i<n;i++)
	    printf("%f\t",ratio[i]); 
	
	 printf("\n\nprofit[]");
     for(i=0;i<n;i++)
	    printf("%f\t",p[i]); 
	 
	printf("\n\nweight[]");    
	for(i=0;i<n;i++)
	    printf("%f\t",w[i]); 
 }
 
 void knapsack(float w[],float p[],int n,float m)
 {
 	int i;
 	float U=m,x[20],tp=0;
 	for(i=0;i<n;i++)
 	   x[i]=0.0;
 	for(i=0;i<n;i++)
 	{
 	    if(w[i]>U)
		  break;
		 
		 x[i]=1.0;
		 U=U-w[i];
		 tp=tp+p[i];	
	}
	if(i<n)
	{
		x[i]=U/w[i];
		tp=tp+(x[i]*p[i]);
	}
	printf("\n\nthe result is ");
	for(i=0;i<n;i++)
	printf("%f\t",x[i]);
	
	printf("\n\n the total profit is %f",tp);  
 }
 void swap(float* p1,float* p2)
 {
 	float temp;
 	temp=*p1;
 	*p1=*p2;
 	*p2=temp;
 }

