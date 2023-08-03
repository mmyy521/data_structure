#include<iostream>			//递增顺序的合并，需要去重 
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
 void CreateList(LinkList L,int n)
 {
 	LinkList p,r;
 	r=L;
 	while(n--)
 	{
	 	p=new LNode;
 		cin>>p->data;
 	
 		r->next=p;
 		r=p;
	 }
	 r->next=NULL; 
 }
 //关键函数 
 void Merge(LinkList L1,LinkList L2,LinkList &L3)
 {
 	LinkList p,q,r;
	p=L1->next;
	L3=L1;
	q=L2->next; 
	r=L3;
	while(p&&q)
	{
		if(q->data==r->data)
			{
				q=q->next;
				continue;
			}
		if(p->data==r->data)
			{
				p=p->next;
				continue;
			}
			
		if(p->data>q->data)
		{	
			r->next=q;
			r=q;
			q=q->next;		
		}
		else if(p->data<q->data)
		{
			r->next=p;
			r=p;
			p=p->next; 
		}
		else
		{
			r->next=q;
			r=q;
			p=p->next;
			q=q->next;
		}	
	} 
	while(p)//需要循环，仍需判断后续有无重复 
	{
		if(r->data==p->data)
		{
			p=p->next;
			continue;
		}	
		r->next=p;
		r=p;
		p=p->next;
	}
	while(q){
		if(r->data==q->data)
		{
			q=q->next;
			continue;
		}
		r->next=q;
		r=q;
		q=q->next;
	} 
//	if(p)
//	r->next=p;
//	if(q)
//	r->next=q;
	r->next=NULL; 
 }
 void Print(LinkList L)
 {
 	LinkList p;
 	p=L->next;
 	while(p)
 	{
 		cout<<p->data;
 		p=p->next;	
 		if(p){
			cout<<" ";
		}
	 }
	cout<<endl;
 }
 int main()
 {
 	int m,n;
 	
 	while(1)
 	{
      cin>>m>>n;
      if(m==0&&n==0)
        return 0;
 		
 		LinkList L1,L2,L3;
 		InitList(L1);
 		InitList(L2);
 		InitList(L3);
 		CreateList(L1,m);
		CreateList(L2,n); 
		Merge(L1,L2,L3);
		Print(L3);	
		
	}
	return 0;
 }
