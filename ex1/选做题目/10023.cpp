#include<iostream>//链表交集 
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

void Intersection(LinkList L1,LinkList L2)
{
	LinkList p,q,r;
	r=L1;
	p=L1->next;
	q=L2->next;
	int flag=0;
//	while(p)		时间复杂度是m*n 
//	{
//		flag=0;
//		q=L2->next;
//		while(q)
//		{
//			if(p->data==q->data)//有相同的就记录 
//			flag=1;	
//			q=q->next; 
//		}
//		if(flag==0)//如果没有发现相同的就删除此项 
//		{
//			r->next=p->next;
//			p=p->next;
//		}
//		 else
//		 {
//		 	r=r->next;
//		 	p=p->next;
//		 }
//	}
	while(p&&q)		//时间复杂度是m+n-1 
	{
		if(p->data==q->data)
			{
				r=r->next;
				p=p->next;
				q=q->next;
			}
			else if(p->data<q->data)
			{
				r->next=p->next;
				p=p->next;
			}
			else 
			{
				q=q->next;
			}
	}	
	r->next=NULL;
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
 int main()
 {
 	LinkList L1,L2;
 	InitList(L1);
	InitList(L2); 
 	int n,m;
 	while(1)
 	{
 		cin>>n>>m;
 		if(n==0&&m==0)
 		return 0;
 	CreateList(L1,n); 
 	CreateList(L2,m);
	Intersection(L1,L2);
	Print(L1);
}
 }
