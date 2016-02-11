#include<stdio.h>
#include<string.h>
int power(int n)
{
	int i,result=1;
	for(i=0;i<n;i++)
	{
		result*=10;
	}
	return result;
}
int main()
{
	char buf[21],digit;
	int i,j,n,temp,total=0,pre,post;
	buf[0]='0';
	gets(buf+1);
	n=strlen(buf);
	for(i=1;i<n;i++)
	{
		if(buf[i]=='1')
		{
			if(i!=n-1)
			{
				sscanf(buf+i+1,"%d",&post);
				post++;
				total+=post;
			}
			else
			{
				total+=1;
			}
			buf[i]=0;
			sscanf(buf,"%d",&pre);
			pre;
			buf[i]='1';
			post=power(n-i-1);
			total+=pre*post;
		}
		else if(buf[i]>'1')
		{
			digit=buf[i];
			buf[i]=0;
			sscanf(buf,"%d",&pre);
			buf[i]=digit;
			pre++;
			post=power(n-i-1);
			total+=pre*post;
		}
		else
		{
			buf[i]=0;
			sscanf(buf,"%d",&pre);
			buf[i]='0';
			post=power(n-i-1);
			total+=pre*post;
		}
	}
	printf("%d\n",total);
}