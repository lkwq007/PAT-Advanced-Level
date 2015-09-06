#include<stdio.h>
int main()
{
	double odds,temp,result=1;
	char word[4]="WTL";
	int max[3],i,j;
	for(j=0;j<3;j++)
	{
		odds=0;
		for(i=0;i<3;i++)
		{
			scanf("%lf",&temp);
			if(temp>odds)
			{
				odds=temp;
				max[j]=i;
			}
		}
		result*=odds;
	}
	for(i=0;i<3;i++)
		printf("%c ",word[max[i]]);
	result=(result*0.65-1)*2;
	printf("%.2lf\n",result);
}