#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	int i,n,*num,n1,s1=0,sum=0;
	scanf("%d",&n);
	num=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",num+i);
		sum+=num[i];
	}
	qsort(num,n,sizeof(int),compare);
	for(i=0;i<n/2;i++)
	{
		s1+=num[i];
	}
	printf("%d %d\n",n-n/2-n/2,sum-s1-s1);
}