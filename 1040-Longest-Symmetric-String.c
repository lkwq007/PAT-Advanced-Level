#include<stdio.h>
#include<string.h>
int main()
{
	char buf[1001];
	int i,j,k,n,count=0,another_count=0,max=1;
	gets(buf);
	n=strlen(buf);
	for(i=0;i<n-1;i++)
	{
		count=1;
		another_count=1;
		if(buf[i]==buf[i+1])
		{
			count=2;
			for(j=i-1,k=i+2;j>=0&&k<n;j--,k++)
			{
				if(buf[j]==buf[k])
				{
					count+=2;
				}
				else
				{
					break;
				}
			}
		}
		if(i+2<n&&buf[i]==buf[i+2])
		{
			another_count=3;
			for(j=i-1,k=i+3;j>=0&&k<n;j--,k++)
			{
				if(buf[j]==buf[k])
				{
					another_count+=2;
				}
				else
				{
					break;
				}
			}
		}
		count=count>another_count?count:another_count;
		if(max<count)
		{
			max=count;
		}
	}
	printf("%d\n",max);
}