#include<stdio.h>
#include<stdlib.h>
typedef struct node_
{
	int no;
	int serve;
	struct node_ *next;
} node;
typedef struct queue_
{
	int num;
	node *head;
	node *tail;
} queue;
int n,m,k,qs,*time_cost,*time_serve,count;
queue *q;
int print_time(int minute,int used)
{
	int hour;
	if(minute-used>=540)
	{
		printf("Sorry\n");
	}
	else
	{
		hour=minute/60+8;
		minute%=60;
		printf("%02d:%02d\n",hour,minute);
	}
}
int dequeue()
{
	int i,min=0;
	node *temp;
	for(i=0;i<n;i++)
	{
		if(q[i].num==0)
			continue;
		if(q[i].head->serve<q[min].head->serve)
		{
			min=i;
		}
	}
	if(min==n||q[min].num==0)
	{
		return 1;
	}
	if(q[min].head->next==q[min].tail)
	{
		q[min].tail=q[min].head;
	}
	temp=q[min].head->next;
	q[min].head->next=temp->next;
	if(q[min].head->next!=NULL)
	{
		q[min].head->serve=q[min].head->next->serve;
	}
	free(temp);
	q[min].num--;
	count--;
	return 0;
}
int enqueue(int no)
{
	int i,min=0;
	node *temp;
	for(i=0;i<n;i++)
	{
		if(q[i].num<m)
		{
			min=i;
			break;
		}
	}
	for(i=min;i<n;i++)
	{
		if(q[i].num<q[min].num)
		{
			min=i;
		}
	}
	if(q[min].tail==q[min].head)
	{
		temp=(node *)malloc(sizeof(node));
		q[min].tail=temp;
		q[min].head->next=temp;
		temp->next=NULL;
		temp->no=no;
		temp->serve=q[min].head->serve+time_cost[no];
		q[min].head->serve=temp->serve;
	}
	else
	{
		temp=(node *)malloc(sizeof(node));
		temp->next=NULL;
		temp->no=no;
		temp->serve=q[min].tail->serve+time_cost[no];
		q[min].tail->next=temp;
		q[min].tail=temp;
	}
	time_serve[no]=temp->serve;
	count++;
	q[min].num++;
	return 0;
}
int main()
{
	int i,j,query;
	node *temp;
	scanf("%d%d%d%d",&n,&m,&k,&qs);
	q=(queue *)malloc(n*sizeof(queue));
	time_cost=(int *)malloc((k+1)*sizeof(int));
	time_serve=(int *)malloc((k+1)*sizeof(int));
	for(i=0;i<n;i++)
	{
		q[i].num=0;
		q[i].head=(node *)malloc(sizeof(node));
		q[i].head->no=0;
		q[i].head->serve=0;
		q[i].head->next=NULL;
		q[i].tail=q[i].head;
	}
	for(i=1;i<=k;i++)
	{
		scanf("%d",time_cost+i);
	}
	count=0;
	for(i=1;i<=k;i++)
	{
		if(count>=n*m)
		{
			dequeue();
		}
		enqueue(i);
/*		for(j=0;j<n;j++)
		{
			temp=q[j].head;
			while(temp!=NULL)
			{
				printf("%d:%d-",temp->no,temp->serve);
				temp=temp->next;
			}
			printf("\n");
		}
		printf("\n");*/
	}
	for(i=0;i<qs;i++)
	{
		scanf("%d",&query);
		print_time(time_serve[query],time_cost[query]);
		/*printf("%d\n",time_serve[query]);*/
	}
}