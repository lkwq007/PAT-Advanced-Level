#include<stdio.h>
#include<stdlib.h>
typedef struct info_
{
	char name[11];
	char id[11];
	int grade;
} info;
int compare(const void *a,const void *b)
{
	return ((info *)b)->grade-((info *)a)->grade;
}
int main()
{
	int n,i,min,max,flag=1;
	info *student;
	scanf("%d",&n);
	student=(info *)malloc(n*sizeof(info));
	for(i=0;i<n;i++)
	{
		scanf("%s%s%d",student[i].name,student[i].id,&(student[i].grade));
	}
	scanf("%d%d",&min,&max);
	qsort(student,n,sizeof(info),compare);
	for(i=0;i<n;i++)
	{
		if(student[i].grade>=min&&student[i].grade<=max)
		{
			printf("%s %s\n",student[i].name,student[i].id);
			flag=0;
		}
	}
	if(flag)
	{
		printf("NONE\n");
	}
}