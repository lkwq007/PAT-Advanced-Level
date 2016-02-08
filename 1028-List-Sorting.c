#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list_
{
	char name[9];
	int id;
	int grade;
} list;
int compare_grade(const void *a,const void *b)
{
	if(((list *)a)->grade<((list *)b)->grade)
	{
		return -1;
	}
	if(((list *)a)->grade>((list *)b)->grade)
	{
		return 1;
	}
	return ((list *)a)->id-((list *)b)->id;
}
int compare_name(const void *a,const void *b)
{
	if(!strcmp(((list *)a)->name,((list *)b)->name))
	{
		return ((list *)a)->id-((list *)b)->id;
	}
	return strcmp(((list *)a)->name,((list *)b)->name);
}
int compare_id(const void *a,const void *b)
{
	return ((list *)a)->id-((list *)b)->id;
}
int main()
{
	int i,n,c;
	int (*compare)();
	list *student;
	scanf("%d%d",&n,&c);
	student=(list *)malloc(n*sizeof(list));
	for(i=0;i<n;i++)
	{
		scanf("%d%s%d",&(student[i].id),student[i].name,&(student[i].grade));
	}
	switch(c)
	{
		case 1:
		compare=compare_id;
		break;
		case 2:
		compare=compare_name;
		break;
		case 3:
		compare=compare_grade;
		break;
	}
	qsort(student,n,sizeof(list),compare);
	for(i=0;i<n;i++)
	{
		printf("%06d %s %d\n",student[i].id,student[i].name,student[i].grade);
	}
}