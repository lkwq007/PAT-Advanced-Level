#include<stdio.h>
#include<stdlib.h>
typedef struct tree_
{
	int number;
	struct tree_ *left;
	struct tree_ *right;
} tree;
typedef struct stack_
{
	int size;
	int capacity;
	int top;
	void **data;
} stack;
#define is_stack_empty(X) (!((X)->size))
#define ptr_top(X) ((X)->data[(X)->top])
stack *inti_stack(int n)
{
	stack *temp;
	temp=(stack *)malloc(sizeof(stack));
	temp->size=0;
	temp->capacity=n;
	temp->top=-1;
	temp->data=(void **)malloc(n*sizeof(void *));
	return temp;
}
int push(stack *s,void *data)
{
	if(s->size==s->capacity)
	{
		return 1;
	}
	(s->top)++;
	(s->size)++;
	s->data[s->top]=data;
	return 0;
}
int pop(stack *s,void **data)
{
	if(s->size==0)
	{
		*data=NULL;
		return 1;
	}
	*data=s->data[s->top];
	(s->size)--;
	(s->top)--;
	return 0;
}
void post_order(tree *t,int *flag)
{
	if(t==NULL)
	{
		return ;
	}
	post_order(t->left,flag);
	post_order(t->right,flag);
	if(*flag==0)
	{
		printf("%d",t->number);
		*flag=1;
	}
	else
	{
		printf(" %d",t->number);
	}
}
int main()
{
	int n,i,index,parent,last_push,flag=0;
	tree *t,*temp;
	stack *s;
	char buf[7],action[5];
	scanf("%d",&n);
	getchar();//注意回车
	s=inti_stack(n);
	t=(tree *)malloc((n+1)*sizeof(tree));
	parent=0;//dummy root
	last_push=1;
	for(i=0;i<n*2;i++)
	{
		gets(buf);
		if(buf[1]=='u')
		{
			sscanf(buf,"%s%d",action,&index);
			t[index].number=index;
			if(last_push)
			{
				t[parent].left=t+index;
			}
			else
			{
				t[parent].right=t+index;
			}
			parent=index;
			push(s,t+index);
			last_push=1;
		}
		else
		{
			if(last_push)
			{
				t[parent].left=NULL;
			}
			else
			{
				t[parent].right=NULL;
			}
			pop(s,(void **)&temp);
			parent=temp->number;
			last_push=0;
		}
	}
	post_order(t[0].left,&flag);
}