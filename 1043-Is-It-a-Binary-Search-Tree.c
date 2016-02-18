#include<stdio.h>
#include<stdlib.h>
int check_bst(int *tree,int n)
{
	int root,i,edge=-1;
	if(n<=1)
	{
		return 1;
	}
	root=tree[0];
	for(i=1;i<n;i++)
	{
		if(tree[i]>=root)
		{
			edge=i;
			break;
		}
	}
	if(edge==-1)
	{
		edge=n;
	}
	for(i=edge;i<n;i++)
	{
		if(tree[i]<root)
		{
			return 0;
		}
	}
	return check_bst(tree+1,edge-1)&&check_bst(tree+edge,n-edge);
}
int check_mbst(int *tree,int n)
{
	int root,i,edge=-1;
	if(n<=1)
	{
		return 1;
	}
	root=tree[0];
	for(i=1;i<n;i++)
	{
		if(tree[i]<root)
		{
			edge=i;
			break;
		}
	}
	if(edge==-1)
	{
		edge=n;
	}
	for(i=edge;i<n;i++)
	{
		if(tree[i]>=root)
		{
			return 0;
		}
	}
	return check_mbst(tree+1,edge-1)&&check_mbst(tree+edge,n-edge);
}
int convert(int *tree,int n,int *flag)
{
	int i,root,edge=-1;
	if(n==0)
	{
		return 0;
	}
	if(n==1)
	{
		if(*flag)
		{
			printf(" ");
		}
		else
		{
			*flag=1;
		}
		printf("%d",*tree);
		return 0;
	}
	root=tree[0];
	for(i=1;i<n;i++)
	{
		if(tree[i]>=root)
		{
			edge=i;
			break;
		}
	}
	if(edge==-1)
	{
		edge=n;
	}
	convert(tree+1,edge-1,flag);
	convert(tree+edge,n-edge,flag);
	if(*flag)
	{
		printf(" ");
	}
	else
	{
		*flag=1;
	}
	printf("%d",*tree);
	return 0;
}
int convert_m(int *tree,int n,int *flag)
{
	int i,root,edge=-1;
	if(n==0)
	{
		return 0;
	}
	if(n==1)
	{
		if(*flag)
		{
			printf(" ");
		}
		else
		{
			*flag=1;
		}
		printf("%d",*tree);
		return 0;
	}
	root=tree[0];
	for(i=1;i<n;i++)
	{
		if(tree[i]<root)
		{
			edge=i;
			break;
		}
	}
	if(edge==-1)
	{
		edge=n;
	}
	convert_m(tree+1,edge-1,flag);
	convert_m(tree+edge,n-edge,flag);
	if(*flag)
	{
		printf(" ");
	}
	else
	{
		*flag=1;
	}
	printf("%d",*tree);
	return 0;
}
int main()
{
	int n,*tree,i,flag=0;
	scanf("%d",&n);
	tree=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",tree+i);
	}
	if(check_bst(tree,n))
	{
		printf("YES\n");
		convert(tree,n,&flag);
	}
	else if(check_mbst(tree,n))
	{
		printf("YES\n");
		convert_m(tree,n,&flag);
	}
	else
	{
		printf("NO\n");
	}
}