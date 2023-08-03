#include<iostream>//删除链表指定区间 
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;
void InitList(LinkList& L)
{
    L = new LNode;
    L->next = NULL;
}
void CreateList(LinkList L, int n)
{
    LinkList p, r;
    r = L;
    while (n--)
    {
        p = new LNode;
        cin >> p->data;
       p->next = NULL;
        r->next = p;
        r = p;  
    }
}
void Print(LinkList L)
 {
 	LinkList p;
 	p=L->next;
 	while(p)
 	{
 		cout<<p->data;
		 p=p->next;
		 if(p)
		 cout<<" ";
	 }
	 cout<<endl;
 }
 /*void DeleteSome(LinkList L,int mink,int maxk)
 {
 	LinkList p; 
 	p=L->next;
 	for(int i=0;i<maxk-1;i++)
 	{
 		if(i<mink-2)
 		p=p->next;
 		else
		p->next=p->next->next; 
	 }
	 
 }*/
 void DeleteSome(LinkList L,int min,int max)
 {
 	LinkList p,q;
 	q=L;
	p=L->next;
	while(p)
	{
		if(p->data<=max&&p->data>=min)
		{
			q->next=p->next;
			p=p->next; 
		}
		else
		{
			q=q->next;
			p=p->next;
		}
		
	 } 
 }
 int main()
 {
 	LinkList L;
 	InitList(L); 
	 int n;
	 int min,max;
	 while(1)
	 {
	 	cin>>n;
	 	if(n==0)
	 	return 0;
	 	CreateList(L,n);
	 	cin>>min>>max;
		DeleteSome(L,min,max);
		Print(L);
	  } 
 }
