#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef struct mgraph_
{
	int length;
	int time_cost;
} mgraph;
mgraph graph[500][500];
typedef struct vertex_
{
	int known;
	int parent;
	int distance;
	int time_cost;
} vertex;
int find_shortest_unknown(vertex *path,int n)
{
	int i,min=-1;
	for(i=0;i<n;i++)
	{
		if(path[i].known==-1&&path[i].distance!=-1&&(min==-1||path[i].distance<path[min].distance))
		{
			min=i;
		}
	}
	return min;
}
int find_fastest_unknown(vertex *path,int n)
{
	int i,min=-1;
	for(i=0;i<n;i++)
	{
		if(path[i].known==-1&&path[i].time_cost!=-1&&(min==-1||path[i].time_cost<path[min].time_cost))
		{
			min=i;
		}
	}
	return min;
}
int shortest_path(vertex *path,int n)
{
	int temp,i;
	while(1)
	{
		temp=find_shortest_unknown(path,n);
		if(temp==-1)
		{
			break;
		}
		path[temp].known=1;
		for(i=0;i<n;i++)
		{
			if(graph[temp][i].length>0&&path[i].known==-1)
			{
				if(path[i].distance==-1||path[i].distance>path[temp].distance+graph[temp][i].length)
				{
					path[i].distance=path[temp].distance+graph[temp][i].length;
					path[i].time_cost=path[temp].time_cost+graph[temp][i].time_cost;
					path[i].parent=temp;
				}
				else if(path[i].distance==path[temp].distance+graph[temp][i].length)
				{
					if(path[i].time_cost>path[temp].time_cost+graph[temp][i].time_cost)
					{
						path[i].time_cost=path[temp].time_cost+graph[temp][i].time_cost;
						path[i].parent=temp;
					}
				}
			}
		}
	}
}
int fastest_path(vertex *path,int n)
{
	int temp,i;
	while(1)
	{
		temp=find_fastest_unknown(path,n);
		if(temp==-1)
		{
			break;
		}
		path[temp].known=1;
		for(i=0;i<n;i++)
		{
			if(graph[temp][i].time_cost>0&&path[i].known==-1)
			{
				if(path[i].time_cost==-1||graph[temp][i].time_cost+path[temp].time_cost<path[i].time_cost)
				{
					path[i].distance=path[temp].distance+1;
					path[i].time_cost=graph[temp][i].time_cost+path[temp].time_cost;
					path[i].parent=temp;
				}
				else if(graph[temp][i].time_cost+path[temp].time_cost==path[i].time_cost)
				{
					if(path[temp].distance+1<path[i].distance)
					{
						path[i].distance=path[temp].distance+1;
						path[i].parent=temp;
					}
				}
			}
		}
	}
}
int main()
{
	int n,m,i,j,v1,v2,state,length,time_cost,source,destination,temp,*result[2],offset[2];
	vertex *path[2];
	scanf("%d%d",&n,&m);
	result[0]=(int *)malloc(n*sizeof(int));
	result[1]=(int *)malloc(n*sizeof(int));
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d%d%d",&v1,&v2,&state,&length,&time_cost);
		graph[v1][v2].length=length;
		graph[v1][v2].time_cost=time_cost;
		if(state==0)
		{
			graph[v2][v1].length=length;
			graph[v2][v1].time_cost=time_cost;
		}
	}
	scanf("%d%d",&source,&destination);
	for(i=0;i<2;i++)
	{
		path[i]=(vertex *)malloc(n*sizeof(vertex));
		memset(path[i],0xFF,n*sizeof(vertex));
		path[i][source].distance=0;
		path[i][source].time_cost=0;
	}
	shortest_path(path[0],n);
	fastest_path(path[1],n);
	for(i=0;i<2;i++)
	{
		temp=destination;
		offset[i]=0;
		while(path[i][temp].parent!=-1)
		{
			result[i][offset[i]++]=temp;
			temp=path[i][temp].parent;
		}
		result[i][offset[i]]=temp;
	}
	if(offset[0]==offset[1])
	{
		for(i=0;i<offset[0];i++)
		{
			if(result[0][i]!=result[1][i])
			{
				break;
			}
		}
		if(i==offset[0])
		{
			printf("Distance = %d; Time = %d: ",path[0][destination].distance,path[0][destination].time_cost);
			printf("%d",source);
			for(i=offset[0]-1;i>=0;i--)
			{
				printf(" -> %d",result[0][i]);
			}
			printf("\n");
			return 0;
		}
	}
	printf("Distance = %d: ",path[0][destination].distance);
	printf("%d",source);
	for(i=offset[0]-1;i>=0;i--)
	{
		printf(" -> %d",result[0][i]);
	}
	printf("\n");
	printf("Time = %d: ",path[1][destination].time_cost);
	printf("%d",source);
	for(i=offset[1]-1;i>=0;i--)
	{
		printf(" -> %d",result[1][i]);
	}
	printf("\n");
}