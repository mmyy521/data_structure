#include<iostream>//链表删除绝对值 
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
 void DeleteAbsoluteV(LinkList L)
 {
 	LinkList p,q,r;
	q=p=L->next;
	r=q->next;
	int temp;
	while(p&&r)
	{
		while(r)
		{
			if(p->data==r->data||p->data==(-r->data))//发现有相同的时候 
			{
				q->next=r->next;
				r=r->next; 
			}
			else
			{
				q=q->next;
				r=r->next;
			}
		}
		if(p->next==NULL)
		break;
		p=q=p->next;
		r=p->next;
	} 
 }
 int main(){ 
 LinkList L;
 	InitList(L); 
	 int n;
	 int item;
	 while(1)
	 {
	 	cin>>n;
	 	if(n==0)
	 	return 0;
	 	CreateList(L,n);
		DeleteAbsoluteV(L);
		Print(L);
	  } 
} 
