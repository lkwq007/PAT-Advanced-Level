#include<stdio.h>
#include<string.h>
void reserve(char *str)
{
	int i,n;
	char temp;
	n=strlen(str);
	for(i=0;i<n/2;i++)
	{
		temp=str[i];
		str[i]=str[n-i-1];
		str[n-i-1]=temp;
	}
	return ;
}
int main()
{
	char num[22],result[22],*p;
	int carry=0,temp,i;
	gets(num);
	strcpy(result,num);
	reserve(result);
	for(i=0;i<strlen(result);i++)
	{
		temp=result[i]-'0';
		temp*=2;
		temp+=carry;
		carry=temp/10;
		result[i]=temp%10+'0';
	}
	if(carry>0)
	{
		result[i]=carry+'0';
		result[i+1]='\0';
		reserve(result);
		printf("No\n%s\n",result);
		return 0;
	}
	reserve(result);
	for(i=0;i<strlen(result);i++)
	{
		if((p=strchr(num,result[i]))!=NULL)
		{
			*p=1;
		}
		else
		{
			printf("No\n%s\n",result);
			return 0;
		}
	}
	printf("Yes\n%s\n", result);
}