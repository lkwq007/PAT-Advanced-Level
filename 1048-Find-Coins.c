#include<stdio.h>
int coins[501];
int main()
{
	int n,m,i,temp;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		coins[temp]++;
	}
	for(i=1;i<=500;i++)
	{
		if(i>=m)
		{
			break;
		}
		if(2*i==m)
		{
			if(coins[i]>1)
			{
				printf("%d %d\n",i,i);
				return 0;
			}
		}
		else if(m-i<=500&&coins[i]>0&&coins[m-i]>0)
		{
			printf("%d %d\n",i,m-i);
			return 0;
		}
	}
	printf("No Solution\n");
}