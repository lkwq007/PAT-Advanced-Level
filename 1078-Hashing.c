#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>
int is_prime(int n)
{
	int i,end;
	//end=sqrt((double)n);
	if(n<2)
	{
		return 0;
	}
	for(i=2;i<=n/2;i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
int get_prime(int n)
{
	int i;
	i=n+1;
	//i=n%2?n+2:n+1;之前竟然坑在这个表达式上了……
	while(!is_prime(i))
	{
		i+=1;//还有这个，之前是i+=2;
	}
	return i;
}
int main()
{
	int m,n,i,*table,temp,offset,pos,flag=0,can_insert;
	scanf("%d%d",&m,&n);
	if(!is_prime(m))
	{
		m=get_prime(m);
	}
	table=(int *)malloc(m*sizeof(int));
	//memset(table,0xFF,m*sizeof(int));
	for(i=0;i<m;i++)
	{
		table[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		pos=temp%m;
		offset=0;
		can_insert=1;
		while(table[pos]!=-1)
		{
			if(offset==m)
			{
				can_insert=0;
				break;
			}
			pos=(pos+2*offset+1)%m;
			offset++;
		}
		if(flag==0)
		{
			printf("%d",pos);
			table[pos]=temp;
			flag=1;
		}
		else
		{
			if(can_insert)
			{
				printf(" %d",pos);
				table[pos]=temp;
			}
			else
			{
				printf(" -");
			}
		}
	}
}