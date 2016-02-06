#include<stdio.h>
#include<stdlib.h>
typedef struct tree_
{
	int number;
	struct tree_ *left;
	struct tree_ *right;
} tree;
int count[10];
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
void level_order(tree *t)
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
void in_order_r(tree *root,int *flag)
{
	if(root==NULL)
	{
		return ;
	}
	in_order_r(root->left,flag);
	if(*flag==0)
	{
		printf("%d",root->number);
		*flag=1;
	}
	else
	{
		printf(" %d",root->number);
	}
	in_order_r(root->right,flag);
}
void invert_r(tree *root)
{
	tree *temp;
	if(root==NULL)
	{
		return ;
	}
	temp=root->left;
	root->left=root->right;
	root->right=temp;
	invert_r(root->left);
	invert_r(root->right);
}
int main()
{
	tree t[10],*root;
	int n,i,flag=0;
	char buf[4];
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		gets(buf);
		t[i].number=i;
		t[i].left=buf[0]=='-'?NULL:t+buf[0]-'0';
		t[i].right=buf[2]=='-'?NULL:t+buf[2]-'0';
		if(buf[0]!='-')
		{
			count[buf[0]-'0']=1;
		}
		if(buf[2]!='-')
		{
			count[buf[2]-'0']=1;
		}
	}
	for(i=0;i<n;i++)
	{
		if(t[i].left==NULL&&t[i].right==NULL)
		{
			continue;
		}
		if(count[i]!=1)
		{
			root=t+i;
			break;
		}
	}
	if(n==1)
	{
		root=t;
	}
	invert_r(root);
	level_order(root);
	in_order_r(root,&flag);
}