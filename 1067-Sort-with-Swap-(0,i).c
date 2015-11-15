#include<stdio.h>

int found(int key,int *num,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(num[i]==key)
			return i;
	}
}

void swap0(int *num,int n,int *count)
{
	int temp,index;
	index=found(0,num,n);
	while(index!=0)
	{
		temp=found(index,num,n);
		num[index]=index;
		num[temp]=0;
		index=temp;
		(*count)++;
	}
	return ;
}

int swap0a(int *num,int *map,int *count)
{
	int temp,index;
	index=map[0];
	while(index!=0)
	{
		temp=map[index];
		num[index]=index;
		num[temp]=0;
		map[0]=temp;
		map[index]=index;
		index=temp;
		(*count)++;
	}
}

int main()
{
	int n,i,num[100000],map[100000],count=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",num+i);
		map[num[i]]=i;
	}
	swap0a(num,map,&count);
	for(i=0;i<n;i++)
	{
		if(num[i]!=i)
		{
			num[0]=num[i];
			num[i]=0;
			map[num[0]]=0;
			map[0]=i;
			count++;
			swap0a(num,map,&count);
		}
	}
	printf("%d\n",count);
}