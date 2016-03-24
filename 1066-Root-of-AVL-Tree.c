#include<stdio.h>
#include<stdlib.h>
#define AVL_BALANCED 0
#define AVL_LEFT_HEAVY 1
#define AVL_RIGHT_HEAVY -1
typedef struct bistree_node
{
	int data;
	int factor;
	struct bistree_node *left;
	struct bistree_node *right;
} bistree_node;
typedef struct bistree
{
	bistree_node *root;
} bistree;
bistree_node *roate_left(bistree_node *root)
{
	bistree_node *left,*grandchild;
	left=root->left;
	if(left->factor==AVL_LEFT_HEAVY)
	{
		root->left=left->right;
		left->right=root;
		root->factor=AVL_BALANCED;
		left->factor=AVL_BALANCED;
		return left;
	}
	grandchild=left->right;
	root->left=grandchild->right;
	grandchild->right=root;
	left->right=grandchild->left;
	grandchild->left=left;
	switch(grandchild->factor)
	{
		case AVL_LEFT_HEAVY:
			left->factor=AVL_BALANCED;;
			root->factor=AVL_RIGHT_HEAVY;
			break;
		case AVL_BALANCED:
			left->factor=AVL_BALANCED;
			root->factor=AVL_BALANCED;
			break;
		case AVL_RIGHT_HEAVY:
			left->factor=AVL_LEFT_HEAVY;;
			root->factor=AVL_BALANCED;
			break;
	}
	grandchild->factor=AVL_BALANCED;
	return grandchild;
}
bistree_node *roate_right(bistree_node *root)
{
	bistree_node *right,*grandchild;
	right=root->right;
	if(right->factor==AVL_RIGHT_HEAVY)
	{
		root->right=right->left;
		right->left=root;
		root->factor=AVL_BALANCED;
		right->factor=AVL_BALANCED;
		return right;
	}
	grandchild=right->left;
	root->right=grandchild->left;
	grandchild->left=root;
	right->left=grandchild->right;
	grandchild->right=right;
	switch(grandchild->factor)
	{
		case AVL_LEFT_HEAVY:
			right->factor=AVL_RIGHT_HEAVY;
			root->factor=AVL_BALANCED;
			break;
		case AVL_BALANCED:
			right->factor=AVL_BALANCED;
			root->factor=AVL_BALANCED;
			break;
		case AVL_RIGHT_HEAVY:
			right->factor=AVL_BALANCED;
			root->factor=AVL_LEFT_HEAVY;
			break;
	}
	grandchild->factor=AVL_BALANCED;
	return grandchild;
}
bistree_node *insert(bistree_node *root,int data,int *balance)
{
	if(root==NULL)
	{
		root=(bistree_node *)malloc(sizeof(bistree_node));
		root->left=NULL;
		root->right=NULL;
		root->factor=AVL_BALANCED;
		root->data=data;
		*balance=0;
		return root;
	}
	if(root->data>=data)
	{
		root->left=insert(root->left,data,balance);
		if(*balance==0)
		{
			switch(root->factor)
			{
				case AVL_LEFT_HEAVY:
					root=roate_left(root);
					*balance=1;
					break;
				case AVL_BALANCED:
					root->factor=AVL_LEFT_HEAVY;
					break;
				case AVL_RIGHT_HEAVY:
					root->factor=AVL_BALANCED;
					*balance=1;
					break;
			}
		}
	}
	else
	{
		root->right=insert(root->right,data,balance);
		if(*balance==0)
		{
			switch(root->factor)
			{
				case AVL_LEFT_HEAVY:
					root->factor=AVL_BALANCED;
					*balance=1;
					break;
				case AVL_BALANCED:
					root->factor=AVL_RIGHT_HEAVY;
					break;
				case AVL_RIGHT_HEAVY:
					root=roate_right(root);
					*balance=1;
					break;
			}	
		}
	}
	return root;
}
int main()
{
	int n,i,temp,balance=0;
	bistree *tree;
	scanf("%d",&n);
	tree=(bistree *)malloc(sizeof(bistree));
	tree->root=NULL;
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		balance=0;
		tree->root=insert(tree->root,temp,&balance);
	}
	printf("%d\n",tree->root->data);
}