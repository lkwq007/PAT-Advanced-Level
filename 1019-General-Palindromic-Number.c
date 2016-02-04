#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,b,flag=1,buf[32],i=0;
	scanf("%d%d",&n,&b);
	do
	{
		buf[i]=n%b;
		n/=b;
		i++;
	}
	while(n>0);
	n=i;
	for(i=0;i<n/2;i++)
	{
		if(buf[i]!=buf[n-i-1])
		{
			flag=0;
			break;
		}
	}
	if(flag)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	for(i=n-1;i>0;i--)
	{
		printf("%d ",buf[i]);
	}
	printf("%d\n",buf[i]);
}