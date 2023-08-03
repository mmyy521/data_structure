#include<iostream>//Á´±í·Ö½â 
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;
void InitList(LinkList& L)
{
    L = new LNode;
    L->next = NULL;
}
void CreateList(LinkList L, int n)
{
    LinkList p, r;
    r = L;
    while (n--)
    {
        p = new LNode;
        cin >> p->data;
       p->next = NULL;
        r->next = p;
        r = p;  
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
 void Disassemble(LinkList L1,LinkList L2,LinkList L3)
 {
 	LinkList p,q,r;
 	p=L1->next;
 	q=L2;
 	r=L3;
 	while(p)
 	{
 		if(p->data>0)
 		{
 			q->next=p;
 			q=q->next;
		 }
 		if(p->data<0)
		 {
 			r->next=p;
 			r=r->next;
		 }
 		
 		p=p->next;
	 }
	 q->next=NULL;
	 r->next=NULL;
 	
 }
 int main()
 {
 	LinkList L1,L2,L3;
 	InitList(L1);
 		InitList(L2);
 		InitList(L3);
 	int n;
 	while(1)
 	{
 		cin>>n;
 		if(n==0)
 		return 0;
		CreateList(L1,n);
		Disassemble(L1,L2,L3);
		Print(L2);
		Print(L3);
		 
 		
	 }
 }
