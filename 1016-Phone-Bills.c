#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ONLINE 1
#define OFFLINE 0
#define UNAVAILABLE -1
int toll[24];
typedef struct clog_
{
	char name[21];
	int month;
	int day;
	int hour;
	int minute;
	int state;
} clog;
int compare(const void *a,const void *b)
{
	int value;
	value=strcmp(((clog *)a)->name,((clog *)b)->name);
	return value?value:
	(
		((clog *)a)->month-((clog *)b)->month?((clog *)a)->month-((clog *)b)->month:
		(
			((clog *)a)->day-((clog *)b)->day?((clog *)a)->day-((clog *)b)->day:
			(
				((clog *)a)->hour-((clog *)b)->hour?((clog *)a)->hour-((clog *)b)->hour:
				(
					((clog *)a)->minute-((clog *)b)->minute
				)
			)
		)
	);
}
int compare_last(const void *a,const void *b)
{
	int value;
	if(((clog *)a)->state==UNAVAILABLE)
	{
		return 1;
	}
	value=strcmp(((clog *)a)->name,((clog *)b)->name);
	return value?value:
	(
		((clog *)a)->month-((clog *)b)->month?((clog *)a)->month-((clog *)b)->month:
		(
			((clog *)a)->day-((clog *)b)->day?((clog *)a)->day-((clog *)b)->day:
			(
				((clog *)a)->hour-((clog *)b)->hour?((clog *)a)->hour-((clog *)b)->hour:
				(
					((clog *)a)->minute-((clog *)b)->minute
				)
			)
		)
	);
}
int check(clog *t)
{
	int sum,i;
	sum=0;
	for(i=0;i<t->hour;i++)
	{
		sum+=toll[i]*60;
	}
	sum+=toll[i]*t->minute;
	return sum;
}
int calculate(clog *end,clog *start)
{
	int extra,i;
	extra=0;
	if(end->day-start->day>0)
	{
		for(i=0;i<24;i++)
		{
			extra+=toll[i]*60;
		}
		extra*=(end->day-start->day);
	}
	return check(end)-check(start)+extra;
}
int sub(clog *end,clog *start)
{
	int end_m,start_m;
	end_m=end->day*24*60+end->hour*60+end->minute;
	start_m=start->day*24*60+start->hour*60+start->minute;
	return end_m-start_m;
}
int main()
{
	clog *customer;
	char buf[9];
	int n,i,flag=0,total,charge,lasting,last=-1;
	for(i=0;i<24;i++)
	{
		scanf("%d",toll+i);
	}
	scanf("%d",&n);
	customer=(clog *)malloc(n*sizeof(clog));
	for(i=0;i<n;i++)
	{
		scanf("%s%d:%d:%d:%d%s",customer[i].name,&(customer[i].month),&(customer[i].day),
			&(customer[i].hour),&(customer[i].minute),buf);
		if(buf[1]=='n')
		{
			customer[i].state=ONLINE;
		}
		else
		{
			customer[i].state=OFFLINE;
		}
	}
	qsort(customer,n,sizeof(clog),compare);
	for(i=0;i<n;i++)
	{
		if(customer[i].state==ONLINE&&i<n-1&&!strcmp(customer[i].name,customer[i+1].name)&&customer[i+1].state==OFFLINE)
		{
			i+=1;
		}
		else
		{
			customer[i].state=UNAVAILABLE;
		}
	}
	for(i=0;i<n;i++)
	{
		if(customer[i].state!=UNAVAILABLE)
		{
			if(last==-1||strcmp(customer[last].name,customer[i].name))
			{
				if(last!=-1)
				{
					printf("Total amount: $%d.%02d\n",total/100,total%100);
				}
				printf("%s %02d\n",customer[i].name,customer[i].month);
				total=0;
			}
			if(customer[i].state==ONLINE)
			{
				charge=calculate(customer+i+1,customer+i);
				lasting=sub(customer+i+1,customer+i);
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%d.%02d\n",
				customer[i].day,customer[i].hour,customer[i].minute,
				customer[i+1].day,customer[i+1].hour,customer[i+1].minute,
				lasting,charge/100,charge%100);
				i+=1;
				last=i;
				total+=charge;
			}
		}
	}
	if(last!=-1)
	{
		printf("Total amount: $%d.%02d\n",total/100,total%100);
	}
}