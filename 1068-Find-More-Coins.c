#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int buf[100],result[100],coins[10000];
int match(int ammount,int begin,int n,int offset)
{
	int i;
	if(ammount==0)
	{
		result[offset]=-1;
		return 1;
	}
	else if(ammount<0)
	{
		return 0;
	}
	for(i=begin;i<n;i++)
	{
		if(match(ammount-coins[i],i+1,n,offset+1))
		{
			result[offset]=coins[i];
			return 1;
		}
	}
	return 0;
}
int main()
{
	int n,m,i;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",coins+i);
	}
	qsort(coins,n,sizeof(int),compare);
	for(i=0;i<n;i++)
	{
		if(coins[i]>=m)
		{
			break;
		}
	}
	n=i;
	if(match(m,0,n,0))
	{
		printf("%d",result[0]);
		for(i=1;result[i]>0;i++)
		{
			printf(" %d",result[i]);
		}
	}
	else
	{
		printf("No Solution\n");
	}
	return 0;
}