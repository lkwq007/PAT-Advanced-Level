#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef struct hashtable_
{
	int number;
	int count;
} hashtable;
int main()
{
	int m,n,temp,i,j,count,total,size,pos,offset,max;
	hashtable *table;
	scanf("%d%d",&m,&n);
	total=m*n;
	if(total%2==0)
	{
		size=total+1;
	}
	else
	{
		size=total;
	}
	table=(hashtable *)malloc(size*sizeof(hashtable));
	memset(table,0xFF,size*sizeof(hashtable));
	for(i=0;i<total;i++)
	{
		scanf("%d",&temp);
		pos=temp%size;
		offset=0;
		while(table[pos].number!=-1&&table[pos].number!=temp)
		{
			pos+=(offset<<1)+1;
		}
		table[pos].number=temp;
		table[pos].count++;
		if(table[pos].count+1>total/2)
		{
			break;
		}
	}
	printf("%d\n",table[pos].number);
}