#include<stdio.h>
#include<stdlib.h>
//一个偷懒的解法
//后序遍历的顺序是 左子树->右子树->节点
//中序遍历的顺序是 左子树->节点->右子树
//那么对于任意一个节点，它的后序遍历的序列的最后一个元素就是它本身，然后可以根据中序遍历的序列确定它左孩子
//和右孩子节点的遍历序列，以此类推。
//然后我又懒得用 Tree ，于是记录了各个节点的深度信息，依据深度的排序将中序遍历转为层序遍历（用后序的也可以）
//同理，前序遍历的顺序是 节点->左子树->右子树
//因而能通过前序、中序、后序中任意两种中顺序还原一颗二叉树
void convert(int *post_order,int *in_order,int *result,int n,int count)
{
	int self,left,right;
	if(n<=0)
	{
		return ;
	}
	self=post_order[n-1];
	for(left=0;left<n;left++)
	{
		if(in_order[left]==self)
		{
			break;
		}
	}
	result[left]=count;
	count++;
	convert(post_order,in_order,result,left,count);
	right=n-left-1;
	convert(post_order+left,in_order+left+1,result+left+1,right,count);
}
int main()
{
	int *post,*in,*result,temp,key,n,i,j;
	scanf("%d",&n);
	post=(int *)malloc(n*sizeof(int));
	in=(int *)malloc(n*sizeof(int));
	result=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",post+i);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",in+i);
	}
	convert(post,in,result,n,0);
	for(i=1;i<n;i++)
	{
		temp=result[i];
		key=in[i];
		j=i;
		while(j>0)
		{
			if(temp<result[j-1])
			{
				result[j]=result[j-1];
				in[j]=in[j-1];
				j--;
			}
			else
			{
				break;
			}
		}
		result[j]=temp;
		in[j]=key;
	}
	for(i=0;i<n-1;i++)
	{
		printf("%d ",in[i]);
	}
	printf("%d\n",in[i]);
}