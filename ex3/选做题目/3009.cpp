#include<iostream>
using namespace std;
typedef struct BiNode
{
    char data;
    struct  BiNode* lchild, * rchild; //左右孩子指针
}BiNode, * BiTree;
void CreateBiTree(BiTree& T)
{
    char ch;
    cin >> ch;
    if (ch == '0')//递归结束，建空树
        T = NULL;  
    else 
    {
        T = new BiNode;    
        T->data = ch;                                  	//生成根结点
        CreateBiTree(T->lchild);  //递归创建左子树
        CreateBiTree(T->rchild); //递归创建右子树
    }
}
void PreOrderTraverse(BiTree T)
{
    if (T)
    {
    	cout << T->data;
        PreOrderTraverse(T->lchild);
        
        PreOrderTraverse(T->rchild);
    }
}
int Tree0(BiTree&T)
{
	int num;
	if(T->lchild==NULL&&T->rchild==NULL)
	return 1;
	else if(T->lchild==NULL&&T->rchild!=NULL)
	{
		num=Tree0(T->rchild);
		return num;
	}
	else if(T->rchild==NULL&&T->lchild!=NULL)
	{
		num=Tree0(T->lchild);
		return num;
	}
	else
	{
		num=Tree0(T->lchild)+Tree0(T->rchild);
		return num;
	}
}  
int Tree1(BiTree&T)
{
	int num;
	if(T->lchild==NULL&&T->rchild!=NULL)
	{
		num=Tree1(T->rchild)+1;
		return num;
	}
	else if(T->rchild==NULL&&T->lchild!=NULL)
	{
		num=Tree1(T->lchild)+1;
		return num;
	}
	else if(T->rchild!=NULL&&T->lchild!=NULL)
	{
		num=Tree1(T->lchild)+Tree1(T->rchild);
		return num;
	}
	return 0;
}  
int Tree2(BiTree&T)
{
	int num;
	if(T->lchild!=NULL&&T->rchild!=NULL)
	{
		num=Tree2(T->lchild)+Tree2(T->rchild)+1;
		return num;
	}
	else if(T->lchild!=NULL)
	{
		num=Tree2(T->lchild);
		return num;
	}
	else if(T->rchild!=NULL)
	{
		num=Tree2(T->rchild);
		return num;
	}
	else
	return 0;
}  
int main()
{
    BiTree Tree;
    while(1)
    {
        CreateBiTree(Tree);
        if (Tree == NULL)
            return 0;
      	//PreOrderTraverse(Tree);
       	cout<<Tree0(Tree)<<" ";
		cout<<Tree1(Tree)<<" ";
		cout<<Tree2(Tree)<<endl;
    }
    

}
