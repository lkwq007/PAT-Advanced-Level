#include<stdio.h>
#include<stdlib.h>
typedef struct list_
{
	int key;
	int next;
} list;
list data[100000];
int count[10001];
int main()
{
	int first,address,key,next,n,i,tail=-1,deleted=-1,deleted_tail=-1;
	scanf("%d%d",&first,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&address,&key,&next);
		data[address].key=key;
		data[address].next=next;
	}
	address=first;
	while(address!=-1)
	{
		key=data[address].key;
		key=key>0?key:-key;
		if(count[key]>0)
		{
			data[tail].next=data[address].next;
			data[address].next=-1;
			if(deleted==-1)
			{
				deleted=address;
				deleted_tail=deleted;
			}
			else
			{
				data[deleted_tail].next=address;
				deleted_tail=address;
			}
		}
		else
		{
			tail=address;
			count[key]++;
		}
		address=data[tail].next;
	}
	address=first;
	while(address!=-1)
	{
		printf("%05d %d ",address,data[address].key);
		if(data[address].next!=-1)
		{
			printf("%05d\n",data[address].next);
		}
		else
		{
			printf("-1\n");
		}
		address=data[address].next;
	}
	address=deleted;
	while(address!=-1)
	{
		printf("%05d %d ",address,data[address].key);
		if(data[address].next!=-1)
		{
			printf("%05d\n",data[address].next);
		}
		else
		{
			printf("-1\n");
		}
		address=data[address].next;
	}
}