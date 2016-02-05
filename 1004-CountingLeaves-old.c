#include<stdio.h>
#include<stdlib.h>
int count[100],level[100],leaves[100];
int main()
{
	int i,j,n,m,k,child,parent,levels,temp,edge=0;
	scanf("%d%d",&n,&m);
	count[1]=1;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&parent,&k);
		count[parent]=-1;
		for(j=0;j<k;j++)
		{
			scanf("%d",&child);
			if(count[child]!=-1)
				count[child]=1;
			level[child]=parent;
		}
	}
	for(i=0;i<100;i++)
	{
		if(count[i]==1)
		{
			levels=0;
			temp=i;
			while(temp!=1)
			{
				levels++;
				temp=level[temp];
			}
			if(levels>edge)
				edge=levels;
			leaves[levels]++;
		}
	}
	printf("%d",leaves[0]);
	for(i=1;i<=edge;i++)
	{
		printf(" %d",leaves[i]);
	}
	printf("\n");
}