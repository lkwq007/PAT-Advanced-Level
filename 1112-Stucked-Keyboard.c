#include<stdio.h>
int flag[128],count;
int main()
{
	char buf[1001],result[50];
	int k,i,temp,count,offset=0;
	scanf("%d",&k);
	getchar();
	gets(buf);
	for(i=0;buf[i];i++)
	{
		temp=i;
		while(buf[temp+1]==buf[temp])
		{
			temp++;
		}
		count=temp-i+1;
		if(count%k!=0)
		{
			flag[buf[i]]=2;
		}
		i=temp;
	}
	for(i=0;buf[i];i++)
	{
		if(flag[buf[i]]==0)
		{
			result[offset++]=buf[i];
			flag[buf[i]]=1;
		}
	}
	result[offset]=0;
	if(offset>0)
	{
		printf("%s\n",result);
	}
	for(i=0;buf[i];i++)
	{
		if(flag[buf[i]]==1)
		{
			i+=k-1;
		}
		putchar(buf[i]);
	}
}