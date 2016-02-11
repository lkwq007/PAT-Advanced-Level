#include<stdio.h>
#include<stdlib.h>
#define ERROR -1
#define NOT_SUBMITED -2
typedef struct info_
{
	int id;
	int total;
	int perfect_count;
	int *score;
	int *perfect;
	int shown;
} info;
int compare(const void *a,const void *b)
{
	if(((info *)a)->shown==0)
	{
		return 1;
	}
	if(((info *)a)->total==((info *)b)->total)
	{
		if(((info *)a)->perfect_count==((info *)b)->perfect_count)
		{
			return ((info *)a)->id-((info *)b)->id;
		}
		return ((info *)b)->perfect_count-((info *)a)->perfect_count;
	}
	return ((info *)b)->total-((info *)a)->total;
}
int main()
{
	int n,k,m,i,j,*scores,id,problem_id,partial_score,last=1;
	info *user;
	scanf("%d%d%d",&n,&k,&m);
	scores=(int *)malloc(k*sizeof(int));
	user=(info *)malloc(n*sizeof(info));
	for(i=0;i<k;i++)
	{
		scanf("%d",scores+i);
	}
	for(i=0;i<n;i++)
	{
		user[i].id=i+1;
		user[i].total=0;
		user[i].perfect_count=0;
		user[i].shown=0;
		user[i].score=(int *)malloc(k*sizeof(int));
		user[i].perfect=(int *)malloc(k*sizeof(int));
		for(j=0;j<k;j++)
		{
			user[i].score[j]=NOT_SUBMITED;
			user[i].perfect[j]=0;
		}
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&id,&problem_id,&partial_score);
		if(partial_score!=-1)
		{
			user[id-1].shown=1;
		}
		if(partial_score==scores[problem_id-1]&&user[id-1].perfect[problem_id-1]==0)
		{
			user[id-1].perfect[problem_id-1]=1;
			user[id-1].perfect_count++;
		}
		if(user[id-1].score[problem_id-1]<partial_score)
		{
			if(partial_score==-1)
			{
				partial_score=0;
			}
			if(user[id-1].score[problem_id-1]>-2)
			{
				user[id-1].total-=user[id-1].score[problem_id-1];
			}
			user[id-1].score[problem_id-1]=partial_score;
			user[id-1].total+=partial_score;
		}
	}
	qsort(user,n,sizeof(info),compare);
	printf("1 %05d %d ",user[0].id,user[0].total);
	for(j=0;j<k-1;j++)
	{
		if(user[0].score[j]==NOT_SUBMITED)
		{
			printf("- ");
		}
		else
		{
			printf("%d ",user[0].score[j]);
		}
	}
	if(user[0].score[j]<0)
	{
		printf("-\n");
	}
	else
	{
		printf("%d\n",user[0].score[j]);
	}
	for(i=1;i<n;i++)
	{
		if(user[i].shown==0)
		{
			break;
		}
		if(user[i].total==user[i-1].total)
		{
			printf("%d ",last);
		}
		else
		{
			printf("%d ",i+1);
			last=i+1;
		}
		printf("%05d %d ",user[i].id,user[i].total);
		for(j=0;j<k-1;j++)
		{
			if(user[i].score[j]<0)
			{
				printf("- ");
			}
			else
			{
				printf("%d ",user[i].score[j]);
			}
		}
		if(user[i].score[j]<0)
		{
			printf("-\n");
		}
		else
		{
			printf("%d\n",user[i].score[j]);
		}
	}
}