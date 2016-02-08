#include<stdio.h>
#include<stdlib.h>
typedef struct info_
{
	//long long id;
	char id[14];
	int location;
	int score;
	int loacl_rank;
	int rank;
} info;
int compare_score(const void *a,const void *b)
{
	return ((info *)b)->score-((info *)a)->score;
}
int compare(const void *pa,const void *pb)
{
	info *a=(info *)pa,*b=(info *)pb;
	if(a->score>b->score)
	{
		return -1;
	}
	else if(a->score<b->score)
	{
		return 1;
	}
	else
	{
		//return a->id-b->id;
		return strcmp(a->id,b->id);
	}
}
int main()
{
	//info *testee;
	info testee[30000];
	int n,k,i,j,total=0,offset=0;
	scanf("%d",&n);
	//testee=(info *)malloc(sizeof(info));
	for(i=0;i<n;i++)
	{
		scanf("%d",&k);
		offset=total;
		total+=k;
		//testee=(info *)realloc(testee,total*sizeof(info));
		for(j=0;j<k;j++)
		{
			scanf("%s %d",(testee[j+offset].id),&(testee[j+offset].score));
			testee[j+offset].location=i+1;
		}
		qsort(testee+offset,k,sizeof(info),compare_score);
		testee[offset].loacl_rank=1;
		for(j=1;j<k;j++)
		{
			if(testee[j+offset].score==testee[j+offset-1].score)
			{
				testee[j+offset].loacl_rank=testee[j+offset-1].loacl_rank;
			}
			else
			{
				testee[j+offset].loacl_rank=j+1;
			}
		}
	}
	qsort(testee,total,sizeof(info),compare);
	printf("%d\n",total);
	testee[0].rank=1;
	printf("%s %d %d %d\n",testee[0].id,testee[0].rank,testee[0].location,testee[0].loacl_rank);
	for(i=1;i<total;i++)
	{
		if(testee[i].score==testee[i-1].score)
		{
			testee[i].rank=testee[i-1].rank;
		}
		else
		{
			testee[i].rank=i+1;
		}
		printf("%s %d %d %d\n",testee[i].id,testee[i].rank,testee[i].location,testee[i].loacl_rank);
	}
}