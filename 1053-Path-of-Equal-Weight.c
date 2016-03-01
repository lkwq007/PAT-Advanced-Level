#include<stdio.h>
#include<stdlib.h>
typedef struct info_ 
{
	int parent;
	int is_leaf;
	int weight;
} info;
info node[100];
int compare(const void *a,const void *b)
{
	int *pa,*pb;
	pa=*(int **)a;
	pb=*(int **)b;
	while(*pa!=-1&&*pb!=-1)
	{
		if(*pa>*pb)
		{
			return -1;
		}
		else if(*pa<*pb)
		{
			return 1;
		}
		pa++;
		pb++;
	}
	if(*pa==-1)
	{
		return 1;
	}
	return -1;
}
int main()
{
	int n,i,j,m,k,s,temp,sum,parent,child,record[100],*result[100],total,offset=0;
	scanf("%d%d%d",&n,&m,&s);
	for(i=0;i<n;i++)
	{
		scanf("%d",&(node[i].weight));
		node[i].is_leaf=1;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&parent,&k);
		node[parent].is_leaf=0;
		for(j=0;j<k;j++)
		{
			scanf("%d",&child);
			node[child].parent=parent;
		}
	}
	for(i=0;i<n;i++)
	{
		if(node[i].is_leaf)
		{
			temp=i;
			sum=0;
			while(temp!=0)
			{
				sum+=node[temp].weight;
				temp=node[temp].parent;
			}
			sum+=node[temp].weight;
			if(sum==s)
			{
				record[offset]=i;
				result[offset]=(int *)malloc(n*sizeof(int));
				temp=i;
				j=0;
				while(temp!=0)
				{
					result[offset][j++]=node[temp].weight;
					temp=node[temp].parent;
				}
				result[offset][j++]=node[temp].weight;
				result[offset][j]=-1;
				total=j;
				for(j=0;j<total/2;j++)
				{
					temp=result[offset][j];
					result[offset][j]=result[offset][total-j-1];
					result[offset][total-j-1]=temp;
				}
				offset++;
			}
		}
	}
	qsort(result,offset,sizeof(int *),compare);
	for(i=0;i<offset;i++)
	{
		printf("%d",result[i][0]);
		j=1;
		while(result[i][j]!=-1)
		{
			printf(" %d",result[i][j++]);
		}
		printf("\n");
	}
}