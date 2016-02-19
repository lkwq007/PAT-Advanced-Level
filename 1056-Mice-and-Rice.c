#include<stdio.h>
#include<stdlib.h>
typedef struct info_
{
	int order;
	int rank;
	int weight;
} info;
int main()
{
	int n,i,j,group,*list,*list_copied,total,group_number,rank,max,flag=0;
	info *mice;
	scanf("%d%d",&n,&group);
	mice=(info *)malloc(n*sizeof(info));
	list=(int *)malloc(n*sizeof(int));
	list_copied=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",&(mice[i].weight));
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",list+i);
	}
/*	total=n;
	times=0;
	while(total>0)
	{
		times++;
		total/=group;
	}*/
	total=n;
	while(total>0)
	{
		group_number=(total+group-1)/group;
		rank-=total-group_number;
		if(total==1)
		{
			rank--;
		}
		for(i=0;i<group_number-1;i++)
		{
			max=i*group;
			for(j=i*group;j<i*group+group;j++)
			{
				if(mice[list[j]].weight>mice[list[max]].weight)
				{
					max=j;
				}
			}
			for(j=i*group;j<i*group+group;j++)
			{
				mice[list[j]].rank=rank;
			}
			list_copied[i]=list[max];
		}
		max=i*group;
		for(j=i*group;j<total;j++)
		{
			if(mice[list[j]].weight>mice[list[max]].weight)
			{
				max=j;
			}
		}
		for(j=i*group;j<total;j++)
		{
			mice[list[j]].rank=rank;
		}
		list_copied[i]=list[max];
		for(i=0;i<total;i++)
		{
			list[i]=list_copied[i];
		}
		if(total==1)
		{
			break;
		}
		total=group_number;
	}
	rank=mice[list[0]].rank;
	printf("%d",mice[0].rank-rank+1);
	for(i=1;i<n;i++)
	{
		printf(" %d",mice[i].rank-rank+1);
	}
}