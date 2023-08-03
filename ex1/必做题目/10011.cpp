#include<iostream>  //??c语言输入输出？ 
#include<stdio.h>  //链表创建输出 
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
 void CreateList(LinkList L,int &n)
 {
 	LinkList p,r;
 	r=L;
 	p=new LNode;
 	cin>>p->bk.Name>>p->bk.No>>p->bk.Price;
 	//scanf("%s %s %lf",p->bk.Name,p->bk.No,&p->bk.Price);字符串是s不是c 
 	while(p->bk.Price>BB)
 	{
 		n++;
 		p->next=NULL;
 		r->next=p;
 		r=p;
 		p=new LNode;
 		cin>>p->bk.Name>>p->bk.No>>p->bk.Price;
 		//scanf("%s %s %lf",p->bk.Name,p->bk.No,&p->bk.Price);
	 }
 }
 void Print(LinkList L)
 {
 	LinkList p;
 	p=L->next;
 	while(p)
 	{
 		cout<<p->bk.Name<<" "<<p->bk.No<<" "<<setiosflags(ios::fixed)<<setprecision(2) <<p->bk.Price<<endl;
 		//printf("%s %s %.2f\n",p->bk.Name,p->bk.No,p->bk.Price);
 		p=p->next;
	 }
 }
 int main()
 {
 	int n=0;
 	LinkList L; 
 	if(InitList(L))
 	{
 		//cout<<"请输入："<<endl; 
 		CreateList(L,n);
 		cout<<n<<endl;
 		Print(L);
 		
	 }
	 return 0;
 }
