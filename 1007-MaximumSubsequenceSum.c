#include<stdio.h>
int main()
{
	int i,n,num[10000],iszero=1,*pi,*pj,*mpi,*mpj,sum=0,max=-1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",num+i);
		if(num[i]>=0)
			iszero=0;
	}
	if(iszero)
	{
		printf("0 %d %d\n",num[0],num[n-1]);
		return 0;
	}
	for(pi=num;pi<num+n;pi++)
	{
		sum=0;
		while(*pi<0)
		{
			pi++;
		}
		sum+=*pi;
		for(pj=pi;pj<num+n;pj++)
		{
			sum+=*pj;
			if(pi==pj)
				sum-=*pj;
			if(sum>max)
			{
				max=sum;
				mpi=pi;
				mpj=pj;
			}
		}
	}
	printf("%d %d %d\n",max,*mpi,*mpj);
}