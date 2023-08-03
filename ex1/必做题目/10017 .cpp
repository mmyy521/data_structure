#include<iostream>//—∞’“◊Óº—Œª÷√Õº È 
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
 void FindBest(LinkList L,int n)
 {
 	int t,j=1;
 	int k;
 	LinkList p;
 	cin>>t;
 	for(int i=0;i<t;i++)
	 { 
	 j=1;
	 p=L->next;
	 cin>>k;
 	if(k>n||k<1)
 	{
 		cout<<"Sorry£¨the book on the best position doesn't exist!"<<endl;
		 return; 
	 }
	 else
	 while(p&&j<k)
	 {
	 	p=p->next;
	 	++j;
	 }
	 cout<<p->bk.No<<" "<<p->bk.Name<<" "<<setiosflags(ios::fixed)<<setprecision(2) <<p->bk.Price<<endl;
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
		FindBest(L,n);	
	}
 	return 0;
 }
