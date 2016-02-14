#include<stdio.h>
#include<math.h>
int is_prime(long long n)
{
	long long i,end;
	end=sqrt((double)n);
	if(n<2)
	{
		return 0;
	}
	for(i=2;i<=end;i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	long long i,n,temp,factor[64],offset=0,count;
	scanf("%lld",&n);
	temp=n;
	for(i=2;i<=temp;i+=2)
	{
		if(is_prime(i)&&temp%i==0)
		{
			factor[offset++]=i;
			temp/=i;
			i=i-2;
		}
		if(i==2)
		{
			i=1;
		}
	}
	if(n<2)
	{
		printf("%lld=%lld\n",n,n);//测试点3，n=1时，输出结果为"1=1"
		return 0;
	}
	printf("%lld=%lld",n,factor[0]);
	count=1;
	for(i=1;i<offset;i++)
	{
		if(factor[i]==factor[i-1])
		{
			count++;
		}
		else
		{
			if(count>1)
			{
				printf("^%lld",count);
			}
			printf("*%lld",factor[i]);
			count=1;
		}
	}
	if(count>1)
	{
		printf("^%lld",count);
	}
}