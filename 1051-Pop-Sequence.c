#include<stdio.h>
#include<stdlib.h>
typedef struct stack_
{
	int size;
	int capacity;
	int top;
	int *data;
} stack;
#define is_stack_full(X) ((X)->size==(X)->capacity)
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
int reset_stack(stack *s)
{
	s->top=-1;
	s->size=0;
	return 0;
}
int delete_stack(stack *s)
{
	free(s->data);
	free(s);
	return 0;
}
int main()
{
	int i,j,m,n,k,sequence,temp,end;
	char buf[50000];
	stack *s;
	scanf("%d%d%d",&m,&n,&k);
	//sequence=(int *)malloc(n*sizeof(int));
	s=inti_stack(m);
	for(i=0;i<k;i++)
	{
		sequence=1;
		end=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&temp);
			if(s->size>0&&s->data[s->top]==temp)
			{
				pop(s,&temp);
				continue;
			}
			//printf("%d-%d\n",temp,sequence);
			if(sequence>n)
			{
				gets(buf);
				printf("NO\n");
				goto end;
			}
			while(temp!=sequence)
			{
				push(s,sequence);
				sequence++;
				if(is_stack_full(s))
				{
					gets(buf);
					printf("NO\n");
					goto end;
				}
			}
			//push(s,temp);
			sequence++;
		}
		printf("YES\n");
	end:
		reset_stack(s);
	}
}