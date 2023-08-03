#include<iostream>//双向链表节点交换 
using namespace std;
typedef struct DuLNode
{
	int data;
	struct DuLNode *prior;
	struct DuLNode *next;	
 } DuLNode,*DuLinkList;
 void InitList(DuLinkList &L)
 {
 	L=new DuLNode;
 	L->next=NULL;
 	L->prior=NULL;
 }
 void CreateList(DuLinkList L,int n)
 {
 	DuLinkList p,r;
 	r=L;
 	while(n--)
 	{
 		p=new DuLNode;
 		cin>>p->data;
 		p->next=NULL;
 		p->prior=NULL;
 		r->next=p;
 		p->prior=r;
		p->next=NULL;
		r=p;
	 }
 }
 void Print(DuLinkList L)
 {
 	DuLinkList p;
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
 void Exchange(DuLinkList L,int k,int n)
 {
 	DuLinkList p,q;
 	p=L->next;
 	int j=0;
 	if(k==n)
	 {
	 	while(j<k-2)
	 	{
	 		p=p->next;
	 		j++;
		 }
	 	
	 	q=p->next;
	q->prior=p->prior;
	p->next=q->next;
	p->prior->next=q;
	p->prior=q;
	q->next=p;
	return;
	  } 
 	while((p->next)&&j<k-2)
 	{
 		p=p->next;
 		j++;
	}
//	cout<<":::"<<p->data<<endl;
//	r=p->prior;
//	p->prior=r->prior;
//	r->prior->next=p;
//	r->next=p->next;
//	p->next->prior=r;
//	p->next=r;
//	r->prior=p;
	
	q=p->next;
	q->prior=p->prior;
	p->next=q->next;
	p->prior->next=q;
	q->next->prior=p;
	p->prior=q;
	q->next=p;
 }
 int main()
 {
 	DuLinkList L;
 	InitList(L);
 	int n,k;
 	while(1){
 		cin>>n;
 		if(n==0)
 		return 0;
 		CreateList(L,n);
 		cin>>k;
		Exchange(L,k,n);
		Print(L); 
	 }
 	
 }
