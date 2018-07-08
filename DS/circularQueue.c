#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int size,capacity,front,rear;
	int* array;
};
struct queue* createQueue(int capacity)
{
    struct queue* queue=(struct queue*)malloc(sizeof(struct queue));
    queue->capacity=capacity;
    queue->size=0;
    queue->rear=queue->front=-1;
    queue->array=(int*)malloc(queue->capacity * sizeof(int));
    return queue;
}
void enqueue(struct queue* queue,int key)
{
	if(isFull(queue))
	{
	  printf(" queue is full\n");
	    return;
    }
    if(queue->front==-1)
    {
    	queue->rear=0;
    	queue->front=0;
	}
	 /*else if (queue->rear == queue->capacity-1 && queue->front != 0)
    {
        queue->rear = 0;
    }*/
	else
	{
	  queue->rear=((queue->rear)+1)%(queue->capacity);

    }
    printf("\n rear %d",queue->rear);
    queue->array[queue->rear]=key;  
	queue->size=(queue->size)+1;
	printf("%d enqueued to queue\n",key);
}
int dequeue(struct queue* queue)
{
	if(isEmpty(queue))
	   return -1;
	int key=queue->array[queue->front];
	 printf("\n front %d",queue->front);
    if(queue->front==queue->rear)
    {
    	queue->front=-1;
		queue->rear=-1;
	}
	else
	  queue->front=((queue->front)+1)%(queue->capacity);
	queue->size=(queue->size)-1;
	return key;
}
void front(struct queue* queue)
{
  if(isEmpty(queue))
     return;
  printf("Front is %d: ",queue->array[queue->front]);	
}
void rear(struct queue* queue)
{
   if(isEmpty(queue))
     return;
  printf("Rear is %d: ",queue->array[queue->rear]);		
}
int isEmpty(struct queue* queue)
{ 
    return (queue->front==-1);
		
}
int isFull(struct queue* queue)
{
    return ((queue->rear==queue->capacity-1 && queue->front==0)|| queue->rear==(queue->front)- 1);
}
void display(struct queue* queue)
{
	int i;
	if(!isEmpty(queue))
	{
	   printf("\nElements in Circular Queue are: ");
    if (queue->rear >= queue->front)
    {
        for ( i = queue->front; i <= queue->rear; i++)
            printf("%d ",queue->array[i]);
    }
    else
    {
        for ( i = queue->front; i < queue->capacity; i++)
            printf("%d ", queue->array[i]);
 
        for ( i = 0; i <= queue->rear; i++)
            printf("%d ", queue->array[i]);
     }
    }
    else 
	   printf("queue is empty");	
}
main()
{
	int key,choice;
	struct queue* queue=createQueue(5);
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
