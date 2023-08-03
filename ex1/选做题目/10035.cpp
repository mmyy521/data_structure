#include<iostream>//Êý×éÑ­»·×óÒÆ 
using namespace std;
typedef struct LNode
{
	int data;
    struct LNode* next;
}LNode, * LinkList; 
void CreateList(LinkList head,int n)
{
	LinkList p,q;
	int flag=0;
	q=head;
	for(int i=0;i<n-1;i++)
	{
		if(flag==0)
		{
			cin>>head->data;
		}
		flag=1;
		p=new LNode;
		cin>>p->data;
		q->next=p;
		p->next=head;
		q=p;
	} 
}
void Circulation(LinkList &head,int k)
{
	while(k--)
	{
		head=head->next;
	}
}
void Print(LinkList head)
 {
 	LinkList p;
 	p=head;
 	while(p->next!=head)
 	{
 		cout<<p->data<<" ";
 		p=p->next;
	 }
	 cout<<p->data<<endl;
 }
int main()
{
	LinkList head; 
	head=new LNode;
	head->next=head;
	int n,k;
	while(1)
	{
		cin>>n;
		if(n==0)
		return 0;
		CreateList(head,n);
		cin>>k;
		Circulation(head,k);
		Print(head);
		
	}
}
