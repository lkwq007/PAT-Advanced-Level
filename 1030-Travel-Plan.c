#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef struct vertex_
{
	int known;
	int parent;
	int distance;
	int cost;
} vertex;
int min_unknown(vertex *citys,int n)
{
	int i,min=-1;
	for(i=0;i<n;i++)
	{
		if(citys[i].known==0&&citys[i].distance!=-1&&(min==-1||citys[min].distance>citys[i].distance))
		{
			min=i;
		}
	}
	return min;
}
int shortest_path(int **graph,int **cost_table,vertex *citys,int n,int start)
{
	int temp,i;
	citys[start].distance=0;
	citys[start].cost=0;
	while(1)
	{
		temp=min_unknown(citys,n);
		if(temp==-1)
		{
			break;
		}
		citys[temp].known=1;
		for(i=0;i<n;i++)
		{
			if(graph[temp][i]>0&&citys[i].known==0)
			{
				if(citys[i].distance==-1||
					citys[i].distance>citys[temp].distance+graph[temp][i]||
					(citys[i].distance==citys[temp].distance+graph[temp][i]&&citys[i].cost>citys[temp].cost+cost_table[temp][i]))
				{
					citys[i].distance=citys[temp].distance+graph[temp][i];
					citys[i].cost=citys[temp].cost+cost_table[temp][i];
					citys[i].parent=temp;
				}
			}
		}
	}
}
int main()
{
	int **graph,**cost_table,*result,i,n,m,start,destination,offset,temp,from,to,cost,distance;
	vertex *citys;
	scanf("%d%d%d%d",&n,&m,&start,&destination);
	graph=(int **)malloc(n*sizeof(int *));
	cost_table=(int **)malloc(n*sizeof(int *));
	result=(int *)malloc(n*sizeof(int));
	citys=(vertex *)malloc(n*sizeof(vertex));
	for(i=0;i<n;i++)
	{
		graph[i]=(int *)calloc(n,sizeof(int));
		cost_table[i]=(int *)calloc(n,sizeof(int));
		citys[i].known=0;
		citys[i].distance=-1;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d%d",&from,&to,&distance,&cost);
		graph[from][to]=distance;
		graph[to][from]=distance;
		cost_table[from][to]=cost;
		cost_table[to][from]=cost;
	}
	shortest_path(graph,cost_table,citys,n,start);
	offset=0;
	temp=destination;
	while(temp!=start)
	{
		result[offset++]=temp;
		temp=citys[temp].parent;
	}
	result[offset++]=temp;
	for(i=offset-1;i>=0;i--)
	{
		printf("%d ",result[i]);
	}
	printf("%d %d\n",citys[destination].distance,citys[destination].cost);
}