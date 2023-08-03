#include<iostream>//链表差集 
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
void Difference(LinkList L1,LinkList L2,int n)
{
	LinkList p,q,r;
	r=L1;
	p=L1->next;
	q=L2->next;
//	while(p)
//	{
//		int flag=0;
//		q=L2->next;
//		while(q)
//		{
//			if(p->data==q->data)//有相同的就记录 
//			flag=1;	
//			q=q->next; 
//		}
//		if(flag==1)//如果发现相同的就删除此项 
//		{
//			r->next=p->next;
//			p=p->next;
//		}
//		 else
//		 {
//		 	n++;
//		 	r=r->next;
//		 	p=p->next;
//		 }
//		
//	}
	while(p&&q)
	{
		if(p->data==q->data)
		{
			r->next=p->next;
			p=p->next;
			n--;	
		}
		else if(p->data<q->data)
		{
			r=r->next;
			p=p->next;
		}
		else
		{
			q=q->next;
		}
	}
	Print(L1); 
	cout<< n<<endl;
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
 	Difference(L1,L2,n); 
}
 }
