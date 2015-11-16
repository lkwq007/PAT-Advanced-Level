#include<stdio.h>
int count[128];
int main()
{
	int i;
	char s1[10001],s2[10001];
	gets(s1);
	gets(s2);
	for(i=0;s2[i];i++)
	{
		count[s2[i]]=1;
	}
	for(i=0;s1[i];i++)
	{
		if(!count[s1[i]])
			putchar(s1[i]);
	}
	printf("\n");
}