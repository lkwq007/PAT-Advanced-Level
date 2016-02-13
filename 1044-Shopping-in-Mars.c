#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *value,i,j,n,m,temp,total=0,min=0,flag=1;
	scanf("%d%d",&n,&m);
	value=(int *)malloc((n+1)*sizeof(int));
	value[0]=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		total+=temp;
		value[i+1]=total;
	}
	for(i=0;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(value[j]-value[i]==m)
			{
				printf("%d-%d\n",i+1,j);
				flag=0;
				break;
			}
			else if(flag&&value[j]-value[i]>m&&(min==0||value[j]-value[i]-m<min))
			{
				min=value[j]-value[i]-m;
				break;
			}
		}
	}
	if(flag)
	{
		for(i=0;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(value[j]-value[i]-m==min)
				{
					printf("%d-%d\n",i+1,j);
					break;
				}
			}
		}
	}
}