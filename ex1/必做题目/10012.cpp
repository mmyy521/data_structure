#include<iostream>//链表排序 
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
 	p=new LNode;
 	cin>>p->bk.Name>>p->bk.No>>p->bk.Price;
 	while(p->bk.Price>BB)
 	{
 		n++;
 		p->next=NULL;
 		r->next=p;
 		r=p;
 		p=new LNode;
 		cin>>p->bk.Name>>p->bk.No>>p->bk.Price;
	 }
 } 
 void Sort(LinkList &L,int n)
 {
 	LinkList p,q,r;
 	q = L;
 	p = q->next;
 	r = p->next;
 	for(int k=0;k<n-1;k++)
	{
		q = L;		//从头结点开始 
 		p = q->next;
 		r = p->next;
		bool flag = true;      //外层循环优化，如果未交换则退出循环 ,说明遍历之后是已序。 
		for(int j=0;j<n-1-k;j++)
		{
				if(p->bk.Price<r->bk.Price) 
				{
					p->next=r->next;	//交换节点 
					r->next=q->next;
					q->next=r;
					r=p->next;
					q=q->next;
					flag=false;
				}
				else
				{
					q=p;			//节点后移 
					p=r;
					r=r->next;
				}
				
		}
		if(flag)
		break;
	}
 }
 
 void Print(LinkList &L)
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
 	int n=0;
 	LinkList L; 
 	if(InitList(L))
 	{
 		CreateList(L,n);
 		Sort(L,n);
 		Print(L);
	 }
	 return 0;
  } 
