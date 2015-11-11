#include<stdio.h>
#include<string.h>
int main()
{
	int rgb[3],i,temp;
	char color[8]="#000000",*p_color=color;
	for(i=0;i<3;i++)
	{
		scanf("%d",&rgb[i]);
	}
	for(i=0;i<3;i++)
	{
		p_color=color+(i+1)*2;
		do
		{
			temp=rgb[i]%13;
			*(p_color--)=temp>9?temp-10+'A':temp+'0';
			rgb[i]/=13;
		}
		while(rgb[i]>0);
	}
	printf("%s\n",color);
}