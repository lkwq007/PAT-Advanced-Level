#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct info_
{
	char name[9];
	int age;
	int worth;
} info;
int compare(const void *a,const void *b)
{
	if(((info *)a)->worth==((info *)b)->worth)
	{
		if(((info *)a)->age==((info *)b)->age)
		{
			return strcmp(((info *)a)->name,((info *)b)->name);
		}
		return ((info *)a)->age-((info *)b)->age;
	}
	return ((info *)b)->worth-((info *)a)->worth;
}
int main()
{
	int n,k,m,i,j,min,max,count;
	info *people;
	scanf("%d%d",&n,&k);
	people=(info *)malloc(n*sizeof(info));
	for(i=0;i<n;i++)
	{
		scanf("%s%d%d",people[i].name,&(people[i].age),&(people[i].worth));
	}
	qsort(people,n,sizeof(info),compare);
	for(i=0;i<k;i++)
	{
		scanf("%d%d%d",&m,&min,&max);
		printf("Case #%d:\n",i+1);
		count=0;
		for(j=0;j<n;j++)
		{
			if(count==m)
			{
				break;
			}
			if(people[j].age>=min&&people[j].age<=max)
			{
				count++;
				printf("%s %d %d\n",people[j].name,people[j].age,people[j].worth);
			}
		}
		if(count==0)
		{
			printf("None\n");
		}
	}
}