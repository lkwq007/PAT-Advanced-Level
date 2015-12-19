#include<stdio.h>
#include<stdlib.h>
typedef struct node_
{
	int no;
	struct node_ *next; 
} node;
typedef struct 
{
/*	int num;*/
	node *list;
} graph;
int set_found(int *set,int no)
{
	int temp=no;
	while(set[temp]>0)
	{
		temp=set[temp];
	}
	while(set[no]>0)
	{
		set[no]=temp;
		no=set[no];
	}
	return temp;
}
int set_union(int *set,int no_1,int no_2)
{
	no_1=set_found(set,no_1);
	no_2=set_found(set,no_2);
	if(no_1==no_2)
		return 0;
	if(set[no_1]<set[no_2])
	{
		set[no_1]+=set[no_2];
		set[no_2]=no_1;
	}
	else
	{
		set[no_2]+=set[no_1];
		set[no_1]=no_2;
	}
	return 1;
}
int connect(graph *roads,int from,int to)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->no=to;
	temp->next=roads[from].list;
	roads[from].list=temp;
	/*roads[from].num++;*/
	temp=(node *)malloc(sizeof(node));
	temp->no=from;
	temp->next=roads[to].list;
	roads[to].list=temp;
	/*roads[to].num++;*/
	return 0;
}
int main()
{
	int n,m,k,i,j,from,to,*citys,lost,total;
	graph *roads;
	node *temp;
	scanf("%d%d%d",&n,&m,&k);
	citys=(int *)malloc((n+1)*sizeof(int));
	roads=(graph *)malloc((n+1)*sizeof(graph));
	for(i=1;i<=n;i++)
	{
/*		roads[i].num=0;*/
		roads[i].list=NULL;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&from,&to);
		connect(roads,from,to);
	}
	for(i=0;i<k;i++)
	{
		total=n;
		for(j=1;j<=n;j++)
		{
			citys[j]=-1;
		}
		scanf("%d",&lost);
		for(j=1;j<=n;j++)
		{
			if(j==lost)
				continue;
			if(roads[j].list!=NULL)
			{
				temp=roads[j].list;
				while(temp!=NULL)
				{
					if(temp->no!=lost)
					{
						if(set_union(citys,j,temp->no))
						{
							total--;
						}
					}
					temp=temp->next;
				}
			}
		}
		printf("%d\n",total-2);//total_num-the_lost_city(1)=rest_sets; connections=rest_sets-1
	}
}