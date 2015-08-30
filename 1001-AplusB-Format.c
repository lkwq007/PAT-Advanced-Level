#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,i,j,flag=0;
	char num[20]="",*pnum=num;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		c=a+b;
		sprintf(num,"%d\0",c);
		pnum=num+strlen(num)-1;
		if(num[0]=='-')
			flag=1;
		while(pnum>num+flag)
		{
			pnum-=2;
			if(pnum>num+flag)
			{
				for(i=strlen(pnum);i>0;i--)
				{
					*(pnum+i)=*(pnum+i-1);
				}
				*pnum=',';
				pnum--;
			}
		}
		printf("%s\n",num);
	}
}