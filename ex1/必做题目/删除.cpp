#include<iostream>//链表删除 
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
void Delete(LinkList L,int n)
{
	int t;
	cin>>t;
	if(t<1||t>n)
	{
		cout<<"Sorry，the position to be deleted is invalid!"<<endl;
		return;
	}
	LinkList r,m;
	r=m=L;
	for(int i=1;i<t;i++)
	{
		r=r->next; 
	}
	m=r->next;
	r->next=m->next;
	delete m;
	Print(L);
}

 int main()
 {
 	LinkList L;
 	InitList (L);
 	int n;
 	cin>>n;
 	CreateList(L,n); 
 	Delete(L,n);
 	return 0;
 }
