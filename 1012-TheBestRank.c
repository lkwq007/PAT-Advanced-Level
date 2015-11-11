//using unstable sort
//need fixing
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int id;
	int grade[4];
/*	int clang;
	int math;
	int eng;
	int average;*/
} STU;
int compare_a(const void *a,const void *b)
{
	return ((STU *)b)->grade[0]-((STU *)a)->grade[0];
}
int compare_c(const void *a,const void *b)
{
	return ((STU *)b)->grade[1]-((STU *)a)->grade[1];
}
int compare_m(const void *a,const void *b)
{
	return ((STU *)b)->grade[2]-((STU *)a)->grade[2];
}
int compare_e(const void *a,const void *b)
{
	return ((STU *)b)->grade[3]-((STU *)a)->grade[3];
}
int main()
{
	int (*compare[4])(const void *a,const void *b);
	int n,m,i,j,latest,min,k,count=0;
	char mark[5]="ACME";
	STU *student;
	compare[0]=compare_a;
	compare[1]=compare_c;
	compare[2]=compare_m;
	compare[3]=compare_e;
	scanf("%d%d",&n,&m);
	if(n<=0)
		return 0;
	student=(STU *)malloc(n*sizeof(STU));
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&(student[i].id),&(student[i].grade[1]),&(student[i].grade[2]),&(student[i].grade[3]));
		student[i].grade[0]=(student[i].grade[1]+student[i].grade[2]+student[i].grade[3])/3.0+0.5;
	}
	for(j=3;j>=0;j--)
	{
		qsort(student,n,sizeof(STU),compare[j]);
		latest=student->grade[j];
		student->grade[j]=1;
		count=0;
		for(i=1;i<n;i++)
		{
			if(student[i].grade[j]==latest)
			{
				student[i].grade[j]=student[i-1].grade[j];
				count++;
			}
			else
			{
				latest=student[i].grade[j];
				student[i].grade[j]=student[i-1].grade[j]+1+count;
				count=0;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		scanf("%d",&latest);
		for(j=0;j<n;j++)
		{
			if(student[j].id==latest)
				break;
		}
		if(j==n)
		{
			printf("N/A\n");
		}
		else
		{
			min=0;
			for(k=1;k<4;k++)
			{
				if(student[j].grade[k]<student[j].grade[min])
					min=k;
			}
			printf("%d %c\n",student[j].grade[min],mark[min]);
		}
	}
}