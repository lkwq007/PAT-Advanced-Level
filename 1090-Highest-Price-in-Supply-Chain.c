//思路与 1106 差不多
//注意优化，容易超时
#include<stdio.h>
#include<stdlib.h>
typedef struct section_
{
	int supplier;
	int increment;
} section;
int main()
{
	int n,i,supplier,max=0,max_count=0,count=0,temp;
	double p,r;
	section *chain;
	scanf("%d%lf%lf",&n,&p,&r);
	r/=100;
	r+=1;
	chain=(section *)malloc(n*sizeof(section));
	for(i=0;i<n;i++)
	{
		scanf("%d",&supplier);
		chain[i].supplier=supplier;
		if(supplier==-1)
		{
			chain[i].increment=0;
		}
		else
		{
			chain[i].increment=-1;
		}
	}
	for(i=0;i<n;i++)
	{
		temp=i;
		count=0;
		while(temp!=-1)
		{
			count++;
			if(chain[temp].increment!=-1)
			{
				count+=chain[temp].increment;
				break;
			}
			temp=chain[temp].supplier;
		}
		temp=i;
		while(temp!=-1)
		{
			count--;
			if(chain[temp].increment!=-1)
			{
				break;
			}
			chain[temp].increment=count;
			temp=chain[temp].supplier;
		}
		if(chain[i].increment>chain[max].increment)
		{
			max=i;
			max_count=0;
		}
		if(chain[i].increment==chain[max].increment)
		{
			max_count++;
		}
	}
	for(i=0;i<chain[max].increment;i++)
	{
		p*=r;
	}
	printf("%.2lf %d\n",p,max_count);
}