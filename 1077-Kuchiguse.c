#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*#define ToLow(X) (((X)>='A'&&(X)<='Z')?(X)-'A'+'a':(X))*/
int main()
{
	int i,j,n,suffix=1,flag;
	char **character,temp;
	scanf("%d",&n);
	getchar();
	if(n==1)
	{
		printf("nai\n");
		exit(0);
	}
	character=(char **)malloc(n*sizeof(char *));
	for(i=0;i<n;i++)
	{
		character[i]=(char *)malloc(257*sizeof(char));
		gets(character[i]);
/*		for(j=0;j<strlen(character[i]);j++)
		{
			ToLow(character[i][j]);
		}*/
	}
	while(1)
	{
		flag=0;
		for(i=0;i<n;i++)
		{
			if(suffix>strlen(character[i]))
			{
				goto end;
			}
			if(flag==0)
			{
				flag=1;
				temp=character[i][strlen(character[i])-suffix];
			}
			if(temp!=character[i][strlen(character[i])-suffix])
			{
				goto end;
			}
		}
		suffix++;
	}
end:
/*	while(character[0][strlen(character[0])-suffix]==' ')
	{
		suffix--;
	}*/
	if(suffix==1)
	{
		printf("nai\n");
	}
	else
	{
		suffix--;
		printf("%s\n",character[0]+strlen(character[0])-suffix);
	}
}