#include<stdio.h>
#include<stdlib.h>
typedef struct section_
{
	int supplier;
	int increment;
	int amount;
} section;
section chain[100000];
double price[100001];
int main()
{
	int n,i,j,k,distributor,temp,count;
	double p,p_copied,r,total=0;
	//section *chain;
	scanf("%d%lf%lf",&n,&p,&r);
	r/=100;
	r+=1;
	p_copied=p;
	//chain=(section *)malloc(n*sizeof(section));
	price[0]=p;
	for(i=0;i<n;i++)
	{
		scanf("%d",&k);
		if(k==0)
		{
			scanf("%d",&(chain[i].amount));
		}
		else
		{
			chain[i].amount=0;
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
		price[i+1]=price[i]*r;
	}
	for(i=0;i<n;i++)
	{
		if(chain[i].amount==0)
		{
			continue;
		}
		if(chain[i].increment!=-1)
		{
			goto calculate;
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
/*		temp=i;
		while(temp!=0)
		{
			if(chain[temp].increment!=-1)
			{
				break;
			}
			chain[temp].increment=count;
			temp=chain[temp].supplier;
			count--;
		}*/
	calculate:
		total+=price[chain[i].increment]*chain[i].amount;
	}
	printf("%.1lf\n",total);
}