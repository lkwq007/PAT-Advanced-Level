#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct info_
{
	int related;
	int calling_time;
	int head;
	int total;
} info;
int set_find(info *set,int index)
{
	int root,temp=index,max=index;
	while(set[temp].related>-1)
	{
		temp=set[temp].related;
		if(set[max].calling_time<set[temp].calling_time)
		{
			max=temp;
		}
	}
	root=temp;
	temp=index;
	while(set[temp].related>-1)
	{
		index=temp;
		temp=set[temp].related;
		set[index].related=root;
	}
	if(set[set[root].head].calling_time<set[max].calling_time)
	{
		set[root].head=max;
	}
	return root;
}
int set_union(info *set,int a,int b,int calling_time)
{
	set[a].calling_time+=calling_time;
	set[b].calling_time+=calling_time;
	a=set_find(set,a);
	b=set_find(set,b);
	if(a==b)
	{
		set[a].total+=calling_time;
		return 0;
	}
	if(set[a].related<set[b].related)
	{
		set[a].related+=set[b].related;
		set[a].total+=set[b].total;
		set[a].total+=calling_time;
		if(set[set[a].head].calling_time<set[set[b].head].calling_time)
		{
			set[a].head=set[b].head;
		}
		set[b].related=a;
	}
	else
	{
		set[b].related+=set[a].related;
		set[b].total+=set[a].total;
		set[b].total+=calling_time;
		if(set[set[b].head].calling_time<set[set[a].head].calling_time)
		{
			set[b].head=set[a].head;
		}
		set[a].related=b;
	}
	return 1;
}
int find_name(char *name,char (*name_list)[4],int *n)
{
	int i;
	for(i=0;i<*n;i++)
	{
		if(!strcmp(name_list[i],name))
		{
			break;
		}
	}
	if(i==*n)
	{
		strcpy(name_list[i],name);
		(*n)++;
	}
	return i;
}
info *set;
char name[2000][4];
int compare(const void *a,const void *b)
{
	return strcmp(name[set[*(int *)a].head],name[set[*(int *)b].head]);
}
int main()
{
	int n,k,i,calling_time,index[2],*result,offset=0;
	char buf[8];
	scanf("%d%d",&n,&k);
	set=(info *)malloc(n*2*sizeof(info));
	result=(int *)malloc(n*2*sizeof(int));
	for(i=0;i<n;i++)
	{
		set[i].related=-1;
		set[i].calling_time=0;
		set[i].total=0;
		set[i].head=i;
	}
	for(i=0;i<n;i++)
	{
		scanf("%s%s%d",buf,buf+4,&calling_time);
		set_union(set,find_name(buf,name,&offset),find_name(buf+4,name,&offset),calling_time);
	}
	offset=0;
	for(i=0;i<n;i++)
	{
		if(set[i].related<-2&&set[i].total>k)
		{
			result[offset++]=i;
		}
	}
	qsort(result,offset,sizeof(int),compare);
	printf("%d\n",offset);
	for(i=0;i<offset;i++)
	{
		printf("%s %d\n",name[set[result[i]].head],-set[result[i]].related);
	}
}