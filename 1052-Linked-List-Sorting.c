#include<stdio.h>
typedef struct list_
{
	int key;
	int next;
} list;
list data[100001];
int main()
{
	int n,i,head,pre,temp,j,address,dummy;
	scanf("%d%d",&n,&head);
	dummy=100000;
	data[dummy].next=head;
	for(i=0;i<n;i++)
	{
		scanf("%d",&address);
		scanf("%d%d",&(data[address].key),&(data[address].next));
	}
	pre=dummy;
	for(i=head;data[i].next!=-1;i=data[i].next)
	{
		for(j=i;data[j].next!=-1;j=data[j].next)
		{
			if(data[j].key>data[data[j].next].key)
			{
				data[pre].next=data[j].next;
				temp=data[data[j].next].next;
				data[data[j].next].next=j;
				data[j].next=temp;
			}
			pre=j;
			printf("%d\n",i);
		}
		pre=i;
	}
	address=data[dummy].next;
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