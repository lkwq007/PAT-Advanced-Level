#include<stdio.h>
#include<string.h>
int main()
{
	char digit[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"},
	base[5][6]={" Qian"," Ge"," Shi"," Bai"},special[3][5]={""," Wan"," Yi"},buf[11];
	int flag=0,i,n,current,zero,zero_pos;
	gets(buf);
	n=strlen(buf);
	i=0;
	if(buf[0]=='-')
	{
		printf("Fu");
		flag=1;
		i=1;
	}
	if(n==1)
	{
		printf("%s\n",digit[buf[i]-'0']);
		return 0;
	}
	while(i<n)
	{
		if(buf[i]!='0')
		{
			if(flag)
			{
				printf(" ");
			}
			else
			{
				flag=1;
			}
			current=(n-i-1)/4;
			if(zero==1&&zero_pos==current)
			{
				printf("%s ",digit[0]);
				zero=0;
			}
			printf("%s",digit[buf[i]-'0']);
			if((n-i)%4!=1)
			{
				printf("%s",base[(n-i)%4]);
			}
		}
		else
		{
			zero_pos=(n-i-1)/4;
			zero=1;
		}
		if((n-i)%4==1&&(n-i-1)/4==current)
		{
			printf("%s",special[(n-i)/4]);
		}
		i++;
	}
	printf("\n");
}