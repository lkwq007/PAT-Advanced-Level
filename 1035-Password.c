#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct account_
{
	int state;
	char name[11];
	char password[11];
};
typedef struct account_ account;
int main()
{
	account *user;
	int n,i,m=0;
	char *p;
	scanf("%d",&n);
	user=(account *)malloc(n*sizeof(account));
	for(i=0;i<n;i++)
	{
		scanf("%s%s",user[i].name,user[i].password);
		user[i].state=0;
		p=user[i].password;
		while(*p!='\0')
		{
			switch(*p)
			{
				case '1':
				*p='@';
				user[i].state=1;
				break;
				case '0':
				*p='%';
				user[i].state=1;
				break;
				case 'l':
				*p='L';
				user[i].state=1;
				break;
				case 'O':
				*p='o';
				user[i].state=1;
				break;
			}
			p++;
		}
		if(user[i].state==1)
			m++;
	}
	if(m==0)
	{
		if(n==1)
			printf("There is 1 account and no account is modified\n");
		else
			printf("There are %d accounts and no account is modified\n",n);
	}
	else
	{
		printf("%d\n",m);
		for(i=0;i<n;i++)
		{
			if(user[i].state==1)
				printf("%s %s\n",user[i].name,user[i].password);
		}
	}
}