#include<stdio.h>
#include <stdlib.h>

struct Stack 
{
   int top;
   unsigned capacity;
   int* array;
};

struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
	stack->top=-1;
	stack->capacity=capacity;
	stack->array=(int*)malloc(stack->capacity*sizeof(int));
}
void push(struct Stack* stack,int key)
{
	if(!isFull(stack))
	  stack->array[++stack->top]=key;
	else
	   printf("stack overflow");
}
int pop(struct Stack* stack)
{
	int key;
	if(!isEmpty(stack))
	{
	  key=stack->array[stack->top--];
	    return key;
    }
	return -1;
}
int isFull(struct Stack* stack)
{
	return stack->top==stack->capacity-1;
}
int isEmpty(struct Stack* stack)
{
	return stack->top==-1;
}
void display(struct Stack* stack)
{
	int i;
	if(stack->top!=-1)
	{
	  for(i=stack->top;i>=0;i--)
	    printf("\n%d",stack->array[i]);
    }
    else
      printf("\nstack is empty");
}
main()
{
	int key,choice;
	struct Stack* stack=createStack(100);
	do
	{
		printf("\n1.Push an element");
		printf("\n2.Pop an element");
		printf("\n3.Display");
		printf("\n4.Exit");
	    printf("\nEnter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\nenter an element you want to push:");
			       scanf("%d",&key);
			       push(stack,key);
			       break;
		    case 2:key=pop(stack);
		           printf("\nPopped element is %d",key);
		           break;
		    case 3:display(stack);
		           break;
		    case 4:exit(0);
			
		}
	}while(choice!=4);
}

