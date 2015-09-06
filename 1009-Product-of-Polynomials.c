#include<stdio.h>
#include<stdlib.h>
double result[2002];
typedef struct
{
	int exponent;
	double coefficient;
} Polynomial;
int main()
{
	int i,j,n1,n2,count,index;
	Polynomial *a,*b;
	double temp,sum;
	scanf("%d",&n1);
	a=(Polynomial *)malloc(n1*sizeof(Polynomial));
	for(i=0;i<n1;i++)
	{
		scanf("%d%lf",&a[i].exponent,&a[i].coefficient);
	}
	scanf("%d",&n2);
	b=(Polynomial *)malloc(n2*sizeof(Polynomial));
	for(i=0;i<n2;i++)
	{
		scanf("%d%lf",&b[i].exponent,&b[i].coefficient);
	}
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			index=a[i].exponent+b[j].exponent;
			temp=a[i].coefficient*b[j].coefficient;
			result[index]+=temp;
		}
	}
	for(i=2001;i>=0;i--)
	{
		if(result[i]!=0)
		{
			count++;
			index=i;
		}
	}
	if(count==0)
		printf("0\n");
/*	else if(count==1)
		printf("1 %d %.1lf\n",index,result[index]);*/
	else
	{
		printf("%d ",count);
		for(i=2001;i>index;i--)
		{
			if(result[i]!=0)
				printf("%d %.1lf ",i,result[i]);
		}
		printf("%d %.1lf",i,result[i]);
	}
	free(a);
	free(b);
}