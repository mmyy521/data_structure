#include<iostream>
using namespace std;
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;
typedef struct VNode//存头结点的结构体数组,起点
{
	int datatop;
	LNode* first;
}VNode,TableL[13];
typedef struct//存头结点+链表的结构体
{
	TableL vertices;//每一条链表
	int n;			//总结点数 
}AlGragh;
void Create(AlGragh &T)
{
	for(int i=0;i<13;i++)
	{
		T.vertices[i].datatop=i; 
		T.vertices[i].first=NULL;
	}
	int e;
	LNode* p=NULL,*q=NULL;
	for(int i=0;i<T.n;i++)//后插法 
	{
		cin>>e;
		int num=e%13;
		p=new LNode;
		p->data=e;
		p->next=NULL;
	if(T.vertices[num].first==NULL)
	T.vertices[num].first=p;
	else
	{
		q=T.vertices[num].first;
		while(q->next)
		q=q->next;
		q->next=p;
	}
}
}
void Insert(AlGragh &T,int e)
{
	int num=e%13;
		LNode *p=new LNode;
		p->data=num;
		p->next=NULL;
		LNode* q;
		q=T.vertices[num].first;
		if(q==NULL)
		{
			q=p;
			return;
		} 
		while(q->next)
		q=q->next;
		q->next=p;
		T.n++;
}
void Print(AlGragh T)
{
	for(int i=0;i<13;i++)
	{
		
		cout<<i;
		LNode* p=T.vertices[i].first;
		while(p)
		{
			cout<<" "<<p->data;
			p=p->next;
		}
		cout<<"__******__"; 
	}
}
int main()
{
	while(1)
	{
		AlGragh T;
		cin>>T.n;
		if(T.n==0)
		return 0;
//		Init(T);
		Create(T);
		int e;
		cin>>e;
		Insert(T,e);
		Print(T);
	}
}
