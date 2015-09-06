#include<stdio.h>
int main()
{
	int i,total=0,current=0,n,request[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",request+i);
		total+=(request[i]-current)*((request[i]-current)>0?6:-4)+5;
		current=request[i];
	}
	printf("%d\n",total);
}