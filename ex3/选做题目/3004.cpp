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
    if (ch == '0')//�ݹ������������
        T = NULL;  
    else 
    {
        T = new BiNode;    
        T->data = ch;                                  	//���ɸ����
        CreateBiTree(T->lchild);  //�ݹ鴴��������
        CreateBiTree(T->rchild); //�ݹ鴴��������
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
