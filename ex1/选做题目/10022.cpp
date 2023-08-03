#include<iostream>		//非递减但不需要去重 变成非递增 
using namespace std;
typedef struct LNode
{
	int data;
	struct LNode *next;
 } LNode,*LinkList;
 void InitList(LinkList &L)
 {
 	L=new LNode;
 	L->next=NULL;
 	
 }
 void CreateList(LinkList &L,int n)
 {
 	LinkList p,r;
 	r=L;
 	while(n--)
 	{
	 	p=new LNode;
 		cin>>p->data;
 		p->next=NULL;
 		r->next=p;
 		r=p;
	 }
	 r->next=NULL; 
 }
 
 void Merge(LinkList &L1,LinkList &L2,LinkList &L3)
 {
 	LinkList p,q,r;
	p=L1->next;
	q=L2->next;
	r=NULL;
	while(p&&q)
	{
		if(p->data>=q->data)
		{
			r=q; q=q->next;
			r->next=L3->next;
			L3->next=r;
			 
		}
		else
		{
			r=p;p=p->next;
			r->next=L3->next;
			L3->next=r;
			
		}
	} 
	while(p)
	{
		r=p;
		p=p->next;
		r->next=L3->next;
		L3->next=r;
		
	} 
	while(q)
	{
		r=q;
		q=q->next;
		r->next=L3->next;
		L3->next=r;		
	}
 }
 void Print(LinkList L)
 {
 	LinkList p;
 	p=L->next;
 	while(p)
 	{
 		cout<<p->data<<" ";
 		p=p->next;	
	 }
 } 
 int main()
 {
 	int m,n;
 	cin>>m>>n;
 	while(m!=0&&n!=0)
 	{
 		LinkList L1,L2,L3;
 		InitList(L1);
 		InitList(L2);
 		InitList(L3);
 		CreateList(L1,m);
		CreateList(L2,n); 
		Merge(L1,L2,L3);
	//	Print(L1);
	//	Print(L2);
		Print(L3);	
		cin>>m>>n;	
	}
	return 0;
 }
