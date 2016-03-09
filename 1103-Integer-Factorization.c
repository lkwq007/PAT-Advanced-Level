#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>
int npow(int base,int power)
{
	int i,result=1;
	for(i=0;i<power;i++)
	{
		result*=base;
	}
	return result;
}
int max,result[400],buf[400];
int factor(int n,int begin,int k,int p,int sum)
{
	int i,number,flag=0;
	if(k==0&&n==0)
	{
		if(sum>=max)
		{
			max=sum;
			memcpy(result,buf,400*sizeof(int));
		}
		return 1;
	}
	if(k==0)
	{
		return 0;
	}
	for(i=begin;i<=sqrt(n);i++)
	{
		number=n-npow(i,p);
		if(number<k-1)
		{
			break;
		}
		sum+=i;
		buf[k-1]=i;
		if(factor(number,i,k-1,p,sum))
		{
			flag=1;
		}
		sum-=i;
	}
	return flag;
}
int main()
{
	int n,k,p,i;
	max=-1;
	scanf("%d%d%d",&n,&k,&p);
	factor(n,1,k,p,0);
	if(max==-1)
	{
		printf("Impossible\n");
		return 0;
	}
	printf("%d = %d^%d",n,result[0],p);
	for(i=1;i<k;i++)
	{
		printf(" + %d^%d",result[i],p);
	}
	return 0;
}