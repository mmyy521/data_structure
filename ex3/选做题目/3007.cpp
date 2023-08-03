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
        T->data = ch;                                  	//���ɸ����
        CreateBiTree(T->lchild);  //�ݹ鴴��������
        CreateBiTree(T->rchild); //�ݹ鴴��������
    }
}
void CoutTree(BiTree T)
{
	BiTree p,s[100];
	int top=0,flag[100];
	p=T;
	while(p||top>0)
	{
		while(p)// ��pָ��Ľڵ㿪ʼ���������ջ 
		{
			s[++top]=p;
			flag[top]=0;
			p=p->lchild;
		}
		if(flag[top]==1)//�ýڵ���ҷ�֧�Ѿ��������� 
		{
			if(s[top]->lchild==NULL&&s[top]->rchild==NULL)
			{
				for(int i=top;i>=1;i--)//���ջ�еĽ��ֵ 
				{
					cout<<s[i]->data;
				}
				cout<<endl;
			 } 
			 top--;//�ڵ���� 
		}
		else if(top>0)
		{
			p=s[top]->rchild;//��ʼ�����ҽڵ� 
			flag[top]=1;//����ҽڵ��Ѿ����� 
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
