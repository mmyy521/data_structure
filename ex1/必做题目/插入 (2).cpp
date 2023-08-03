#include<iostream>//链表插入 
#include <iomanip>
#include<string.h>
using namespace std;
#define Maxsize 100
#define OK 1
#define ERROR 0
#define OVERFLOW -1 
#define BB 0.0000000001
typedef struct
{
	char No[50];
	char Name[50];
	float Price;

}Book;
typedef struct LNode
 {
 	Book bk;
 	struct LNode *next;
 }LNode,*LinkList;
//构建空表
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
 void Print(LinkList L)
 {
 	LinkList p;
 	p=L->next;
 	while(p)
 	{
 		cout<<p->bk.No<<" "<<p->bk.Name<<" "<<setiosflags(ios::fixed)<<setprecision(2) <<p->bk.Price<<endl;
 		p=p->next;
	 }
 }
void Insert(LinkList L,int n)
{
	int t;
	cin>>t;
	if(t<1||t>n+1)
	{
		cout<<"Sorry，the position to be inserted is invalid!"<<endl;
		return;
	}
	LinkList p,q;
	q=new LNode;
	p=L;
	cin>>q->bk.No>>q->bk.Name>>q->bk.Price;
	for(int i=1;i<t;i++)//不用分情况，所有情况通用的办法 
	{
		p=p->next;
	 } 
	 q->next=p->next;
	 p->next=q; 
	Print(L);
}

 int main()
 {
 	LinkList L;
 	InitList (L);
 	int n;
 	cin>>n;
 	CreateList(L,n); 
 	Insert(L,n);
 	return 0;
 }
