#include<stdio.h>
#include <stdlib.h>

struct Stack 
{
   int data;
   struct Stack* next;
};

struct Stack* newNode(int data)
{
	struct Stack* stacknode=(struct Stack*)malloc(sizeof(struct Stack));
	stacknode->data=data;
	stacknode->next=NULL;
	return stacknode;
}
void push(struct Stack** root,int key)
{
       struct Stack* node=newNode(key);
       node->next=*root;
       *root=node;
}
int pop(struct Stack** root)
{
	if(!isEmpty(*root))
	{
		struct Stack* temp=*root;
	    int key=temp->data;
	    *root=(*root)->next;
	    free(temp);
	    return key;
    }
	   return -1;
}

int isEmpty(struct Stack* root)
{
	return !root;
}
void display(struct Stack* root)
{
     if(!isEmpty(root))
     {
     	while(root->next!=NULL)
     	{
     		printf("\n%d",root->data);
     		root=root->next;
		 }
		 printf("\n%d",root->data);
	 }
	 else
	    printf("\nstack is empty");
}
int peek(struct Stack* root)
{
	if(!isEmpty(root))
	{
		int key=root->data;
		return key;
	}
	else
	    printf("\nstack is empty");
}
main()
{
	int choice,key;
    struct Stack* root=NULL;
 	do
	{
		printf("\n1.Push an element");
		printf("\n2.Pop an element");
		printf("\n3.Display");
		printf("\n4.To view top node");
		printf("\n5.Exit..");
		printf("\n.Enter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\nenter an element you want to push:");
			       scanf("%d",&key);
			       push(&root,key);
			       break;
		    case 2:key=pop(&root);
		           printf("\nPopped element is %d",key);
		           break;
		    case 3:display(root);
		           break;
		    case 4:key=peek(root);
		           printf("\nTop element is %d",key);
			       break;
		}
	}while(choice!=5);
}

