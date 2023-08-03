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
        cout << T->data;
        PreOrderTraverse(T->rchild);
    }
}
int main()
{
    BiTree Tree1,Tree2;
    while(1)
    {
        CreateBiTree(Tree1);
        if (Tree1 == NULL)
            return 0;
      
        PreOrderTraverse(Tree1);
        cout << endl;
    }
    

}
