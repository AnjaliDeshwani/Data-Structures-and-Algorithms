#include<stdio.h>
int job_sequencing(int j[],int d[],int n);
void swap(int*,int*);
main()
{
	int n,i,j,k,d[20],J[20],p[20],q[20];
	printf("\nEnter the no. of jobs");
	scanf("%d",&n);
	printf("\nEnter the deadlines and profit of the  ");
	for(i=1;i<=n;i++)
	{
	 printf("job no. %d :",i);
	 scanf("%d %d",&d[i],&p[i]);
    }
	for(i=1;i<=n;i++)
	  q[i]=p[i];
	
	 for(i=1;i<n;i++)
	 {
	   for(j=i+1;j<=n;j++)
	   {
	   	  if(p[j]>p[i])
	   	  {
	  	  	swap(&p[j],&p[i]);
	   	  	
	   	  	swap(&d[j],&d[i]);
		  }
	   }
     }
     printf("\n\ndeadlines[] ");
     for(i=1;i<=n;i++)
	    printf("%d\t",d[i]); 
	
	 printf("\n\nprofit[]");
     for(i=1;i<=n;i++)
	    printf("%d\t",p[i]);  
	    
    k=job_sequencing(J,d,n);
    printf("\nresult is:");
    for(i=1;i<=k;i++)                     //mapping 
      for(j=1;j<=n;j++)
      {
      	 if(p[J[i]]==q[j])
      	 {
      	    printf("%d \t",j);
      	    break;
         }
	  }
}
int job_sequencing(int J[],int d[],int n)
{
	
	int k,r,q,i;
	J[0]=d[0]=0;
	J[1]=1;
	k=1;
	for(i=2;i<=n;i++)
	{
	  r=k;
	 
	  while((d[J[r]]>d[i]) && (d[J[r]]!=r))
	       r=r-1;

	  if((d[J[r]]<=d[i]) && (d[i]>r))
	  {

	  	  for(q=k;q>=r+1;q--)
	  	  	  J[q+1]=J[q];
	  	  J[r+1]=i;
	  	  k=k+1;
	  }
    }
  

    return k;
}
void swap(int* p1,int* p2)
 {
 	int temp;
 	temp=*p1;
 	*p1=*p2;
 	*p2=temp;
 }

