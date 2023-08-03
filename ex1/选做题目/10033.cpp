#include<iostream>//链表中位数 
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
void Median(LinkList L1,LinkList L2,int n)
{
	LinkList p,q;
	p=L1->next;
	q=L2->next;
	int t,flag;
	t=n;
	while(p&&q)
	{
		if(p->data>q->data)
		{
			q=q->next;
			n--;
			flag=1;
		}
		else if(p->data==q->data)
		{
			p=p->next;
			q=q->next;
			n--;
			flag=1;
		}
		else
		{
			p=p->next;
			n--;
			flag=2;
		}
		if(n==1)
		break;
	} 	
	if(flag==1){
 	if(p->data<q->data) 
		cout<<p->data<<endl;
	else
		cout<<q->data<<endl;
	}
	else{
		if(q->data<p->data)
		cout<<q->data<<endl;
		else
		cout<<p->data<<endl;
	}
	
} 
int main()
{
	LinkList L1,L2;
 	InitList(L1);
	 InitList(L2); 
	 int n;
	 while(1)
	 {
	 	cin>>n;
	 	if(n==0)
	 	return 0;
	 	CreateList(L1,n);
	 	CreateList(L2,n);
		Median(L1,L2,n);
	  } 
}
