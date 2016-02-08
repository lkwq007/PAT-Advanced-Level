//偷懒了……并不用开一个数组的
#include<stdio.h>
#include<stdlib.h>
#define MALE 0
#define FEMALE 1
typedef struct info_
{
	char name[11];
	char id[11];
	int gender;
	int grade;
} info;
int main()
{
	int n,i,min=-1,max=-1;
	char gender[2];
	info *student;
	scanf("%d",&n);
	student=(info *)malloc(n*sizeof(info));
	for(i=0;i<n;i++)
	{
		scanf("%s%s%s%d",student[i].name,&gender,student[i].id,&(student[i].grade));
		if(gender[0]=='M')
		{
			student[i].gender=MALE;
			if(min==-1||student[min].grade>student[i].grade)
			{
				min=i;
			}
		}
		else
		{
			student[i].gender=FEMALE;
			if(max==-1||student[max].grade<student[i].grade)
			{
				max=i;
			}
		}
	}
	if(max!=-1)
	{
		printf("%s %s\n",student[max].name,student[max].id);
	}
	else
	{
		printf("Absent\n");
	}
	if(min!=-1)
	{
		printf("%s %s\n",student[min].name,student[min].id);
	}
	else
	{
		printf("Absent\n");
	}
	if(max==-1||min==-1)
	{
		printf("NA\n");
	}
	else
	{
		printf("%d\n",student[max].grade-student[min].grade);
	}
}