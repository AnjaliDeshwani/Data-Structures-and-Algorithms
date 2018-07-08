//Sorting using heap
#include<stdio.h>
void insert(int a[],int n,int x)
{
	int i,item;
	n=n+1;
	a[n]=x;
	i=n;
	item=a[n];
	while((i>1) && (a[i/2]<item))
	{
		a[i]=a[i/2];
		i=i/2;
	}
	a[i/2]=item;
	//return n;
}
void adjust(int a[],int i,int n)
{
	int j,item=a[i];
	j=i*2;
	while(j<=n)
   {
	if((j<n) && (a[j]<a[j+1]))
	{
		j++;
	}
	if(item>=a[j])
	  break;
	a[j/2]=a[j];
	j=2*j;
   }
   a[j/2]=item;
}
void delmax(int a[],int n,int *x)
{
	if(n==0)
	{
		*x=-999;
	}
	*x=a[1];
	a[1]=a[n];
	n=n-1;
	adjust(a,1,n);
	//return n;
	
}
void insertSort(int a[],int num)
{
	int x,i,n;
	printf("\n1.gggh");
	for(n=0;n<num;n++)
	{
	 printf("\nEnter an element -");
	 scanf("%d",&x);
	 insert(a,n,x);
    }
    	printf("\n3.gggh");
    for(n=num;n>=1;n--)
    {
    		printf("\n4.gggh");
    	delmax(a,n,&x);
    	a[n]=x;
	}	
}

main()
{
	int num,a[25],i;
	printf("\nEnter the number of nodes to be inserted");
	scanf("%d",&num);
	insertSort(a,num);
	printf("\nSorted array is :");
	for(i=1;i<=num;i++)
	  printf("%d\n",a[i]);
}
