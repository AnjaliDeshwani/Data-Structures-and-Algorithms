#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* createnode(int data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));;
	temp->next=NULL;
	temp->data=data;
	return temp;
}
struct node* search(struct node** last,int value)
{
	struct node* temp=(*last)->next;
	do
	{
		if(temp->data==value)
		   return temp;
		temp=temp->next;
	}while(temp!=(*last)->next);
    
    return NULL;
}
void insert_beg(struct node** last,int data)
{
	struct node* new_node=createnode(data);
	if(*last==NULL)
	{
	  (*last)=new_node;
	  (*last)->next=*last;
    }
	new_node->next=(*last)->next;
	(*last)->next=new_node;
}
void insert_end(struct node** last,int data)
{
	struct node* new_node=createnode(data);
	if(*last==NULL)
	{
	   *last=new_node;
	  (*last)->next=*last;
	    return;
    }
    new_node->next=(*last)->next;
    (*last)->next=new_node;
    *last=new_node;
}
void insert_after(struct node** last,int data,int value)
{
	if(*last==NULL)
	   return;
	struct node* temp=search(last,value);
	struct node* new_node=createnode(data);
	if(temp!=NULL)
	{
	   new_node->next=temp->next;
	   temp->next=new_node;
	   if(temp==*last)
         *last=new_node;
    }
    else
        printf("\ngiven value not found and hence the node cannot be inserted");
}
void delete_beg(struct node** last)
{
	struct node* temp;
	 if((*last)->next==*last)
	 {
	 	temp=(*last);
	 	printf("\ndeleted node is %d",temp->data);
	 	free(temp);
	 	*last=NULL;
	 	return;
	 	//(*last)->next=NULL;
	 //	free(last);
	 }
    if(*last!=NULL)
  {
     temp=(*last)->next;
     (*last)->next=(temp)->next;
     printf("\ndeleted node is %d",temp->data);
     free(temp);
  }
  else
     printf("\nno node exists");
}
void delete_end(struct node** last)
{
	struct node* p,*r,*temp;
	if((*last)->next==*last)
	 {
	 	temp=(*last);
	 	printf("\ndeleted node is %d",temp->data);
	 	free(temp);
	 	*last=NULL;
	 	return;
	 	//(*last)->next=NULL;
	 }
    if(*last!=NULL)
    {
      p=(*last)->next;
      r=(*last);
      while(p->next!=*last)
	  {
	    p=p->next;
      }
      p->next=(*last)->next;
      *last=p;
      printf("\ndeleted node is %d",r->data);
      free(r);
    }
    else
     printf("\nno node exists");
}
void delete_at(struct node** last,int value)
{
	int flag=0;
	struct node* r,*p;
    p=*last;
    while(p->data!=value)
	{
	    r=p;
	    p=p->next;
    }
    if(p->data==value)
   {
     r->next=p->next;
   
     if(p==*last)
     {
   	   *last=r;
     }
     printf("\ndeleted node is %d",p->data);
    free(p);
   }
   else
      printf("\nnode doesn't exist");
   
} 

void display(struct node* last)
{
	struct node* temp=(last)->next;
	 printf("\n");
	do
	{
	    printf("\n%d ",temp->data);
		temp=temp->next;
	}while(temp!=(last)->next);

}

main()
{
  int key,value,value1,choice;
  struct node* last=NULL,*temp=NULL;
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
			if(last==NULL)
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
			case 1:insert_beg(&last,key);
			       break;
			case 2:insert_end(&last,key);
			       break;
			case 3:printf("\nenter the node after which you want to insert:");
			       scanf("%d",&value);
			       insert_after(&last,key,value);
			       break;
		    case 4:delete_beg(&last);
			       break;
			case 5:delete_end(&last);
			       break;
			case 6:printf("\nenter the node  which you want to delete:");
			       scanf("%d",&value1);
			       delete_at(&last,value1);
			       break;
		    case 7:printf("\nelements of the singly circular linked list are:");
			       display(last);
		           break;
		  
		}
	}while(choice!=8);
}
