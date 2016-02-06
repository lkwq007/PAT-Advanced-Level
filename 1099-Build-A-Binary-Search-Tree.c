#include<stdio.h>
#include<stdlib.h>
typedef struct tree_
{
	int number;
	struct tree_ *left;
	struct tree_ *right;
} tree;
typedef struct queue_
{
	int size;
	int capacity;
	int front;
	int rear;
	void **data;
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
	temp->data=(void **)malloc(n*sizeof(void *));
	return temp;
}
int enqueue(queue *q,void *data)
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
int dequeue(queue *q,void **data)
{
	if(q->size==0)
	{
		*data=NULL;
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
void level_order(tree *t,int *sequence)
{
	queue *q;
	tree *temp;
	int flag=0;
	q=init_queue(10);
	enqueue(q,t);
	while(!is_queue_empty(q))
	{
		dequeue(q,(void **)&temp);
		if(flag==0)
		{
			printf("%d",sequence[temp->number]);
			flag=1;
		}
		else
		{
			printf(" %d",sequence[temp->number]);
		}
		if(temp->left!=NULL)
		{
			enqueue(q,temp->left);
		}
		if(temp->right!=NULL)
		{
			enqueue(q,temp->right);
		}
	}
	printf("\n");
}
void in_order_r(tree *t,int *count)
{
	if(t==NULL)
	{
		return ;
	}
	in_order_r(t->left,count);
	t->number=*count;
	(*count)++;
	in_order_r(t->right,count);
}
int compare(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	tree t[100];
	int i,n,left,right,sequence[100],count=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&left,&right);
		t[i].left=left==-1?NULL:t+left;
		t[i].right=right==-1?NULL:t+right;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",sequence+i);
	}
	qsort(sequence,n,sizeof(int),compare);
	in_order_r(t,&count);
	level_order(t,sequence);
}