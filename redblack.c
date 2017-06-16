//Implementation of Red Black Trees
//The Red Node is indicated as 0 and the black node is indicated as 1
#include<stdio.h>
#include<stdlib.h>
int flag = 0;
struct node
{
	int key;
	struct node* lchild;
	struct node* rchild;
	struct node* parent;
	int color;
};
typedef struct node* NODE;

NODE getnode()
{
	NODE x;
	x = (NODE)malloc(sizeof(struct node));
	if(x == NULL)
		exit(0);
	return x;
}

NODE leftRotate(NODE root,NODE x)
{
	NODE y = x->rchild;
	x->rchild = y->lchild;
	if(y->lchild!=NULL)
		y->lchild->parent = x;
	y->parent = x->parent;
	if(x->parent == NULL)
		root = y;
	else if(x == x->parent->lchild)
		x->parent->lchild =y;
	else if(x->parent->rchild == x)
		x->parent->rchild = y;
	
	y->lchild = x;
	x->parent = y;
	return root;
}

NODE rightRotate(NODE root,NODE x)
{
	NODE y = x->lchild;
	x->lchild = y->rchild;
	
	if(y->rchild!=NULL)
		y->rchild->parent = x;
	y->parent = x->parent;
	if(x->parent == NULL)
		root = y;
	else if(x->parent->lchild == x)
		x->parent->lchild = y;
	else if(x->parent->rchild == x)
		x->parent->rchild = y;
	
	y->rchild = x;
	x->parent = y;
	return root;
}
	
void inorder(NODE root)
{
	if(root == NULL)
		return;
	inorder(root->lchild);
	printf("%d,%d\t",root->key,root->color);
	inorder(root->rchild);
}
	

int black(NODE root)
{
	if(root == NULL)
		return 0;
	int p,q;
	if(root->color == 1)
	{
	
		p = 1+black(root->lchild);
		q = 1+ black(root->rchild);
	}
	if(p!=q)
		flag =1;
	
	return p;
}
			
void redcheck(NODE root)
{
	if(root == NULL)
		return;
	redcheck(root->lchild);
	redcheck(root->rchild);
	if(root->lchild!=NULL)
		if(root->color == 0 && root->lchild->color == 0)
		{
			flag = 1;
			return;
		}
	if(root->rchild!=NULL)
		if(root->color == 0 && root->rchild->color == 0)
		{
			flag = 1;
			return;
		}
		
		
}	 
	
	


NODE insert(NODE root,int value)
{
	NODE NN =getnode();
	NN->lchild =NULL;
	NN->rchild = NULL;
	NN->key = value;
	if(root == NULL)
	{
		NN->color = 1;
		NN->parent = NULL;
		return NN;
	}
	
	NODE CN,PN;
	PN = NULL;
	CN = root;
	while(CN!=NULL)
	{
		PN = CN;
		if(value < CN->key)
			CN = CN->lchild;
		else CN = CN->rchild;
	}
	if(value<PN->key)
		PN->lchild = NN;
	else
		PN->rchild = NN;
	NN->parent = PN;
	NN->color = 0;
	NODE x=NN;
	NODE uncle,y;
	while(x!=root && x->parent->color == 0)
	{
		if(x->parent == x->parent->parent->lchild)
		{
			y = x->parent->parent->rchild;
			if(y == NULL || y->color == 1) 
			{
				if(x == x->parent->rchild)
				{
					x = x->parent;
					root = leftRotate(root,x);
				}
			
				x->parent->color = 1;
				x->parent->parent->color = 0;
				root = rightRotate(root,x->parent->parent);
			}
			else
			{
				x->parent->color =  1;
				y->color = 1;
				x->parent->parent->color = 0;
				x = x->parent->parent;
			}
			
		}	
		else
		{
			y = x->parent->parent->lchild;
			if(y==NULL || y->color == 1)
			{
			 	if(x == x->parent->lchild)
				{
					x = x->parent;
					root = rightRotate(root,x);
				}
				x->parent->color = 1;
				x->parent->parent->color = 0;
				root = leftRotate(root,x->parent->parent);
			}
			else
			{
				x->parent->color =  1;
				y->color = 1;
				x->parent->parent->color = 0;
				x = x->parent->parent;
			}
			
		}		
		
	}
	root->color=1;
	
	return root;
}	
	

NODE insuc(NODE root)
{
	NODE P = root->rchild;
	while(P->lchild != NULL)
		P = P->lchild;
	return P;

}
void exchange(NODE root,NODE u,NODE v)
{
	if(u->parent == NULL)
		root = v;
	else if( u->parent->lchild == u)
		u->parent->lchild = v;
	else
		u->parent->rchild = v;
	v->parent = u->parent;
}


	
void main()
{
	int choice,value,flag = 0;
	NODE root = NULL;
	
	
	while(1)
	{
		printf("\nEnter choice:\n1-Insert\n2-Delete\n3-Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nEnter value to be entered:\n");
				scanf("%d",&value);
				root = insert(root,value);
				break;
			case 2:printf("Enter the vlue to be deleted:\n");
				scanf("%d",&value);
				//root = delete(root,value);
				break;
			case 3: inorder(root);
				break;
				
			case 4:	redcheck(root);
				if(root != NULL)
					if(black(root->lchild)!=black(root->rchild))
						flag = 1;
				
				if(flag)
					printf("Tree isnt red black balanced");
				else
					printf("Tree is red black balanced");
				break;
				
						
			default: free(root);
				exit(0);
				
		}
	}
}
		
