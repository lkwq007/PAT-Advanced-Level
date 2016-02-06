#include<stdio.h>
#include<stdlib.h>
typedef struct section_
{
	int supplier;
	int increment;
	int is_retailer;
} section;
section chain[100000];
int main()
{
	int n,i,j,k,distributor,temp,count,min_count,min=-1;
	double p,r;
	//section *chain;
	scanf("%d%lf%lf",&n,&p,&r);
	//chain=(section *)malloc(n*sizeof(section));
	for(i=0;i<n;i++)
	{
		scanf("%d",&k);
		if(k==0)
		{
			chain[i].is_retailer=1;
		}
		else
		{
			chain[i].is_retailer=0;
		}
		for(j=0;j<k;j++)
		{
			scanf("%d",&distributor);
			chain[distributor].supplier=i;
			if(!(i!=0&&chain[i].increment==0))
			{
				chain[distributor].increment=chain[i].increment+1;
			}
			else
			{
				chain[distributor].increment=-1;
			}
		}
	}
	min_count=0;
	for(i=0;i<n;i++)
	{
		if(chain[i].is_retailer!=1)
		{
			continue;
		}
		if(chain[i].increment!=-1)
		{
			goto check;
		}
		temp=i;
		count=0;
		while(temp!=0)
		{
			temp=chain[temp].supplier;
			count++;
			if(chain[temp].increment!=-1)
			{
				count+=chain[temp].increment;
				break;
			}
		}
		chain[i].increment=count;
		temp=i;
		while(temp!=0)
		{
			if(chain[temp].increment!=-1)
			{
				break;
			}
			chain[temp].increment=count;
			temp=chain[temp].supplier;
			count--;
		}
	check:
		if(min==-1||chain[min].increment>chain[i].increment)
		{
			min=i;
			min_count=0;
		}
		if(chain[min].increment==chain[i].increment)
		{
			min_count++;
		}
	}
	r/=100;
	r+=1;
	for(i=0;i<chain[min].increment;i++)
	{
		p*=r;
	}
	printf("%.4lf %d\n",p,min_count);
}