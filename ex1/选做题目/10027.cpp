#include<iostream>//Á´±íÄæÐò´æ´¢ 
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
 }
 void Reverse(LinkList L1,LinkList L2)
 {
 	LinkList p,q;
 	p=L1->next;
 	q=NULL;
 	while(p)
 	{
 		q=p;
 		p=p->next;
 		q->next=L2->next;
 		L2->next=q;
 	}
 }
 void Print(LinkList L)
 {
 	LinkList p;
 	p=L->next;
 	while(p)
 	{
 		cout<<p->data;
 		p=p->next;	
 		if(p)
 		cout<<" ";
	 }
	 cout<<endl;
 } 
 
 int main()
 {
 	LinkList L1,L2;
 	int n; 
 	while(1)
	{
	 
 	cin>>n;
 	if(n==0)
	 return 0; 
	InitList(L1);
	InitList(L2);
	CreateList(L1,n);
	Reverse(L1,L2);
	Print(L2);
}
 }

