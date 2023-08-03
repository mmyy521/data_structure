#include<iostream>
using namespace std;
typedef struct LNode
{
	int data;
	 struct LNode* next;
}LNode, * LinkList;
void InitList(LinkList &L)
{
	L=new LNode;
	L=NULL;
 } 
 void CreateList(LinkList &L)
 {
 	LinkList p,q;
 
 	for(int i=0;i<3;i++)
 	{
 		if(i==0)
 		{
 			L=new LNode;
 			L->data=i+1;
 			L->next=NULL;
 			q=L;
		}
		else
		{
		 	p=new LNode;
		 	p->data=i+1;
		 	q->next=p;
		 	p->next=NULL;
		 	q=p;
		 }
	 }
 }
 void Print(LinkList L)
 {
 	LinkList p;
 	p=L;
 	while(p)
 	{
 		cout<<p->data<<" ";
 		p=p->next;
	 }
  } 
// double GetAverage(LinkList p , int n)
//{
//	if(!p->next)	
//	return p->data;
//	else
//	{
//	   double ave=GetAverage(p->next,n-1);
//	   return (ave*(n-1)+p->data)/n;
//	}
//}
int n=3;
double GetAverage(LinkList p )
{
	if(!p->next)	return p->data;
	else
	{
	   n--;
               double ave=GetAverage(p->next);
	   return (ave*n+p->data)/(n+1);
	}
}

int main()
{
	int n;
	n=3;
	LinkList L;
//	InitList(L);
	CreateList(L);
	GetAverage(L);
//	Print(L);
	return 0;
}

