#include<iostream>
using namespace std;
typedef struct BiNode
{
    int data;
    struct  BiNode* lchild, * rchild; //×óÓÒº¢×ÓÖ¸Õë
}BSNode, * BSTree;
int n;
void InsertBST(BSTree &T,int e)
{
	if(!T)
	{
		BSTree S=new BSNode;
		S->data=e;
		S->lchild=S->rchild=NULL;
		T=S;
	}
	else if(e<T->data)
	InsertBST(T->lchild,e);
	else if(e>T->data)
	InsertBST(T->rchild,e);
}
void CreatBST(BSTree &T,int n)
{
	T=NULL;
	int e;
	for(int i=0;i<n;i++)
	{
		cin>>e;
		InsertBST(T,e);
	}
}
void CoutT(BSTree T,int m,int S[],int &t)
{
	if (T)
    {
        CoutT(T->lchild,m,S,t);
        if(T->data>=m)
        {
    		S[t++]=T->data;
		}
        CoutT(T->rchild,m,S,t);
    }
}
void CoutS(int S[],int &t)
{
	for(int i=0;i<t-1;i++)
	{
		cout<<S[i]<<" ";
	}
	cout<<S[t-1]<<endl;
 } 
int main()
{
	BSTree T;
	while(1)
	{
		cin>>n;
		if(n==0)
		return 0;
		CreatBST(T,n);
		int m;
		cin>>m;
		int S[100]={0},t=0;
		CoutT(T,m,S,t);
		CoutS(S,t);
	//	cout<<endl;
	}
}
