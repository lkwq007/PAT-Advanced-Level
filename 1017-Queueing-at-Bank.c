#include<stdio.h>
#include<stdlib.h>
#define BEGIN 8*3600
#define END 17*3600
#define is_empty(X) (!((X)->size))
typedef struct qlog
{
	int arriving;//到达时间
	int processing;//处理用户所需时间
	int waiting;//等待截止的时间
} qlog;
typedef struct queue_
{
	int size;
	int capacity;
	int front;
	int rear;
	qlog **data;
} queue;
queue *init_queue(int n)
{
	queue *temp;
	temp=(queue *)malloc(sizeof(queue));
	temp->size=0;
	temp->capacity=n;
	temp->front=0;
	temp->rear=-1;
	temp->data=(qlog **)malloc(n*sizeof(qlog *));
	return temp;
}
int enqueue(queue *q,qlog *data)
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
qlog *dequeue(queue *q)
{
	qlog *temp;
	if(q->size==0)
	{
		return NULL;
	}
	q->size--;
	temp=q->data[q->front];
	q->front=(q->front+1)%q->capacity;
	return temp;
}
int compare(const void *a,const void *b)
{
	return ((qlog *)a)->arriving-((qlog *)b)->arriving;
}
int main()
{
	int n,k,i,j,total,hour,minute,second,cost,current_time,min;
	qlog *customer;
	queue **q;
	scanf("%d%d",&n,&k);
	customer=(qlog *)malloc(n*sizeof(qlog));
	q=(queue **)malloc(k*sizeof(queue *));
	for(i=0;i<k;i++)
	{
		q[i]=init_queue(n);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d:%d:%d %d",&hour,&minute,&second,&cost);
		customer[i].arriving=hour*3600+minute*60+second;
		if(cost>60)
		{
			cost=60;
		}
		customer[i].processing=cost*60;
	}
	qsort(customer,n,sizeof(qlog),compare);
	for(i=0;i<n;i++)
	{
		if(customer[i].arriving>END)
		{
			break;
		}
		current_time=customer[i].arriving;
		min=0;
		for(j=0;j<k;j++)
		{
			if(q[j]->size==0)
			{
				continue;
			}
			while((q[j]->data[q[j]->front])->waiting+(q[j]->data[q[j]->front])->processing<=current_time)
			{
				dequeue(q[j]);
				if(q[j]->size==0)
				{
					break;
				}
			}
		}
		for(j=0;j<k;j++)
		{
			if(q[j]->size==0)
			{
				min=j;
				break;
			}
			if((q[min]->data[q[min]->rear])->waiting+(q[min]->data[q[min]->rear])->processing>
				(q[j]->data[q[j]->rear])->waiting+(q[j]->data[q[j]->rear])->processing)
			{
				min=j;
			}

		}
		if(q[min]->size==0)
		{
			if(current_time<BEGIN)
			{
				customer[i].waiting=BEGIN;
			}
			else
			{
				customer[i].waiting=current_time;
			}
		}
		else
		{
			customer[i].waiting=(q[min]->data[q[min]->rear])->waiting+(q[min]->data[q[min]->rear])->processing;
		}
		enqueue(q[min],customer+i);
		total+=(customer[i].waiting-customer[i].arriving);
	}
	n=i;
	printf("%.1lf\n",(double)total/n/60);
}