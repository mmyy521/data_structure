#include<iostream>//链表倒数第k节点 
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

 void Reciprocal(LinkList L,int k,int n)
 {
 	LinkList qk,sk;
 	qk=sk=L->next;
 	while(k--)
 	qk=qk->next;
 	while(qk)
	{
		qk=qk->next;
		sk=sk->next;
	} 
	cout<<sk->data<<endl;
}
int main()
{
	LinkList L;
	int n,k;
	InitList(L);
	while(1)
	{
		cin>>n;
		if(n==0)
		return 0;
		CreateList(L,n);
		cin>>k;
		Reciprocal(L,k,n);
		
	}
	
}

