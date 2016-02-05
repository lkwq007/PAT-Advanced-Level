#include<stdio.h>
int isleaf[100],tree[100],leaves[100];
int main()
{
	int i,j,n,m,k,child,parent,level,temp,edge=0;
	scanf("%d%d",&n,&m);
	isleaf[1]=1;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&parent,&k);
		isleaf[parent]=-1;
		for(j=0;j<k;j++)
		{
			scanf("%d",&child);
			if(isleaf[child]!=-1)
				isleaf[child]=1;
			tree[child]=parent;
		}
	}
	for(i=0;i<100;i++)
	{
		if(isleaf[i]==1)
		{
			level=0;
			temp=i;
			while(temp!=1)
			{
				level++;
				temp=tree[temp];
			}
			if(level>edge)
				edge=level;
			leaves[level]++;
		}
	}
	printf("%d",leaves[0]);
	for(i=1;i<=edge;i++)
	{
		printf(" %d",leaves[i]);
	}
	printf("\n");
}