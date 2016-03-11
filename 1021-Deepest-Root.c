#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef struct list_
{
	int id;
	struct list_ *next;
} list;
typedef struct vertex_
{
	list *adjacent;
} vertex;
int set_found(int *set,int index)
{
	int root,temp;
	temp=index;
	while(set[temp]>-1)
	{
		temp=set[temp];
	}
	root=temp;
	temp=index;
	while(set[temp]>-1)
	{
		index=temp;
		temp=set[temp];
		set[index]=root;
	}
	return root;
}
int set_union(int *set,int a,int b)
{
	a=set_found(set,a);
	b=set_found(set,b);
	if(a==b)
	{
		return 0;
	}
	if(set[a]<set[b])
	{
		set[a]+=set[b];
		set[b]=a;
	}
	else
	{
		set[b]+=set[a];
		set[a]=b;
	}
	return 1;
}
int main()
{
	int i,n,total,from,to,*node_no,*stack,top=-1,current,*record,max=0,offset=0,*set;
	vertex *node;
	list *temp;
	scanf("%d",&n);
	total=n;
	node=(vertex *)malloc((n+1)*sizeof(vertex));
	node_no=(int *)malloc((n+1)*sizeof(int));
	record=(int *)malloc(n*sizeof(int));
	stack=(int *)malloc(n*sizeof(int));
	set=(int *)malloc((n+1)*sizeof(int));
	memset(set,0xFF,(n+1)*sizeof(int));
	for(i=0;i<=n;i++)
	{
		node[i].adjacent=NULL;
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&from,&to);
		if(set_union(set,from,to))
		{
			total--;
		}
		temp=(list *)malloc(sizeof(list));
		temp->id=to;
		temp->next=node[from].adjacent;
		node[from].adjacent=temp;
		temp=(list *)malloc(sizeof(list));
		temp->id=from;
		temp->next=node[to].adjacent;
		node[to].adjacent=temp;
	}
	if(total!=1)
	{
		printf("Error: %d components\n",total);
		return 0;
	}
	total=0;
	for(i=1;i<=n;i++)
	{
		max=0;
		memset(node_no,0xFF,(n+1)*sizeof(int));
		stack[++top]=i;
		node_no[i]=1;
		while(top>-1)
		{
			current=stack[top--];
			temp=node[current].adjacent;
			if(node_no[current]>max)
			{
				max=node_no[current];
			}
			while(temp!=NULL)
			{
				if(node_no[temp->id]==-1)
				{
					node_no[temp->id]=node_no[current]+1;
					stack[++top]=temp->id;
				}
				temp=temp->next;
			}
		}
		if(total<max)
		{
			total=max;
			offset=0;
		}
		if(max==total)
		{
			record[offset++]=i;
		}
	}
	for(i=0;i<offset;i++)
	{
		printf("%d\n",record[i]);
	}
}