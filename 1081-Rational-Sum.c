#include<stdio.h>
typedef struct rational_
{
	int numerator;
	int denominator;
} rational;
void simplify(rational *a)
{
	int i,sign=1;
	if(a->numerator<0)
	{
		sign=-1;
		a->numerator=-a->numerator;
	}
	for(i=2;i<=a->numerator;i++)
	{
		if(a->numerator%i==0&&a->denominator%i==0)
		{
			a->numerator/=i;
			a->denominator/=i;
			i=2;
		}
	}
	a->numerator*=sign;
}
void add(rational *a,rational *b)
{
	a->numerator*=b->denominator;
	b->numerator*=a->denominator;
	a->numerator+=b->numerator;
	a->denominator*=b->denominator;
	simplify(a);
}
void print(rational *a)
{
	if(a->denominator==1||a->numerator==0)
	{
		printf("%d\n",a->numerator);
	}
	else if(a->numerator>a->denominator||-a->numerator>a->denominator)
	{
		printf("%d ",a->numerator/a->denominator);
		a->numerator%=a->denominator;
		simplify(a);
		printf("%d/%d\n",a->numerator,a->denominator);
	}
	else
	{
		printf("%d/%d\n",a->numerator,a->denominator);
	}
}
int main()
{
	int i,n;
	rational temp,sum;
	sum.numerator=0;
	sum.denominator=1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d/%d",&(temp.numerator),&(temp.denominator));
		simplify(&temp);
		add(&sum,&temp);
	}
	print(&sum);
}