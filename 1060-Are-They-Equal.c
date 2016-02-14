#include<stdio.h>
#include<string.h>
int handle(char *str,int n)
{
	int first=-1,i,count,total;
	char *point,temp[105];
	point=strchr(str,'.');
	total=strlen(str);
	if(point==NULL)
	{
		point=str+total;
	}
	for(i=0;str[i];i++)
	{
		if(str[i]!='.'&&str[i]!='0')
		{
			first=i;
			break;
		}
	}
	if(first==-1)
	{
		str[0]='0';
		str[1]='.';
		for(i=0;i<n;i++)
		{
			str[i+2]='0';
		}
		str[i+2]=0;
		return 0;//坑死人的 PAT，最后一个测试点有点不科学，当数字为 0 时，只按照那个 standard form 为什么指数不能是 1 ？
	}
	else
	{
		count=point-str-first;
		temp[0]='0';
		temp[1]='.';
		for(i=0;i<n;i++)
		{
			if(i+first>=total)
			{
				temp[i+2]='0';
			}
			else if(str[i+first]=='.')
			{
				i--;
				first++;
			}
			else
			{
				temp[i+2]=str[i+first];
			}
		}
		temp[i+2]=0;
	}
	strcpy(str,temp);
	if(count<0)
	{
		count++;
	}
	return count;
}
int main()
{
	char a[105],b[105];
	int n,power_a,power_b;
	scanf("%d%s%s",&n,a,b);
	power_a=handle(a,n);
	power_b=handle(b,n);
	if(power_a==power_b&&!strcmp(a,b))
	{
		printf("YES %s*10^%d\n",a,power_a);
	}
	else
	{
		printf("NO %s*10^%d %s*10^%d\n",a,power_a,b,power_b);
	}
}