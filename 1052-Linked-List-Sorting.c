#include<stdio.h>
#include<stdlib.h>
typedef struct list_
{
	int address;
	int key;
	int next;
	int in_list;
} list;
int memory[100000];
int compare(const void *a,const void *b)
{
	if(((list *)b)->in_list>((list *)a)->in_list)
	{
		return -1;
	}
	else if(((list *)b)->in_list<((list *)a)->in_list)
	{
		return 1;
	}
	return ((list *)a)->key-((list *)b)->key;
}
int main()
{
	int n,head,i,address,count=0,pre=-1;
	list *data;
	scanf("%d%d",&n,&head);
	data=(list *)malloc(n*sizeof(list));
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&(data[i].address),&(data[i].key),&(data[i].next));
		memory[data[i].address]=i;
		data[i].in_list=0;
	}
	address=head;
	while(address!=-1)
	{
		data[memory[address]].in_list=1;
		address=data[memory[address]].next;
	}
	qsort(data,n,sizeof(list),compare);
	head=-1;
	for(i=0;i<n;i++)
	{
		if(data[i].in_list==1)
		{
			if(head==-1)
			{
				head=data[i].address;
			}
			count++;
		}
	}
	if(head!=-1)
	{
		printf("%d %05d\n",count,head);
	}
	else
	{
		printf("%d %d\n",count,head);
	}
	for(i=0;i<n;i++)
	{
		if(data[i].in_list==1)
		{
			if(pre!=-1)
			{
				printf("%05d\n",data[i].address);
			}
			printf("%05d %d ",data[i].address,data[i].key);
			pre=data[i].address;
		}
	}
	if(pre!=-1)
	{
		printf("-1\n");
	}
}