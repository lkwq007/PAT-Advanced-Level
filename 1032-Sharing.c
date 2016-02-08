#include<stdio.h>
typedef struct list_
{
	int word;
	//int key;
	int next;
} list;
list data[100000];
int main()
{
	int n,i,address,head_a,head_b;
	char buf[2];
	scanf("%d%d%d",&head_a,&head_b,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&address);
		scanf("%s%d",buf,&(data[address].next));
		data[address].word=0;
	}
	address=head_a;
	while(address!=-1)
	{
		data[address].word=1;
		address=data[address].next;
	}
	address=head_b;
	while(address!=-1)
	{
		if(data[address].word==1)
		{
			break;
		}
		address=data[address].next;
	}
	if(address==-1)
	{
		printf("-1\n");
	}
	else
	{
		printf("%05d\n",address);
	}
}