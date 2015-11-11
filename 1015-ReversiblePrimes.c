#include<stdio.h>
#include<string.h>
#include<math.h>
int is_prime(int n)
{
	int i;
	if(n==1||n==0)
		return 0;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;
}

int main()
{
	int n,d,temp,i;
	char reversed[100],*p_reversed;
	while(scanf("%d",&n),n>=0)
	{
		p_reversed=reversed;
		scanf("%d",&d);
		if(!is_prime(n))
		{
			printf("No\n");
		}
		else
		{
			temp=n;
			do
			{
				*(p_reversed++)=temp%d+'0';
				temp/=d;
			}
			while(temp>0);
			temp=0;
			*p_reversed='\0';
			for(i=0;i<strlen(reversed);i++)
			{
				temp+=(reversed[i]-'0')*pow(d,strlen(reversed)-i-1);
			}
			if(is_prime(temp))
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
		}
	}
}