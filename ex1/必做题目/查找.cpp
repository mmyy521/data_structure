#include<iostream>//¡¥±Ì≤È’“ 
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
 void FindLove(LinkList L)
 {
 	int num;
	LinkList L1;
	InitList(L1);
	LinkList p,q;
	p=L->next;
	q=L1;
	char name[50];
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		p=L->next;
		num=0;
		cin>>name;
		while(p)
		{
			if(strcmp(name,p->bk.Name)==0)
			{
				q->next=p;
				q=p;
				p=p->next;
				q->next=NULL;
				num++;
			}
			else
			p=p->next;
		}
		if(num){
			q=L1->next;
			cout<<num<<endl;
			while(q)
			{
				cout<<q->bk.No<<" "<<q->bk.Name<<" "<<setiosflags(ios::fixed)<<setprecision(2) <<q->bk.Price<<endl;
		 		q=q->next;
			 } 	
		}
		else
		cout<<"Sorry£¨there is no your favourite!"<<endl;
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
		FindLove(L);	
	}
 	return 0;
 }
