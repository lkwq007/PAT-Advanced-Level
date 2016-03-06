#include<stdio.h>
#include<stdlib.h>
#define STROKE 1
#define NORMAL 0
#define SCANED -1
typedef struct postion_
{
	int x;
	int y;
	int z;
} postion;
typedef struct stack_
{
	int size;
	int capacity;
	int top;
	postion *data;
} stack;
postion directions[6]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
int m,n,l,t,***slices;
stack *s;
#define is_stack_empty(X) (!((X)->size))
#define ptr_top(X) ((X)->data[(X)->top])
stack *inti_stack(int n)
{
	stack *temp;
	temp=(stack *)malloc(sizeof(stack));
	temp->size=0;
	temp->capacity=n;
	temp->top=-1;
	temp->data=(postion *)malloc(n*sizeof(postion));
	return temp;
}
int push(stack *s,postion data)
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
int pop(stack *s,postion *data)
{
	if(s->size==0)
	{
		return 1;
	}
	*data=s->data[s->top];
	(s->size)--;
	(s->top)--;
	return 0;
}
int reset_stack(stack *s)
{
	if(s==NULL)
	{
		return 1;
	}
	s->size=0;
	s->top=-1;
	return 0;
}
int can_scan(postion pos,int direct)
{
	int x,y,z;
	x=pos.x+directions[direct].x;
	y=pos.y+directions[direct].y;
	z=pos.z+directions[direct].z;
	if(x<0||x>=n||y<0||y>=m||z<0||z>=l||slices[z][y][x]!=STROKE)
	{
		return 0;
	}
	return 1;
}
int scan_this_area(postion pos)
{
	int count=0,i;
	postion temp;
	push(s,pos);
	while(!is_stack_empty(s))
	{
		pop(s,&pos);
		if(slices[pos.z][pos.y][pos.x]!=SCANED)
		{
			slices[pos.z][pos.y][pos.x]=SCANED;
			count++;
		}
		for(i=0;i<6;i++)
		{
			if(can_scan(pos,i))
			{
				temp.x=pos.x+directions[i].x;
				temp.y=pos.y+directions[i].y;
				temp.z=pos.z+directions[i].z;
				push(s,temp);
			}
		}
	}
	if(count<t)
	{
		return 0;
	}
	return count;
}
int main()
{
	int i,j,k,offset=0,count=0;
	postion *record;
	scanf("%d%d%d%d",&m,&n,&l,&t);
	slices=(int ***)malloc(l*sizeof(int **));
	record=(postion *)malloc(m*n*l*sizeof(postion));
	s=inti_stack(m*n*l);
	for(i=0;i<l;i++)
	{
		slices[i]=(int **)malloc(m*sizeof(int *));
		for(j=0;j<n;j++)
		{
			slices[i][j]=(int *)malloc(n*sizeof(int));
		}
	}
	for(i=0;i<l;i++)
	{
		for(j=0;j<m;j++)
		{
			for(k=0;k<n;k++)
			{
				scanf("%d",&slices[i][j][k]);
				if(slices[i][j][k]==STROKE)
				{
					record[offset].z=i;
					record[offset].y=j;
					record[offset].x=k;
					offset++;
				}
			}
		}
	}
	for(i=0;i<offset;i++)
	{
		if(slices[record[i].z][record[i].y][record[i].x]==STROKE)
		{
			count+=scan_this_area(record[i]);
		}
	}
	printf("%d\n",count);
}