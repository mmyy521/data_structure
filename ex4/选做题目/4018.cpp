#include<iostream>
using namespace std;
typedef struct BiNode
{
	int data;
	int count;
	struct BiNode *llink,*rlink;
}BiNode,*BiTNode;
	int N=0;
void Insert(BiTNode &T,int e,int &num)
{
	BiTNode S;
	S=new BiNode;
		S->data=e;
		S->count=0;
		S->llink=S->rlink=NULL;
	if(!T)
	{
		T=S;
		return;	
	}
	BiTNode p=T,q;
	while(p)
	{
		if(p->data==e)//找到相等的 
		{
			p->count++;
			return;
		}
		q=p;//没找到，用q保留双亲
		if(p->data>e)
		p=p->llink;
		else
		p=p->rlink; 
	}
	//最终也没找到相等的就把这个节点加进去
	if(q->data>e)
	{
		 q->llink=S;
		 num++;
	}
	 else
	 {
	 	q->rlink=S;
	 	num++;
	 }	 
}
void CoutT(BiTNode T,int num,int& N)
{
	if(T!=NULL)
	{
		CoutT(T->llink,num,N);
		N++;
		if(N<=num)
		cout<<T->data<<" ";
		else
		cout<<T->data<<endl;
		CoutT(T->rlink,num,N);
	}
	
}
void CoutC(BiTNode T,int num,int& N)
{
	if(T!=NULL)
	{
		CoutC(T->llink,num,N);
		N++;
		if(N<=num)
		cout<<T->count<<" ";
		else
		cout<<T->count<<endl;
		CoutC(T->rlink,num,N);
	}
}
int main()
{
	
	while(1)
	{
		BiTNode T=NULL;
		int n=0;
		cin>>n;
		if(n==0)
		return 0;
		int e;
		int num=0;
		for(int i=0;i<n;i++)
		{
			cin>>e;
			Insert(T,e,num);
		}
		int key;
		cin>>key;
		Insert(T,key,num);
		int N1=0;
		CoutT(T,num,N1);
		int N2=0;
		CoutC(T,num,N2);
	}
 } 
