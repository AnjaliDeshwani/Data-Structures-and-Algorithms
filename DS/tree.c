#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left,*right;
};
struct node* getnode(int x)
{
	struct node* q=(struct node*)malloc(sizeof(struct node));
	q->data=x;
	q->left=NULL;
	q->right=NULL;
	return q;
}
void insert(struct node** tree,int x)
{
	struct node* p,*q,*parent;
	q=getnode(x);

	if(*tree==NULL)
	{
	
		*tree=q;
		return;
	}
	else
	{
		parent=NULL;
		p=*tree;
		while(p!=NULL)
		{
		   parent=p;
		   if(x<p->data)
		      p=p->left;
		    else
		    p=p->right;
		}
		if(x<parent->data)
		    parent->left=q;
		 else   
		 parent->right=q;
		
	}
	return;
	 
}
void pretrav(struct node* tree)
{
	if(tree!=NULL)
	{
       printf("%d ",tree->data);
	   pretrav(tree->left);	
	   pretrav(tree->right);		
	}
	
}
void intrav(struct node* tree)
{
	if(tree!=NULL)
	{
	   pretrav(tree->left);	
	   printf("%d ",tree->data);
	   pretrav(tree->right);		
	}

}
void post_trav(struct node* tree)
{
	if(tree!=NULL)
	{
	   pretrav(tree->left);	
	   pretrav(tree->right);	
	   printf("%d ",tree->data);	
	}

}
struct node* search_min(struct node* tree)
{
	if(tree==NULL || tree->left==NULL)
	    return tree;
     return(search_min(tree->left));
}
struct node* search_max(struct node* tree)
{
	if(tree==NULL || tree->right==NULL)
	    return tree;
     return(search_max(tree->right));
}
int count_leaves(struct node* tree)
{
	if(tree==NULL)
	 return 0;
	else if((tree->left==NULL)&&(tree->right==NULL))
	 return 1;
	return(count_leaves(tree->left) + count_leaves(tree->right));
}
int count_nonleaves(struct node* tree)
{
	if((tree==NULL) || ((tree->left==NULL) && (tree->right==NULL)))
	 return 0;
	return(1 + count_nonleaves(tree->left) + count_nonleaves(tree->right));
}
int count_nodes(struct node* tree)
{
	if(tree==NULL)
	 return 0;
	return(1 + count_nodes(tree->left) + count_nodes(tree->right));
}
int depth(struct node* tree)
{
	int leftdepth,rightdepth;
	if(tree == NULL)
	   return 0;
	else
	{
		leftdepth=depth(tree->left);
		rightdepth=depth(tree->right);
		if(leftdepth > rightdepth)
		   return(1 + leftdepth);
		return(1 + rightdepth);
	}
}
struct node* mirrorImage(struct node* tree)
{
	struct node* p;
	if(tree!=NULL)
	{
		mirrorImage(tree->left);
		mirrorImage(tree->right);
		p=tree->left;
		tree->left=tree->right;
		tree->right=p;
	}
	return tree;
}
struct node* search(struct node* tree,int x)
{
	if(tree==NULL)
	  return NULL;
	if(tree->data==x)
	   return tree;
	if(x<tree->data)
	   return (search(tree->left,x));
   return	search(tree->right,x);
}
void del(struct node** tree,int x)
{
   struct node* p,*suc,*parentsuc,*parent=NULL,*q;
   if(tree==NULL)
   {
   	  printf("\ntree is empty");
   	     return;
   }
   p=*tree;
   while((p!=NULL) && (p->data!=x))
   {
   	 parent=p;
   	 p=(x<p->data)?p->left:p->right;
   }
   if(p==NULL)
   {
   	 printf("\nvalue not found");
   	 return;
   }
   if((p->left==NULL) && (p->right==NULL))
      q=NULL;
    else if(p->left==NULL)
      q=p->right;
    else if(p->right==NULL)
      q=p->left;
    else
    {
       parentsuc=p;
       suc=p->right;
       while(suc->left!=NULL)
       {
       	  parentsuc=suc;
       	  suc=suc->left;
	   }
	   if(parentsuc==p)
	     suc->left=p->left;
	   else
	   {
	   	  suc->left=p->left;
	   	  parentsuc->left=suc->right;
	   	  suc->right=p->right;
	   }
	   q=suc;
	}
	if(parent==NULL)
	{
		*tree=q;
	}
	else if(parent->left==p)
	 parent->left=q;
	else
	 parent->right=q;
	 free(p);
}
struct node* deltree(struct node* tree)
{
	if(tree!=NULL)
	{
	  deltree(tree->left);
	  deltree(tree->right);
	  free(tree);
	  tree=NULL;  
    }
    return tree;
}
main()
{
	struct node *tree=NULL,*mirror,*p;
	int x,ch;
 do
 {
    printf("\n1.Insert a node");	
    printf("\n2.Inorder traverasal");
    printf("\n3.Preorder traversal");
    printf("\n4.Postorder traversal");
    printf("\n5.Search minimum element");
    printf("\n6.Search maximum element");
    printf("\n7.Count leaf nodes");
    printf("\n8.Count non-leaf nodes");
    printf("\n9.Count no. of nodes");
    printf("\n10.Depth of tree");
    printf("\n11.Mirror Image of a tree");
    printf("\n12.Search the element");
    printf("\n13.Delete the element");
    printf("\n14.Delete whole tree");
    printf("\n15.exit..");
    printf("\nEnter Your choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("\nEnter the value to be inserted");
             scanf("%d",&x);
             insert(&tree,x);
             break;
      case 2:intrav(tree);
             break;
      case 3:pretrav(tree);
             break;
	  case 4:post_trav(tree);
	         break;
      case 5:p=search_min(tree);
             printf("\nMin no. is%d",p->data);
             break;
      case 6:p=search_max(tree);
             printf("\nMax no. is%d",p->data);
             break;
      case 7:x=count_leaves(tree);
             printf("\nno. of leaves %d",x);
             break;
      case 8:x=count_nonleaves(tree);
             printf("\nno. of non-leaf nodes %d",x);
             break;
      case 9:x=count_nodes(tree);
             printf("\nno. of nodes %d",x);
             break;
      case 10:x=depth(tree);
              printf("\ndepth of tree is %d",x);
              break;
      case 11:mirror=mirrorImage(tree);
             pretrav(mirror);
             break;
      case 12:printf("\nEnter the value to be searched");
             scanf("%d",&x);
             p=search(tree,x);
             if(p!=NULL)
                printf("\nvalue found is %d",p->data);
             else
               printf("\nvalue not found");
             break;
      case 13:printf("\nEnter the node to be deleted");
             scanf("%d",&x);
             del(&tree,x);
             break;
      case 14:tree=deltree(tree);
              if(tree==NULL)
                printf("\ntree is deleted");
              break;
    }
 }while(ch!=15);
}

