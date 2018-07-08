#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
void insert_beg(struct node** head,int key)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=key;
	new_node->next=*head;
	*head=new_node;	
}
void insert_end(struct node** head,int key)
{
	struct node* last;
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=key;
	new_node->next=NULL;
	if(*head==NULL)
	{
	   *head=new_node;
	   return;
    }
    last=*head;
	while(last->next!=NULL)
	    last=last->next;
    last->next=new_node;
}
void insert_after(struct node** temp,int key)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	
	new_node->data=key;
	new_node->next=(*temp)->next;
	(*temp)->next=new_node;
}
void delete_beg(struct node** head)
{
	struct node* temp;
  
    temp=(*head);
    *head=(*head)->next;
    free(temp);
}
void delete_end(struct node** head)
{
	struct node* r,* p;
   
    p=(*head);
    while(p->next!=NULL)
	{
	    r=p;
	    p=p->next;
    }
    r->next=NULL;
    free(p);
}
void delete_at(struct node** head,int value)
{
	int flag=0;
	struct node* r,*p;
    p=*head;
    while(p->data!=value)
	{
	    r=p;
	    p=p->next;
    }
    if(p!=NULL)
   {
    r->next=p->next;
    free(p);
  
   }
   else
      printf("\nnode doesn't exist");
   
} 

void display(struct node* head)
{
	while(head!=NULL)
	{
	  printf("\n%d",head->data);
	  head=head->next;
    }
}
struct node* search(struct node* head,int value)
{
	struct node* temp=head;
	while(temp!=NULL)
	{
		if(temp->data==value)
		   return temp;
		temp=temp->next;
	}
}
main()
{
  int key,value,value1,choice;
  struct node* head=NULL,*temp=NULL;
  	x: do
	{
		printf("\n1.Insert node at beginning");
		printf("\n2.Insert node at end");
		printf("\n3.Insert node after");
		printf("\n4.Delete beginning node");
		printf("\n5.Delete end node");
		printf("\n6.Delete node ");
		printf("\n7.Display");
		printf("\n8.Exit..");
		printf("\n.Enter your choice");
		scanf("%d",&choice);
		if(choice==3||choice==4||choice==5||choice==6||choice==7)
		{
			if(head==NULL)
			{
		    	printf("\nlist is empty");
		    	goto x;
		    }
		}
		if(choice==1||choice==2||choice==3)
		{
			printf("\nenter the node you want to insert:");
			scanf("%d",&key);
		}
		
		switch(choice)
		{
			case 1:insert_beg(&head,key);
			       break;
			case 2:insert_end(&head,key);
			       break;
			case 3:printf("\nenter the node after which you want to insert:");
			       scanf("%d",&value);
			       temp=search(head,value);
			       insert_after(&temp,key);
			       break;
		    case 4:delete_beg(&head);
			       break;
			case 5:delete_end(&head);
			       break;
			case 6:printf("\nenter the node  which you want to delete:");
			       scanf("%d",&value1);
			       delete_at(&head,value1);
			       break;
		    case 7:display(head);
		           break;
		  
		}
	}while(choice!=8);
}
