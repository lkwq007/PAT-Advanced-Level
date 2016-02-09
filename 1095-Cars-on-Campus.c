#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define IN 0
#define OUT 1
#define UNAVAILABLE -1
typedef struct info_
{
	char plate[9];
	int time_point;
	int status;
	int cost;
} info;
int compare_each(const void *a,const void *b)
{
	if(!strcmp(((info *)a)->plate,((info *)b)->plate))
	{
		return ((info *)a)->time_point-((info *)b)->time_point;
	}
	return strcmp(((info *)a)->plate,((info *)b)->plate);
}
int compare_all(const void *a,const void *b)
{
	return ((info *)a)->time_point-((info *)b)->time_point;
}
int compare_cost(const void *a,const void *b)
{
	if(((info *)b)->cost==((info *)a)->cost)
	{
		return strcmp(((info *)a)->plate,((info *)b)->plate);
	}
	return ((info *)b)->cost-((info *)a)->cost;
}
int main()
{
	int n,k,i,hh,mm,ss,flag,total=0,offset=0,last=-1;
	char buf[4];
	info *record,*longest;
	scanf("%d%d",&n,&k);
	record=(info *)malloc(n*sizeof(info));
	longest=(info *)malloc(n*sizeof(info));
	for(i=0;i<n;i++)
	{
		scanf("%s%d:%d:%d%s",record[i].plate,&hh,&mm,&ss,buf);
		record[i].time_point=hh*3600+mm*60+ss;
		record[i].cost=0;
		if(buf[0]=='i')
		{
			record[i].status=IN;
		}
		else
		{
			record[i].status=OUT;
		}
	}
	qsort(record,n,sizeof(info),compare_each);
	for(i=0;i<n;i++)
	{
		if(record[i].status==IN&&i<n-1&&!strcmp(record[i].plate,record[i+1].plate)&&record[i+1].status==OUT)
		{
			if(last!=-1&&!strcmp(record[i].plate,record[last].plate))
			{
				record[i+1].cost=record[i+1].time_point-record[i].time_point+record[last].cost;
				record[last].cost=0;
			}
			else
			{
				record[i+1].cost=record[i+1].time_point-record[i].time_point;
			}
			i+=1;
			last=i;
		}
		else
		{
			record[i].status=UNAVAILABLE;
		}
	}
	qsort(record,n,sizeof(info),compare_all);
	for(i=0;i<k;i++)
	{
		scanf("%d:%d:%d",&hh,&mm,&ss);
		ss+=hh*3600+mm*60;
		while(offset<n&&record[offset].time_point<=ss)
		{
			if(record[offset].status==IN)
			{
				total+=1;
			}
			else if(record[offset].status==OUT)
			{
				total-=1;
			}
			offset++;
		}
		printf("%d\n",total);
	}
	qsort(record,n,sizeof(info),compare_cost);
	printf("%s ",record[0].plate);
	for(i=1;i<n;i++)
	{
		if(record[i].cost!=record[i-1].cost)
		{
			break;
		}
		printf("%s ",record[i].plate);
	}
	printf("%02d:%02d:%02d\n",record[i-1].cost/3600,(record[i-1].cost/60)%60,record[i-1].cost%60);
}