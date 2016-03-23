#include<stdio.h>
#include<stdlib.h>
typedef struct info_
{
	int related;
	int m_estate;
	int area;
	int smallest_id;
} info;
info set[10000];
int find(int index)
{
	int root,temp=index,min=index;
	while(set[temp].related>-1)
	{
		temp=set[temp].related;
		if(temp<min)
		{
			min=temp;
		}
	}
	root=temp;
	while(set[temp].related>-1)
	{
		index=temp;
		temp=set[temp].related;
		set[index].related=root;
	}
	if(min<set[root].smallest_id)
	{
		set[root].smallest_id=min;
	}
	return root;
}
int set_union(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a==b)
	{
		return 0;
	}
	if(set[a].related<set[b].related)
	{
		set[a].related+=set[b].related;
		set[b].related=a;
		if(set[a].smallest_id>set[b].smallest_id)
		{
			set[a].smallest_id=set[b].smallest_id;
		}
	}
	else
	{
		set[b].related+=set[a].related;
		set[a].related=b;
		if(set[b].smallest_id>set[a].smallest_id)
		{
			set[b].smallest_id=set[a].smallest_id;
		}
	}
	return 1;
}
int compare(const void *a,const void *b)
{
	if(set[*(int *)a].area*(-set[*(int *)b].related)==set[*(int *)b].area*(-set[*(int *)a].related))
	{
		return set[*(int *)a].smallest_id-set[*(int *)b].smallest_id;
	}
	return set[*(int *)b].area*(-set[*(int *)a].related)-set[*(int *)a].area*(-set[*(int *)b].related);
}
int main()
{
	int i,j,n,id,temp,father,mother,k,child,m_estate,area,*list,*result,offset=0;
	info *members;
	for(i=0;i<10000;i++)
	{
		set[i].related=-1;
		set[i].area=0;
		set[i].m_estate=0;
		set[i].smallest_id=10000;
	}
	scanf("%d",&n);
	list=(int *)malloc(n*sizeof(int));
	result=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&id,&father,&mother,&k);
		list[i]=id;
		if(father!=-1)
		{
			set_union(id,father);
		}
		if(mother!=-1)
		{
			set_union(id,mother);
		}
		for(j=0;j<k;j++)
		{
			scanf("%d",&child);
			set_union(id,child);
		}
		scanf("%d%d",&m_estate,&area);
		set[id].m_estate=m_estate;
		set[id].area=area;
	}
	for(i=0;i<n;i++)
	{
		id=list[i];
		temp=find(id);
		for(j=0;j<offset;j++)
		{
			if(result[j]==temp)
			{
				break;
			}
		}
		if(j==offset)
		{
			result[offset++]=temp;
		}
		if(temp!=id)
		{
			set[temp].m_estate+=set[id].m_estate;
			set[temp].area+=set[id].area;
		}
	}
	qsort(result,offset,sizeof(int),compare);
	printf("%d\n",offset);
	for(i=0;i<offset;i++)
	{
		printf("%04d %d %.3lf %.3lf\n",set[result[i]].smallest_id,-set[result[i]].related,set[result[i]].m_estate/(double)(-set[result[i]].related),set[result[i]].area/(double)(-set[result[i]].related));
	}
}