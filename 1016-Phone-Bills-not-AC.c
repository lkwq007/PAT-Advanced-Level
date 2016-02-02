#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ONLINE 1
#define OFFLINE 0
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
	clog *customer,*current,sentry;
	char buf[9];
	int n,i,flag=0,total,charge,lasting;
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
	sentry.name[0]=1;
	sentry.name[1]=0;
	sentry.month=-1;
	sentry.state=OFFLINE;
	current=&sentry;
	for(i=0;i<n;i++)
	{
		if(strcmp(current->name,customer[i].name)||current->month!=customer[i].month)
		{
			if(flag==1)
			{
				printf("Total amount: $%d.%02d\n",total/100,total%100);
			}
			current=customer+i;
			flag=0;
			total=0;
		}
		else if(customer[i].state==ONLINE)
		{
			current=customer+i;
		}
		else if(current->state==ONLINE&&customer[i].state==OFFLINE)
		{
			if(flag==0)
			{
				printf("%s %02d\n",current->name,customer[i].month);
				flag=1;
			}
			charge=calculate(customer+i,current);
			lasting=sub(customer+i,current);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%d.%02d\n",
				current->day,current->hour,current->minute,
				customer[i].day,customer[i].hour,customer[i].minute,
				lasting,charge/100,charge%100);
			total+=charge;
		}
	}
	if(flag==1)
	{
		printf("Total amount: $%d.%02d\n",total/100,total%100);
	}
}