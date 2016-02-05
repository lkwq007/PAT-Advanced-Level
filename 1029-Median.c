#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *result,*s1,*s2,i1,i2,n1,n2,i,median;
	scanf("%d",&n1);
	s1=(int *)malloc(n1*sizeof(int));
	for(i=0;i<n1;i++)
	{
		scanf("%d",s1+i);
	}
	scanf("%d",&n2);
	s2=(int *)malloc(n2*sizeof(int));
	for(i=0;i<n2;i++)
	{
		scanf("%d",s2+i);
	}
	median=(n1+n2+1)/2;
	result=(int *)malloc(median*sizeof(int));
	i1=0;
	i2=0;
	for(i=0;i<median;i++)
	{
		if(i2>=n2||i1<n1&&s1[i1]<s2[i2])
		{
			result[i]=s1[i1];
			i1++;
		}
		else
		{
			result[i]=s2[i2];
			i2++;
		}
	}
	printf("%d\n",result[i-1]);
}