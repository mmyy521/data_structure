#include<iostream>
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
 } Book;
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
 void CreateList(LinkList &L,int &n)
 {
 	LinkList p,r;
 	r=L;
 	
 	while(1)
 	{
 		p=new LNode;
 		cin>>p->bk.No>>p->bk.Name>>p->bk.Price;
 		if(p->bk.Price<BB)
 		return;
 		
 		p->next=NULL;
 		r->next=p;
 		r=p;
 		n++;
	 }
	 r->next=NULL;
 } 
 void Change(LinkList L,int n)
 {
 	LNode *p,*r;
 	p=L->next;
 	double Num,Ave; 
 	while(p)
 	{
 		Num+=p->bk.Price;
 		p=p->next;	
	}
 	Ave=Num/n;
 	p=L->next;
	while(p)
	{
		if(p->bk.Price<Ave)
		p->bk.Price*=1.2;
		else
		p->bk.Price*=1.1;
		p=p->next;
	}
	cout<<setiosflags(ios::fixed)<<setprecision(2) <<Ave<<endl;
 }
 void Print(LinkList &L)
 {
 	LinkList p;
 	p=L->next;
 	while(p)
 	{
 		cout<<p->bk.No<<" "<<p->bk.Name<<" "<<setiosflags(ios::fixed)<<setprecision(2) <<p->bk.Price<<endl;
 		p=p->next;
	 }
 }
 int main()
 {
 	int n=0;
 	LinkList L; 
 	if(InitList(L))
 	{
 		CreateList(L,n);
 		Change(L,n);
 		Print(L);
	 }
	 return 0;
  } 
