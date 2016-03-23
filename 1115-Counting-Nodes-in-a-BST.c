#include<stdio.h>
#include<stdlib.h>
int result[2],bottom=0;
typedef struct tree_
{
	int num;
	int level;
	struct tree_ *left;
	struct tree_ *right;
} tree;
tree *insert(tree *root,int num,int level)
{
	if(level>bottom)
	{
		bottom=level;
	}
	if(root==NULL)
	{
		root=(tree *)malloc(sizeof(tree));
		root->left=NULL;
		root->right=NULL;
		root->num=num;
		root->level=level;
		return root;
	}
	if(root->num<num)
	{
		root->right=insert(root->right,num,level+1);
	}
	else
	{
		root->left=insert(root->left,num,level+1);
	}
	root->level=level;
	return root;
}
void search(tree *root)
{
	if(root==NULL)
	{
		return ;
	}
	if(root->level==bottom)
	{
		result[1]++;
	}
	if(root->level+1==bottom)
	{
		result[0]++;
	}
	search(root->left);
	search(root->right);
	return ;
}
int main()
{
	int i,n,num;
	tree *root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		root=insert(root,num,0);
	}
	search(root);
	printf("%d + %d = %d\n",result[1],result[0],result[0]+result[1]);
}