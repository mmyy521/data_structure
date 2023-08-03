#include<iostream>//Á´±íÕÒ×î´ó 
#include<string.h>
#include <iomanip>
using namespace std;
#define OK 1
#define ERROR 0
#define BB 0.0000000001
typedef struct
{
	char No[100];
	char Name[100];
	double Price;
}Book;
 typedef struct LNode
 {
 	Book bk;
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
 		cin>>p->bk.No>>p->bk.Name>>p->bk.Price;
 		r->next=p;
 		r=p;
	 }
	 r->next=NULL; 
 }
 void Max(LinkList L)
 {
 	int num;
	LinkList L1;
	InitList(L1);
	LinkList p,q;
	p=L->next;
	q=L1;
	float Mprice = p->bk.Price;
	p=p->next;
	while(p)
	{
		if(p->bk.Price>Mprice)
		{
			Mprice=p->bk.Price;
			num=1;
		}
		else if(p->bk.Price==Mprice)
		num++;
		p=p->next;
	}
	q = L->next;
	cout<<num<<endl;
	while(q)
	{
		if(q->bk.Price==Mprice)
		cout<<q->bk.No<<" "<<q->bk.Name<<" "<<setiosflags(ios::fixed)<<setprecision(2) <<q->bk.Price<<endl;
 		q=q->next;
	 } 
 }
 int main()
 {
 	int n;
 	cin>>n;
 	LinkList L;
 	if(InitList(L))
 	{
 		CreateList(L,n);
		Max(L);	
	}
 	return 0;
 }
