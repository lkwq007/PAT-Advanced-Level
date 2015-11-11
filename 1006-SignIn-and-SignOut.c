//using unstable sort
//need fixing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	char id[16];
	int h;
	int m;
	int s;
} PERSON;
int compare_s(const void *a,const void *b)
{
	return ((PERSON *)a)->s-((PERSON *)b)->s;
}
int compare_m(const void *a,const void *b)
{
	return ((PERSON *)a)->m-((PERSON *)b)->m;
}
int compare_h(const void *a,const void *b)
{
	return ((PERSON *)a)->h-((PERSON *)b)->h;
}
int main()
{
	PERSON *signin,*signout;
	int i,n;
	scanf("%d",&n);
	signin=(PERSON *)malloc(n*sizeof(PERSON));
	signout=(PERSON *)malloc(n*sizeof(PERSON));
	for(i=0;i<n;i++)
	{
		scanf("%s%d:%d:%d%d:%d:%d",signin[i].id,&signin[i].h,&signin[i].m,&signin[i].s,&signout[i].h,&signout[i].m,&signout[i].s);
		strcpy(signout[i].id,signin[i].id);
	}
	qsort(signin,n,sizeof(PERSON),compare_s);
	qsort(signin,n,sizeof(PERSON),compare_m);
	qsort(signin,n,sizeof(PERSON),compare_h);
	qsort(signout,n,sizeof(PERSON),compare_s);
	qsort(signout,n,sizeof(PERSON),compare_m);
	qsort(signout,n,sizeof(PERSON),compare_h);
	printf("%s %s\n",signin[0].id,signout[n-1].id);
}