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
void CoutTree(BiTree T)
{
	BiTree p,s[100];
	int top=0,flag[100];
	p=T;
	while(p||top>0)
	{
		while(p)// 从p指向的节点开始向左遍历入栈 
		{
			s[++top]=p;
			flag[top]=0;
			p=p->lchild;
		}
		if(flag[top]==1)//该节点的右分支已经遍历过了 
		{
			if(s[top]->lchild==NULL&&s[top]->rchild==NULL)
			{
				for(int i=top;i>=1;i--)//输出栈中的结点值 
				{
					cout<<s[i]->data;
				}
				cout<<endl;
			 } 
			 top--;//节点回溯 
		}
		else if(top>0)
		{
			p=s[top]->rchild;//开始遍历右节点 
			flag[top]=1;//标记右节点已经遍历 
		}
	}
}
int main()
{
    BiTree Tree;
    while(1)
    {
        CreateBiTree(Tree);
        if (Tree == NULL)
            return 0;
      	CoutTree(Tree);
    }
    

}
