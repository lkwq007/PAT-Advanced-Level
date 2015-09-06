#include<stdio.h>
#include<math.h>
main()
{
	int c,sum,sum_c,digit,num;
	sum=0;
	while((c=getchar())!='\n')
	{
		sum+=(c-'0');
	}
	sum_c=sum;
	digit=0;
	do
	{
		sum_c/=10;
		digit++;
	}
	while(sum_c);
	while(digit)
	{
		num=sum/pow(10,digit-1);
		if(digit==1)
		{
			switch(num)
			{
				case 1:printf("one");break;
				case 2:printf("two");break;
				case 3:printf("three");break;
				case 4:printf("four");break;
				case 5:printf("five");break;
				case 6:printf("six");break;
				case 7:printf("seven");break;
				case 8:printf("eight");break;
				case 9:printf("nine");break;
				case 0:printf("zero");break;
			}
			break;
		}
		switch(num)
		{
			case 1:printf("one ");break;
			case 2:printf("two ");break;
			case 3:printf("three ");break;
			case 4:printf("four ");break;
			case 5:printf("five ");break;
			case 6:printf("six ");break;
			case 7:printf("seven ");break;
			case 8:printf("eight ");break;
			case 9:printf("nine ");break;
			case 0:printf("zero ");break;
		}
		sum=sum-num*pow(10,digit-1);
		digit--;
	}

}