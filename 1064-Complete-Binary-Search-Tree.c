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
void level_order(tree *t,int n)
{
	queue *q;
	tree *temp;
	int flag=0;
	q=init_queue(n);
	enqueue(q,t);
	while(!is_queue_empty(q))
	{
		dequeue(q,(void **)&temp);
		if(flag==0)
		{
			printf("%d",temp->number);
			flag=1;
		}
		else
		{
			printf(" %d",temp->number);
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
int compare(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
tree *build_cbst(int *sequence,int n)
{
	tree *root;
	int edge,bottom,count,temp;
	if(n<=0)
	{
		return NULL;
	}
	root=(tree *)malloc(sizeof(tree));
	if(n==1)
	{
		root->left=NULL;
		root->right=NULL;
		root->number=sequence[0];
		return root;
	}
	temp=2;
	count=1;
	while(temp-1<n)
	{
		count++;
		temp=temp<<1;
	}
	temp=temp>>1;
	bottom=temp;
	if(n-temp+1>bottom/2)
	{
		edge=(temp-1-1)/2+bottom/2;
	}
	else
	{
		edge=(temp-1-1)/2+n-temp+1;
	}
	root->number=sequence[edge];
	root->left=build_cbst(sequence,edge);
	root->right=build_cbst(sequence+edge+1,n-1-edge);
	return root;
}
int main()
{
	int n,i,buf[1000];
	tree *root;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",buf+i);
	}
	qsort(buf,n,sizeof(int),compare);
	root=build_cbst(buf,n);
	level_order(root,n);
}