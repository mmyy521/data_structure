#include<iostream>//奇偶链表的分割 
using namespace std;
#define OK 1
#define ERROR 0
 typedef struct LNode
 {
 	int data;
 	struct LNode *next;
 }LNode,*LinkList;
 int InitList(LinkList &L)
 {
 	L=new LNode;
 	L->next=NULL;
 	return OK;
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
 void Segmentation(LinkList L,LinkList L1,LinkList L2)
 {
 	LinkList p,q,r,h;
 	p=L->next;
 	q=L1;
 	r=L2;
 	int i=0;
 	while(p)
 	{
 		i++;
 		if(i%2!=0)//奇数就接到L2 
 		{
 			q->next=p;
 			q=p;
 			p=p->next;
		}
		else
		{
			r->next=p;
			r=p;
			p=p->next;
		}
	}
	q->next=NULL;
	r->next=NULL;
	q->next=L2->next; 
 }
 void Print(LinkList L)
 {
 	LinkList p;
 	p=L->next;
 	while(p)
 	{
 		cout<<p->data;
 		if(p->next)
 		cout<<" ";
 		p=p->next;
	 }
	 cout<<endl;
 }
 int main()
 {
 	LinkList L,L1,L2;
 	int n;
 	while(1)
 	{
 		cin>>n;
 		if(n==0)
 		return 0;
 		InitList(L);
 		InitList(L1);
 		InitList(L2);
 		CreateList(L,n);
 		Segmentation(L,L1,L2);
 		Print(L1);
 	//	Print(L2);
	 }
 	
 }
