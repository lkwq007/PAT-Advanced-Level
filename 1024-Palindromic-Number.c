#include<stdio.h>
#include<string.h>
int is_palindromic(char *str)
{	
	int i,n;
	n=strlen(str);
	for(i=0;i<n/2;i++)
	{
		if(str[i]!=str[n-i-1])
		{
			return 0;
		}
	}
	return 1;
}
void reverse(char *str)
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
void add(char *a,char *b)
{
	int carry=0;
	char *p_a;
	p_a=a;
	reverse(a);
	reverse(b);
	while(*a!=0&&*b!=0)
	{
		if(*a-'0'+*b-'0'+carry>9)
		{
			*a+=*b-'0'+carry-10;
			carry=1;
		}
		else
		{
			*a+=*b-'0'+carry;
			carry=0;
		}
		a++;
		b++;
	}
	while(*a!=0)
	{
		if(*a+carry-'0'>9)
		{
			*a+=carry-10;
			carry=1;
		}
		else
		{
			break;
		}
		a++;
	}
	while(*b!=0)
	{
		if(*b+carry-'0'>9)
		{
			*a=*b+carry-10;
			carry=1;
		}
		else
		{
			strcpy(a,b);
			break;
		}
		a++;
	}
	if(carry==1)
	{
		*a='1';
		*(a+1)=0;
	}
	reverse(p_a);
}
int main()
{
	int k,i;
	char number[120],r_number[120];
	memset(number,0,120);
	memset(r_number,0,120);
	scanf("%s%d",number,&k);
	for(i=0;i<k;i++)
	{
		if(is_palindromic(number))
		{
			break;
		}
		strcpy(r_number,number);
		reverse(r_number);
		add(number,r_number);
	}
	printf("%s\n%d\n",number,i);
}