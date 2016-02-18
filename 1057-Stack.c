#include<stdio.h>
#include<stdlib.h>
#define max_val 100001
typedef struct stack_
{
	int size;
	int capacity;
	int top;
	int *data;
} stack;
int tree[max_val];
int get(int index)
{
	int sum=0;
	while(index>0)
	{
		sum+=tree[index];
		index-=(index&-index);
	}
	return sum;
}
int update(int index,int value,int max)
{
	while(index<=max)
	{
		tree[index]+=value;
		index+=(index&-index);
	}
	return 0;
}
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
	update(data,1,s->capacity);
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
	update(*data,-1,s->capacity);
	(s->size)--;
	(s->top)--;
	return 0;
}
int find(int dest,int begin,int end)
{
	if(begin==end)
	{
		return begin;
	}
	if(get((begin+end)/2)>=dest)
	{
		return find(dest,begin,(begin+end)/2);		
	}
	else
	{
		return find(dest,(begin+end)/2+1,end);
	}
}
int peekmedian(stack *s,int *data)
{
	int i,n;
	if(s->size==0)
	{
		*data=-1;
		return 1;
	}
	if(s->size==1)
	{
		*data=s->data[0];
		return 0;
	}
	n=(s->size+1)/2;
	*data=find(n,1,s->capacity);
	return 0;
}
int main()
{
	int n,i,temp,value;
	stack *s;
	char command[12],buf[5];
	scanf("%d",&n);
	getchar();
	s=inti_stack(max_val);
	for(i=0;i<n;i++)
	{
		gets(command);
		switch(command[1])
		{
			case 'u':
			sscanf(command,"%s%d",buf,&temp);
			push(s,temp);
			break;
			case 'o':
			pop(s,&temp);
			if(temp==-1)
			{
				printf("Invalid\n");
			}
			else
			{
				printf("%d\n",temp);
			}
			break;
			case 'e':
			peekmedian(s,&temp);
			if(temp==-1)
			{
				printf("Invalid\n");
			}
			else
			{
				printf("%d\n",temp);
			}
			break;
		}
	}
}