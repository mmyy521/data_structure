#include<iostream>//链表逆序存储 
#include <iomanip>
using namespace std;
typedef struct
{
	char No[100];
	char Name[100];
	double Price;
 } Book;
 typedef struct LNode
 {
 	Book bk;
 	struct LNode *next;
 }LNode,*LinkList;
void InitList(LinkList &L)
 {
 	L=new LNode;
 	L->next=NULL; 
 }
 void CreateList(LinkList &L,int n)//用尾插法建立链表 
 {
 	LinkList p,r;
 	r=L;
 	while(n--)
 	{
	 	p=new LNode;
 		cin>>p->bk.Name>>p->bk.No>>p->bk.Price;
 		p->next=NULL;
 		r->next=p;
 		r=p;
	 }
 }
 void Reverse(LinkList L1,LinkList L2)//用头插法将L1插进L2，创建时直接头插更简洁 
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
 		cout<<p->bk.Name<<" "<<p->bk.No<<" "<<setiosflags(ios::fixed)<<setprecision(2) <<p->bk.Price<<endl;
 		
 		p=p->next;
	 }
}
 
 int main()
 {
 	LinkList L1,L2;
 	int n; 
 	cin>>n;
	InitList(L1);
	InitList(L2);
	CreateList(L1,n);
	Reverse(L1,L2);
	Print(L2);
 }

