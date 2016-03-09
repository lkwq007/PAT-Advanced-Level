#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
typedef struct stack_
{
	int size;
	int capacity;
	int top;
	int *data;
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
	temp->data=(int *)malloc(n*sizeof(int));
	return temp;
}
int push(stack *s,int data)
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
int pop(stack *s,int *data)
{
	if(s->size==0)
	{
		*data=-1;
		return 1;
	}
	*data=s->data[s->top];
	(s->size)--;
	(s->top)--;
	return 0;
}
int coins[10000];
int main()
{
	int n,m,i,amount;
	stack *s;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",coins+i);
	}
	qsort(coins,n,sizeof(int),compare);
	s=inti_stack(n);
	amount=m;
	for(i=0;i<n;i++)
	{
		if(coins[i]>m)
		{
			break;
		}
	}
	n=i;
	i=0;
	while(1)
	{
		if(amount==0)
		{
			break;
		}
		if(amount-coins[i]>=0&&i<n)
		{
			amount-=coins[i];
			push(s,i);
		}
		else
		{
			pop(s,&i);
			if(i<0)
			{
				printf("No Solution\n");
				return 0;
			}
			amount+=coins[i];
			while(coins[i]==coins[i+1]&&i<n-1)
			{
				i++;
			}
		}
		i++;
	}
	if(amount!=0)
	{
		printf("No Solution\n");
		return 0;
	}
	printf("%d",coins[s->data[0]]);
	for(i=1;i<s->size;i++)
	{
		printf(" %d",coins[s->data[i]]);
	}
	return 0;
}