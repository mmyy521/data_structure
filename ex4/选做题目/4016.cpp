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
int num=0;
void InOrder(BiTree& T,char S[])
{
    if (T)
    {
        InOrder(T->lchild,S);
        S[num++]=T->data;
        InOrder(T->rchild,S);
	}
}
int Judge(BiTree& T)
{
	char S[100];
	InOrder(T,S);
	for(int i=0;i<num-1;i++)
	{
		if(S[i]>S[i+1])
		return 0; 
	}
	return 1;
}
int main()
{
	BiTree Tree1;
    while(1)
    {
        CreateBiTree(Tree1);
        if (Tree1 == NULL)
            return 0;
      
        int yes=Judge(Tree1);
        if(yes==1)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
}
