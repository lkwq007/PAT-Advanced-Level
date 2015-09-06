#include<stdio.h>
#include<stdlib.h>
int c1,c2,count=0,count_p=0,max=0,path=0,shortest=-1,current;
struct road
{
	int destination;
	int distance;
	struct road *next;
};
struct node
{
	int state;
	int prev;
	int num;
	struct road *head;
	struct road *tail;
}*city;
int city_dps()
{
	int next;
	//int temp;
	count+=city[current].num;
	city[current].state=1;
	if(current==c2)
	{
		if(shortest!=-1)
		{
			if(shortest==path)
			{
				count_p++;
				if(count>=max)
					max=count;
			}
			else if(shortest>path)
			{
				shortest=path;
				count_p=1;
				max=count;
			}
		}
		else
		{
			shortest=path;
			count_p=1;
			max=count;
		}
/*		temp=c1;
		do
		{
			printf("%d->",temp);
			temp=city[temp].tail->destination;
		}
		while(temp!=c2);
		printf("%d#count:%d$%d\n",temp,count,path);*/
		return 0;
	}
	while(city[current].tail!=NULL)
	{
		next=city[current].tail->destination;
		if(city[next].state!=-1)
		{
			city[current].tail=city[current].tail->next;
		}
		else
		{
			city[next].prev=current;
			path+=city[current].tail->distance;
			current=next;
			return 1;
		}
	}
	return 0;
}
int back_step()
{
	int prev;
	if(current==c1)
	{
		count=0;
		return 0;
	}
	city[current].state=-1;
	city[current].tail=city[current].head;
	count-=city[current].num;
	prev=city[current].prev;
	current=prev;
	path-=city[current].tail->distance;
	city[current].tail=city[current].tail->next;
	count-=city[current].num;
	return 1;
}
int main()
{
	int n,m,departure,destination,distance;
	int i;
	struct road *temp;
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	city=(struct node *)malloc(n*sizeof(struct node));
	for(i=0;i<n;i++)
	{
		city[i].head=NULL;
		city[i].tail=NULL;
		city[i].state=-1;
		scanf("%d",&city[i].num);
	}
	city[c1].state=1;
	if(c2==c1)
	{
		printf("1 %d",city[c1].num);
		return 0;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&departure,&destination,&distance);
		temp=(struct road *)malloc(sizeof(struct road));
		temp->destination=destination;
		temp->distance=distance;
		temp->next=NULL;
		if(city[departure].head==NULL)
		{
			city[departure].head=temp;
		}
		else
		{
			city[departure].tail->next=temp;
		}
		city[departure].tail=temp;
		temp=(struct road *)malloc(sizeof(struct road));
		temp->destination=departure;
		temp->distance=distance;
		temp->next=NULL;
		if(city[destination].head==NULL)
		{
			city[destination].head=temp;
		}
		else
		{
			city[destination].tail->next=temp;
		}
		city[destination].tail=temp;
	}
	for(i=0;i<n;i++)
	{
		city[i].tail=city[i].head;
	}
	current=c1;
	while(city[c1].tail!=NULL)
	{
		if(!city_dps())
		{
			back_step();
		}
	}
	printf("%d %d\n",count_p,max);
}