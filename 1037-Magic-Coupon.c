#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
	return *(int *)b-*(int *)a;
}
int main()
{
	int nc,np,i,j,*coupon,*product,temp,total=0;
	scanf("%d",&nc);
	coupon=(int *)malloc(nc*sizeof(int));
	for(i=0;i<nc;i++)
	{
		scanf("%d",coupon+i);
	}
	scanf("%d",&np);
	product=(int *)malloc(np*sizeof(int));
	for(i=0;i<np;i++)
	{
		scanf("%d",product+i);
	}
	qsort(coupon,nc,sizeof(int),compare);
	qsort(product,np,sizeof(int),compare);
	for(i=0,j=0;i<nc&&j<np;i++,j++)
	{
		temp=coupon[i]*product[j];
		if(temp<=0)
		{
			break;
		}
		coupon[i]=0;
		product[j]=0;
		total+=temp;
	}
	for(i=nc-1,j=np-1;i>=0,j>=0;i--,j--)
	{
		temp=coupon[i]*product[j];
		if(temp<=0)
		{
			break;
		}
		coupon[i]=0;
		coupon[j]=0;
		total+=temp;
	}
	printf("%d\n",total);
}