#include<iostream>
using namespace std;
typedef struct BiNode
{
    char data;
    struct  BiNode* lchild, * rchild; //���Һ���ָ��
}BiNode, * BiTree;
void CreateBiTree(BiTree& T)
{
    char ch;
    cin >> ch;
    if (ch == '#')//�ݹ������������
        T = NULL;  
    else 
    {
        T = new BiNode;    
        T->data = ch;                                  	//���ɸ����
        CreateBiTree(T->lchild);  //�ݹ鴴��������
        CreateBiTree(T->rchild); //�ݹ鴴��������
    }
}

int PreOrderTraverse(BiTree T1,BiTree T2) {
    if (T1 == NULL && T2 == NULL) return 0;
    else if (T1->data != T2->data)
        return 1;
    else {
        int num = PreOrderTraverse(T1->lchild, T2->lchild) + PreOrderTraverse(T1->rchild, T2->rchild);
        return num;//�ؼ���� 
        
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
int main()
{
    BiTree Tree1,Tree2;
    while(1)
    {
        CreateBiTree(Tree1);
        if (Tree1 == NULL)
            return 0;
        //Change(Tree1->lchild, Tree1->rchild);
        PreOrderTraverse(Tree1);
        cout << endl;
    }
    

}
