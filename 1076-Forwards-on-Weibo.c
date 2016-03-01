#include<stdio.h>
#include<stdlib.h>
int graph[1001][1001],users[1001];
typedef struct queue_
{
	int size;
	int capacity;
	int front;
	int rear;
	int *data;
} queue;
#define is_queue_empty(X) (!((X)->size))
queue *init_queue(int n)
{
	queue *temp;
	temp=(queue *)malloc(sizeof(queue));
	temp->size=0;
	temp->capacity=n;
	temp->front=0;
	temp->rear=-1;
	temp->data=(int *)malloc(n*sizeof(int));
	return temp;
}
int enqueue(queue *q,int data)
{
	if(q->size==q->capacity)
	{
		return 1;
	}
	q->size++;
	q->rear=(q->rear+1)%q->capacity;
	q->data[q->rear]=data;
	return 0;
}
int dequeue(queue *q,int *data)
{
	if(q->size==0)
	{
		*data=-1;
		return 1;
	}
	q->size--;
	*data=q->data[q->front];
	q->front=(q->front+1)%q->capacity;
	return 0;
}
int delete_queue(queue *q)
{
	free(q->data);
	free(q);
	return 0;
}
int bfs(int source,int level,int n,queue *q)
{
	int i,temp,count=0;
	users[source]=0;
	enqueue(q,source);
	while(!is_queue_empty(q))
	{
		count++;
		dequeue(q,&temp);
		for(i=1;i<=n;i++)
		{
			if(graph[temp][i])
			{
				if(users[i]==-1)
				{
					users[i]=users[temp]+1;
					if(users[i]<=level)
					{
						enqueue(q,i);
					}
				}
			}
		}
	}
	return count-1;
}
int main()
{
	int n,l,m,k,i,j,temp;
	queue *q;
	scanf("%d%d",&n,&l);
	q=init_queue(n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&m);
		for(j=0;j<m;j++)
		{
			scanf("%d",&temp);
			graph[temp][i]=1;
		}
	}
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		scanf("%d",&temp);
		for(j=1;j<=n;j++)
		{
			users[j]=-1;
		}
		printf("%d\n",bfs(temp,l,n,q));
	}
}
