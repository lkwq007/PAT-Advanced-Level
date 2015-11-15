#include<stdio.h>
struct number_
{
	int no;
	int count;
};
typedef struct number_ number;
number num[10001];
int main()
{
	int n,i,temp,min=0;
	scanf("%d",&n);
	for(i=0;i<10001;i++)
	{
		num[i].no=-1;
		num[i].count=0;
	}
	num[0].no=100005;
	num[0].count=-1;
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		num[temp].count++;
		if(num[temp].no==-1)
			num[temp].no=i;
	}
	for(i=1;i<10001;i++)
	{
		if(num[i].count==1)
		{
			if(num[min].no>num[i].no)
				min=i;
		}
	}
	if(min>0&&min<10001)
		printf("%d\n",min);
	else
		printf("None\n");
}