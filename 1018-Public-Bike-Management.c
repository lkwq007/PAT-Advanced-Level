#include<stdio.h>
#include<stdlib.h>
typedef struct vertex_
{
	int parent;
	int distance;
	int known;
	int condition;
} vertex;
int find_min_unknown(vertex *station,int n)
{
	int i,min=-1;
	for(i=0;i<=n;i++)
	{
		if(station[i].known==0&&station[i].distance!=-1)
		{
			if(min==-1||station[min].distance>station[i].distance)
			{
				min=i;
			}
		}
	}
	return min;
}
int rcompare(vertex *a,vertex *b)
{
	if(a->condition<b->condition)
	{
		return 1;
	}
	return 0;
}
int compare(vertex *a,vertex *b)
{
	if(a->condition>b->condition)
	{
		return 1;
	}
	return 0;
}
void find_shortest_path(int **graph,vertex *station,int n,int (*compare)(vertex *a,vertex *b))
{
	int temp,i;
	while(1)
	{
		temp=find_min_unknown(station,n);
		if(temp==-1)
		{
			break;
		}
		station[temp].known=1;
		for(i=0;i<=n;i++)
		{
			if(graph[temp][i]>0&&!station[i].known)
			{
				if(station[i].distance==-1||station[i].distance>station[temp].distance+graph[temp][i])
				{
					station[i].distance=station[temp].distance+graph[temp][i];
					station[i].parent=temp;
				}
				else if(station[i].distance==station[temp].distance+graph[temp][i])
				{
					if(compare(station+temp,station+station[i].parent))
					{
						station[i].parent=temp;
					}
				}
			}
		}
	}
}
int main()
{
	int **graph,n,m,problem,capacity,i,j,from,to,weight,source,destination,temp,send=0,take=0;
	vertex *station;
	scanf("%d%d%d%d",&capacity,&n,&problem,&m);
	station=(vertex *)malloc((n+1)*sizeof(vertex));
	graph=(int **)malloc((n+1)*sizeof(int *));
	for(i=1;i<=n;i++)
	{
		scanf("%d",&(station[i].condition));
	}
	for(i=0;i<=n;i++)
	{
		graph[i]=(int *)malloc((n+1)*sizeof(int));
		station[i].known=0;
		station[i].distance=-1;
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			graph[i][j]=-1;
		}
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&from,&to,&weight);
		graph[from][to]=weight;
		graph[to][from]=weight;
	}
	if(station[problem].condition<capacity/2)
	{
		source=problem;//实际起点为0
		station[source].distance=0;
		find_shortest_path(graph,station,n,compare);
		source=0;
		destination=problem;
	}
	else
	{
		source=0;//实际起点为problem
		station[source].distance=0;
		find_shortest_path(graph,station,n,compare);
		source=problem;
		destination=0;
	}
	temp=source;
	if(source==0)
	{
		temp=station[temp].parent;
		while(temp!=destination)
		{
			if(station[temp].condition>capacity/2)
			{
				send-=station[temp].condition-capacity/2;
			}
			else
			{
				send+=capacity/2-station[problem].condition;
			}
			temp=station[temp].parent;
		}
		send+=capacity/2-station[problem].condition;
		if(send<0)
		{
			take-=send;
			take=0;
		}
	}
	else
	{
		temp=station[temp].parent;
		while(temp!=destination)
		{
			if(station[temp].condition<capacity/2)
			{
				take-=capacity/2-station[temp].condition;
			}
			else
			{
				take+=station[temp].condition-capacity/2;
			}
			temp=station[temp].parent;
		}
		take+=station[problem].condition-capacity/2;
		if(take<0)
		{
			send-=take;
			take=0;
		}
	}
	printf("%d ",send);
	temp=source;
	printf("%d",temp);
	while(temp!=destination)
	{
		temp=station[temp].parent;
		printf("->%d",temp);
	}
	printf(" %d\n",take);
}