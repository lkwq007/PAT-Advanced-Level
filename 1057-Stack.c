#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef struct stack_
{
	int size;
	int capacity;
	int top;
	void **data;
	void **copied;
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
	temp->copied=(void **)malloc(n*sizeof(void *));
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
int compare(const void *a,const void *b)
{
	return **(int **)a-**(int **)b;
}
int peekmedian(stack *s,void **data)
{
	int i;
	if(s->size==0)
	{
		*data=NULL;
		return 1;
	}
	if(s->size==1)
	{
		*data=s->data[0];
		return 0;
	}
	memcpy(s->copied,s->data,s->size*sizeof(void *));
	//qsort(s->copied,s->size,sizeof(int *),compare);
	*data=s->data[(s->size+1)/2-1];
	return 0;
}
int main()
{
	int n,i,*temp,value;
	stack *s;
	char command[12],buf[5];
	scanf("%d",&n);
	getchar();
	s=inti_stack(n);
	for(i=0;i<n;i++)
	{
		gets(command);
		switch(command[1])
		{
			case 'u':
			temp=(int *)malloc(sizeof(int));
			sscanf(command,"%s%d",buf,temp);
			push(s,temp);
			break;
			case 'o':
			pop(s,(void **)&temp);
			if(temp==NULL)
			{
				printf("Invalid\n");
			}
			else
			{
				printf("%d\n",*temp);
				free(temp);
			}
			break;
			case 'e':
			peekmedian(s,(void **)&temp);
			if(temp==NULL)
			{
				printf("Invalid\n");
			}
			else
			{
				printf("%d\n",*temp);
			}
			break;
		}
	}
}