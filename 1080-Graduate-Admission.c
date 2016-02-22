#include<stdio.h>
#include<stdlib.h>
typedef struct info_
{
	int id;
	int ge;
	int total;
	int choices[5];
} info;
info *applicant;
int quota[100],offset[100],schools[100][40000];
int compare(const void *a,const void *b)
{
	if(((info *)a)->total==((info *)b)->total)
	{
		return ((info *)b)->ge-((info *)a)->ge;
	}
	return ((info *)b)->total-((info *)a)->total;
}
int compare_school(const void *a,const void *b)
{
	return applicant[*(int *)a].id-applicant[*(int *)b].id;
}
int main()
{
	int i,j,n,m,k,temp,last;
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<m;i++)
	{
		scanf("%d",quota+i);
	}
	applicant=(info *)malloc(n*sizeof(info));
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&(applicant[i].ge),&(temp));
		applicant[i].total=applicant[i].ge+temp;
		applicant[i].id=i;
		for(j=0;j<k;j++)
		{
			scanf("%d",&(applicant[i].choices[j]));
		}
	}
	qsort(applicant,n,sizeof(info),compare);
	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++)
		{
			temp=applicant[i].choices[j];
			if(offset[temp]<quota[temp])
			{
				schools[temp][offset[temp]]=i;
				offset[temp]++;
				break;
			}
			else if(offset[temp]>0&&applicant[schools[temp][offset[temp]-1]].total==applicant[i].total&&
				applicant[schools[temp][offset[temp]-1]].ge==applicant[i].ge)
			{
				schools[temp][offset[temp]]=i;
				offset[temp]++;
				break;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		if(offset[i]==0)
		{
			printf("\n");
			continue;
		}
		qsort(schools+i,offset[i],sizeof(int),compare_school);
		printf("%d",applicant[schools[i][0]].id);
		for(j=1;j<offset[i];j++)
		{
			printf(" %d",applicant[schools[i][j]].id);
		}
		printf("\n");
	}
}