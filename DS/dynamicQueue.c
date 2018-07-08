#include<stdio.h>
#include<stdlib.h>
struct Queue
{
	int data;
	struct Queue* next,*rear,*front;
};
struct Queue* createQueue()
{
    struct Queue* queue=(struct Queue*)malloc(sizeof(struct Queue));
    queue->front=queue->rear=NULL;
    return queue;
}
struct Queue* createNode(int data)
{
	struct Queue* temp=(struct Queue*)malloc(sizeof(struct Queue));
	temp->data=data;
	temp->next=NULL;
	return temp;
}
void enqueue(struct Queue* queue,int data)
{
    struct Queue* temp=createNode(data);
	if(queue->rear==NULL)
	   queue->rear=queue->front=temp;
	queue->rear->next=temp;
	queue->rear=temp;
}
int dequeue(struct Queue* queue)
{
	if(queue->front==NULL)
	{
	   printf("\nqueue is empty"); 
	   return -1;
    }
	struct Queue* temp=queue->front;
	queue->front=queue->front->next;
	
	if(queue->front==NULL)
	    queue->rear=NULL;
	return temp->data;
}
void front(struct Queue* queue)
{
	if(queue->front!=NULL)
	   printf("%d ",queue->front->data);
	else
	   return;
}
void rear(struct Queue* queue)
{
	if(queue->rear!=NULL)
	   printf("%d ",queue->rear->data);
	else
	   return;
}
void display(struct Queue* queue)
{
	if(queue->front!=NULL)
	{
    	struct Queue* temp=queue->front;
    	while(temp!=queue->rear)
	  {
		  printf("%d ",temp->data);
		  temp=temp->next;
      }
       printf("%d ",temp->data);
    }
    else
      printf("\nqueue is empty");
}
main()
{
   int key,choice;
	struct Queue* queue=createQueue();
	do
	{
		printf("\n1.Insert an element ");
		printf("\n2.Delete an element ");
		printf("\n3.Front");
		printf("\n4.Rear");
		printf("\n5.Display");
		printf("\n6.Exit");
	    printf("\nEnter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\nenter an element you want to insert:");
			       scanf("%d",&key);
			       enqueue(queue,key);
			       break;
		    case 2:key=dequeue(queue);
		           printf("\nDeleted element is %d",key);
		           break;
		    case 3:front(queue);
		           break;
		           
		    case 4:rear(queue);
		           break;
		    case 5:display(queue);
		           break;
		    case 6:exit(0);
			
		}
	}while(choice!=6);	
}
