#include<stdio.h>
#include<stdlib.h>
int count[21],cbt[21];
typedef struct tree_
{
	int left;
	int right;
} tree;
int main()
{
	tree node[21];
	int n,i,left,right,root,temp,parent,child,stack[20],top=-1;
	char buf[6];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",buf);
		cbt[i]=-1;
		if(buf[0]=='-')
		{
			node[i].left=-1;
		}
		else
		{
			sscanf(buf,"%d",&(node[i].left));
			node[i].left++;
			count[node[i].left]=1;
		}
		scanf("%s",buf);
		if(buf[0]=='-')
		{
			node[i].right=-1;
		}
		else
		{
			sscanf(buf,"%d",&(node[i].right));
			node[i].right++;
			count[node[i].right]=1;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(count[i]==0)
		{
			root=i;
			break;
		}
	}
	parent=1;
	cbt[parent]=root;
	stack[++top]=parent;
	while(top>=0)
	{
		parent=stack[top--];
		temp=cbt[parent];
		child=2*parent;
		if(child<=n&&node[temp].left!=-1)
		{
			cbt[child]=node[temp].left;
			stack[++top]=child;
		}
		if(child+1<=n&&node[temp].right!=-1)
		{
			cbt[child+1]=node[temp].right;
			stack[++top]=child+1;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(cbt[i]<=0)
		{
			printf("NO %d\n",root-1);
			return 0;
		}
	}
	printf("YES %d\n",cbt[n]-1);
}