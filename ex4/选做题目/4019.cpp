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
int Height(BiTree T)//��֮ǰ�����һ����Ҳ������ƽ�����ӵķ����� 
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
