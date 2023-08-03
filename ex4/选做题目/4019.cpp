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
    if (ch == '#')//递归结束，建空树
        T = NULL;  
    else 
    {
        T = new BiNode;    
        T->data = ch;                                  	//生成根结点
        CreateBiTree(T->lchild);  //递归创建左子树
        CreateBiTree(T->rchild); //递归创建右子树
    }
}
int Height(BiTree T)//跟之前求深度一样，也有利用平衡因子的方法吧 
{
	if(!T)
	return 0;
	if(T->lchild==NULL&&T->rchild==NULL)
	return 1;
	else
	return  Height(T->lchild)>Height(T->rchild)?Height(T->lchild)+1:Height(T->rchild)+1;
}
int main()
{
	int n; 
	while(1)
	{
		BiTree T=NULL;
		CreateBiTree(T);
		if(T==NULL)
		return 0;
		cout<<Height(T)<<endl;
		 
	 } 
}
