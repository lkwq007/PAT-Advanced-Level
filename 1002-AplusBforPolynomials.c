#include<stdio.h>
double coefficient[1001];
int main()
{
	int i,count=0,n,index;
	double temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%lf",&index,&temp);
		coefficient[index]+=temp;
	}
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%lf",&index,&temp);
		coefficient[index]+=temp;
	}
	for(i=1000;i>=0;i--)
	{
		if(coefficient[i]!=0)
		{
			count++;
			index=i;
		}
	}
	if(count>0)
	{
		printf("%d ",count);
		for(i=1000;i>index;i--)
		{
			if(coefficient[i]!=0)
				printf("%d %.1lf ",i,coefficient[i]);
		}
		printf("%d %.1lf",i,coefficient[i]);
	}
	else
		printf("%d",count);

}