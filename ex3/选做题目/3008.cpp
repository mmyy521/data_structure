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

int PreOrderTraverse(BiTree T1,BiTree T2) {
    if (T1 == NULL && T2 == NULL) return 0;
    else if (T1->data != T2->data)
        return 1;
    else {
        int num = PreOrderTraverse(T1->lchild, T2->lchild) + PreOrderTraverse(T1->rchild, T2->rchild);
        return num;//关键语句 
        
    }
}
void Change(BiTree &lch,BiTree &rch)
{
    if (lch == NULL && rch == NULL)
        return;
    else if (lch == NULL || rch == NULL)
    {
        BiTree p;
        p = lch;
        lch = rch;
        rch = p;
        return;
    }
    else
    {
        BiTree p;
        p = lch;
        lch = rch;
        rch = p;
        Change(lch->lchild, lch->rchild);
        Change(rch->lchild, rch->rchild);
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
void InOrder(BiTree T)
{
    if (T)
    {
        
       InOrder(T->lchild);
        cout << T->data;
        InOrder(T->rchild);
    }
}
void LastOrder(BiTree T)
{
    if (T)
    {

        LastOrder(T->lchild);
        LastOrder(T->rchild);
        cout << T->data;
    }
}
int GetMax(BiTree T)//采用一个指针队列存每一叶节点到根节点
{
    int max = 0;
    int temp = 0;
    int front = 1, rear = 1;
    BiTree G[100];
    G[rear] = T;
    
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
        InOrder(Tree1);
        cout << endl;
        LastOrder(Tree1);
        cout << endl;
    }
    

}
