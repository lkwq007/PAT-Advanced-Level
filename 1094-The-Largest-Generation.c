//与 1004 思路类似
#include<stdio.h>
int intree[100],tree[100],population[100];
int main()
{
	int i,j,n,m,k,child,parent,level,temp,edge=0,max=0;
	scanf("%d%d",&n,&m);
	intree[1]=1;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&parent,&k);
		intree[parent]=1;
		for(j=0;j<k;j++)
		{
			scanf("%d",&child);
			intree[child]=1;
			tree[child]=parent;
		}
	}
	for(i=0;i<100;i++)
	{
		if(intree[i]==1)
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
			population[level]++;
		}
	}
	for(i=0;i<=edge;i++)
	{
		if(population[i]>population[max])
		{
			max=i;
		}
	}
	printf("%d %d",population[max],max+1);
}