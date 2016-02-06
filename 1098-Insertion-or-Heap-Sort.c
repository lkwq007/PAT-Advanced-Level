#include<stdio.h>
#include<stdlib.h>
int seqcmp(int *a,int *b,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]!=b[i])
		{
			return 1;
		}
	}
	return 0;
}
void print_seq(int *data,int n)
{
	int i;
	if(n<=0)
	{
		return ;
	}
	printf("%d",data[0]);
	for(i=1;i<n;i++)
	{
		printf(" %d",data[i]);
	}
	printf("\n");
}
int insertion(int *data,int times)
{
	int temp;
	temp=data[times];
	while(temp<data[times-1]&&times>=1)
	{
		data[times]=data[times-1];
		times--;
	}
	data[times]=temp;
}
void percolate_down(int *data,int n,int pos)
{
	int child,temp;
	temp=data[pos];
	while(1)
	{
		child=pos*2;
		if(child<n&&data[child]<data[child+1])
		{
			child=child+1;
		}
		if(child<=n&&data[child]>temp)
		{
			data[pos]=data[child];
		}
		else
		{
			break;
		}
		pos=child;
	}
	data[pos]=temp;
}
void build_heap(int *data,int n)
{
	int i;
	for(i=n/2;i>0;i--)
	{
		percolate_down(data,n,i);
	}
}
int heap(int *data,int n,int times)
{
	int temp;
	temp=data[n-times];
	data[n-times]=data[1];
	data[1]=temp;
	percolate_down(data,n-times-1,1);
}
int main()
{
	int *initial_seq,*initial_seq_c,*sorted_seq;
	int n,i;
	scanf("%d",&n);
	initial_seq=(int *)malloc(n*sizeof(int));
	initial_seq_c=(int *)malloc((n+1)*sizeof(int));
	sorted_seq=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",initial_seq+i);
		initial_seq_c[i+1]=initial_seq[i];
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",sorted_seq+i);
	}
	build_heap(initial_seq_c,n);
	for(i=1;i<n;i++)//i=0 不属于插入排序的环节，我一开始偷懒 i=0 ，测试点 2 一直未能通过
	{
		insertion(initial_seq,i);
		if(!seqcmp(initial_seq,sorted_seq,n))
		{
			if(i<n-1)
			insertion(initial_seq,i+1);
			printf("Insertion Sort\n");
			print_seq(initial_seq,n);
			return 0;
		}
	}
	for(i=0;i<n;i++)
	{
		heap(initial_seq_c,n,i);
		if(!seqcmp(initial_seq_c+1,sorted_seq,n))
		{
			if(i<n-1)
			heap(initial_seq_c,n,i+1);
			printf("Heap Sort\n");
			print_seq(initial_seq_c+1,n);
			return 0;
		}
	}
}