#include<stdio.h>
#include<string.h>
int main()
{
	char card[54][4],pattern[5]="SHCD";
	int i,j,total=0,k,shuffling[55],temp[55],result[55];
	for(i=0;i<4;i++)
	{
		for(j=1;j<=13;j++)
		{
			sprintf(card[total],"%c%d\0",pattern[i],j);
			total++;
		}
	}
	strcpy(card[total++],"J1");
	strcpy(card[total++],"J2");
	scanf("%d",&k);
	for(i=1;i<=54;i++)
	{
		scanf("%d",shuffling+i);
		result[i]=i;
	}
	for(i=0;i<k;i++)
	{
		for(j=1;j<=54;j++)
		{
			temp[shuffling[j]]=result[j];
		}
		for(j=1;j<=54;j++)
		{
			result[j]=temp[j];
		}
	}
	for(i=1;i<54;i++)
	{
		printf("%s ",card[result[i]-1]);
	}
	printf("%s\n",card[result[i]-1]);
}