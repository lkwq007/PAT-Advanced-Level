#include<stdio.h>
#include<stdlib.h>
#define ABS(X) ((X)>0?(X):-(X))
int main()
{
	int n,i,m,*distance,*record,total=0,from,to,temp;
	scanf("%d",&n);
	distance=(int *)malloc(n*sizeof(int));
	record=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",distance+i);
		record[i]=total;
		total+=distance[i];
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&from,&to);
		temp=ABS(record[from-1]-record[to-1]);
		if(temp>total-temp)
		{
			printf("%d\n",total-temp);
		}
		else
		{
			printf("%d\n",temp);
		}
	}
}