#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int set_find(int *set,int index)
{
	int temp,root;
	temp=index;
	while(set[temp]>=0)
	{
		temp=set[temp];
	}
	root=temp;
	temp=index;
	while(set[temp]>=0)
	{
		index=temp;
		temp=set[temp];
		set[index]=root;
	}
	return root;
}
int set_union(int *set,int a,int b)
{
	a=set_find(set,a);
	b=set_find(set,b);
	if(a==b)
	{
		return 0;
	}
	if(set[a]<set[b])
	{
		set[a]+=set[b];
		set[b]=a;
	}
	else
	{
		set[b]+=set[a];
		set[a]=b;
	}
	return 0;
}
int compare(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	int n,i,j,k,*clusters,index,hobby[1001];
	scanf("%d",&n);
	clusters=(int *)malloc(n*sizeof(int));
	memset(clusters,0xFF,n*sizeof(int));
	memset(hobby,0xFF,1001*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d:",&k);
		for(j=0;j<k;j++)
		{
			scanf("%d",&index);
			if(hobby[index]==-1)
			{
				hobby[index]=i;
			}
			else
			{
				set_union(clusters,i,hobby[index]);
			}
		}
	}
	qsort(clusters,n,sizeof(int),compare);
	for(i=0;i<n;i++)
	{
		if(clusters[i]>=0)
		{
			break;
		}
	}
	n=i;
	printf("%d\n",n);
	if(n>0)
	{
		printf("%d",-clusters[0]);
		for(i=1;i<n;i++)
		{
			printf(" %d",-clusters[i]);
		}
	}
}