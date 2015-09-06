#include<stdio.h>
int main()
{
	char num[102],word[10][6]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	int sum,i;
	scanf("%s",num);
	for(i=0;num[i];i++)
	{
		sum+=(num[i]-'0');
	}
	sprintf(num,"%d\0",sum);
	printf("%s",word[num[0]-'0']);
	for(i=1;num[i];i++)
		printf(" %s", word[num[i]-'0']);
}