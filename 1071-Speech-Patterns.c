#include<stdio.h>
#include<stdlib.h>
typedef struct tree_
{
	char *word;
	int count;
	struct tree_ *left;
	struct tree_ *right;
} tree;
tree *update(tree *root,char *word,tree **max)
{
	int temp;
	if(root==NULL)
	{
		root=(tree *)malloc(sizeof(tree));
		root->word=word;
		root->count=1;
		root->left=NULL;
		root->right=NULL;
		if(*max==NULL||(*max)->count<root->count)
		{
			*max=root;
		}
		return root;
	}
	temp=strcmp(word,root->word);
	if(temp<0)
	{
		root->left=update(root->left,word,max);
	}
	else if(temp>0)
	{
		root->right=update(root->right,word,max);
	}
	else
	{
		root->count++;
	}
	if(*max==NULL||(*max)->count<root->count)
	{
		*max=root;
	}
	return root;
}
int main()
{
	char buf[1048580],*p_buf=buf,*first_letter=NULL;
	tree *root=NULL,*max;
	gets(buf);
	while(*p_buf)
	{
		if(*p_buf>='0'&&*p_buf<='9'||*p_buf>='a'&&*p_buf<='z'||*p_buf>='A'&&*p_buf<='Z')
		{
			if(first_letter==NULL)
			{
				first_letter=p_buf;
			}
			if(*p_buf>='A'&&*p_buf<='Z')
			{
				*p_buf+='a'-'A';
			}
		}
		else if(first_letter!=NULL)
		{
			*p_buf=0;
			root=update(root,first_letter,&max);
			first_letter=NULL;
		}
		p_buf++;
	}
	if(first_letter!=NULL)
	{
		update(root,first_letter,&max);
	}
	printf("%s %d\n",max->word,max->count);
}