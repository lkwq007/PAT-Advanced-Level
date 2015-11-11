#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char string[81];
	int max=0,i,j,n,temp;
	gets(string);
	n=strlen(string);
	for(i=n%2?3:4;i<=n;i+=2)
	{
		temp=(n-i)/2;
		if(max<temp+1&&temp+1<=i)
		{
			max=temp+1;
		}
	}
	for(i=0;i<max-1;i++)
	{
		printf("%c%*c\n",string[i],n-2*max+1,string[n-i-1]);
	}
	for(i=0;i<n-2*max+2;i++)
	{
		printf("%c",string[max+i-1]);
	}
}