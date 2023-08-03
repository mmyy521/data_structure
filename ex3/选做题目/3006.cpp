#include<iostream>
using namespace std;
typedef struct BiNode{
	char data;
	struct BiNode *lchild,*rchild;
}BiNode, * BiTree;
void CreateBiTree(BiTree&T)
{
	char ch;
	cin>>ch;
	if(ch=='0')
	T=NULL;
	else 
    {
        T = new BiNode;    
        T->data = ch;                                  	//生成根结点
        CreateBiTree(T->lchild);  //递归创建左子树
        CreateBiTree(T->rchild); //递归创建右子树
    }
}
void THeight(BiTree &T)
{
	BiTree p=T,l[200],s[200];
	int top=0;
	int tag[200];
	int longest=0;
	while(p||top>0)
	{
		while(p)
		{
			s[++top]=p;
			tag[top]=0;
			p=p->lchild;
		}

	if(tag[top]==1)
	{
		if(!s[top]->lchild&&!s[top]->rchild)
		{
			if(top>longest)
			{
				for(int i=1;i<=top;i++)
				l[i]=s[i];
				longest=top;
			}
			
		}
		top--;
	}
	else if(top>0)
	{
		tag[top]=1;
		p=s[top]->rchild;
	}
			
	}
	cout<<longest<<endl;
	for(int i=1;i<=longest;i++)
	{
		cout<<l[i]->data; 
	}
	cout<<endl;
 } 
 int main()
 {
 	BiTree Tree;
    while(1)
    {
        CreateBiTree(Tree);
        if (Tree == NULL)
            return 0;
      	THeight(Tree);
    }
 }
