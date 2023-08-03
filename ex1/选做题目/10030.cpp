#include<iostream>//É¾³ýÄ³Öµ 
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
 void DeleteItem(LinkList L,int item)
 {
 	LinkList p,q;
 	q=L; 
 	p=L->next;
 	while(p)
 	{
 		if(p->data==item)
 		{
 			q->next=p->next;
			 
			 p=p->next;	
		}
		else
		{
			p=p->next;
			q=q->next;
		}
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
	 	cin>>item;
		DeleteItem(L,item);
		Print(L);
	  } 
} 
