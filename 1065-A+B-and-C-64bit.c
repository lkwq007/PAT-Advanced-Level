#include<stdio.h>
#include<string.h>
typedef struct integer_
{
	int sign;
	char digit[22];
} integer;
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
void add(integer *a,integer *b)
{
	char *pa=a->digit,*pb=b->digit;
	int carry=0;
	reverse(a->digit);
	reverse(b->digit);
	while(*pa&&*pb)
	{
		if(*pa+*pb+carry-'0'>'9')
		{
			*pa+=*pb+carry-10-'0';
			carry=1;
		}
		else
		{
			*pa+=*pb+carry-'0';
			carry=0;
		}
		pa++;
		pb++;
	}
	if(*pb)
	{
		strcpy(pa,pb);
	}
	while(*pa)
	{
		if(*pa+carry>'9')
		{
			*pa+=carry-10;
			carry=1;
		}
		else
		{
			*pa+=carry;
			carry=0;
			break;
		}
		pa++;
	}
	if(carry)
	{
		*(pa++)='1';
		*pa=0;
	}
	reverse(a->digit);
	return ;
}
void sub(integer *a,integer *b)
{
	char *pa,*pb,*temp;
	int carry=0,l_a,l_b,flag=0;
	l_a=strlen(a->digit);
	l_b=strlen(b->digit);
	pa=a->digit;
	pb=b->digit;
	if(l_a==l_b&&strcmp(a->digit,b->digit)<0||l_a<l_b)
	{
		pa=b->digit;
		pb=a->digit;
		flag=1;
	}
	if(flag)
	{
		a->sign=b->sign;
	}
	reverse(a->digit);
	reverse(b->digit);
	while(*pa&&*pb)
	{
		if(*pa-*pb+carry<0)
		{
			*pa+=-*pb+carry+10+'0';
			carry=-1;
		}
		else
		{
			*pa+=-*pb+carry+'0';
			carry=0;
		}
		pa++;
		pb++;
	}
	if(*pb)
	{
		strcpy(pa,pb);
	}
	while(*pa)
	{
		if(*pa+carry<'0')
		{
			*pa+=carry+10;
			carry=-1;
		}
		else
		{
			*pa+=carry;
			carry=0;
		}
		pa++;
	}
	pa--;
	while(*pa=='0')
	{
		*pa=0;
		pa--;
	}
	if(flag)
	{
		strcpy(a->digit,b->digit);
	}
	reverse(a->digit);
	return ;
}
int compare(integer *a,integer *b)
{
	int l_a,l_b;
	if(a->sign>b->sign)
	{
		return 1;
	}
	l_a=strlen(a->digit);
	l_b=strlen(b->digit);
	if(a->sign+b->sign>0)
	{
		if(l_a==l_b)
		{
			return strcmp(a->digit,b->digit);
		}
		return l_a-l_b;
	}
	if(l_a==l_b)
	{
		return -strcmp(a->digit,b->digit);
	}
	return l_b-l_a;
}
int main()
{
	int i,j,n;
	char buf[3][21];
	integer number[3];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%s",buf[j]);
			if(buf[j][0]=='-')
			{
				number[j].sign=-1;
				strcpy(number[j].digit,buf[j]+1);
			}
			else
			{
				number[j].sign=1;
				strcpy(number[j].digit,buf[j]);
			}
		}
		if(number[0].sign+number[1].sign==0)
		{
			sub(number,number+1);
		}
		else
		{
			add(number,number+1);
		}
		if(compare(number,number+2)>0)
		{
			printf("Case #%d: true\n",i+1);
		}
		else
		{
			printf("Case #%d: false\n",i+1);
		}
	}
}