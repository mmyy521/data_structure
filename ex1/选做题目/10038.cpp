#include<iostream>//猴子选大王问题 
using namespace std;
typedef struct LNode
 {
 	int data;
 	struct LNode *next;
 }LNode,*LinkList;
void InitList(LinkList &head)
{
	head=new LNode;
	head->next=NULL;
}
void CreateList(LinkList head,int m)
{
	LinkList p,q;
	q=head;
	head->data=1;
	for(int i=1;i<m;i++)
	{
		p=new LNode;
		p->data=i+1;
		q->next=p;
		p->next=head;		
		q=p;
	}
 } 
 void Choose(LinkList head,int m,int n)
 {
 	LinkList p,q;
 	p=head;
// 	for(int i=0;i<k-2;i++)
// 		p=p->next;
// 		cout<<p->next->data;
	if(m==1)
	{
		cout<<p->data<<endl;//只有1个数的情况下 
		return;
	}
	if(n==1)
		{
			for(int i=0;i<m;i++)
			{
				cout<<p->data;
				p=p->next; 
				if(i<m-1)
				cout<<" ";
			 } 
			 cout<<endl;
			 return;
		 } 	
 	while(m!=0)
 	{
 		//当步数比2小时不进这个循环 
 		for(int i=0;i<n-2;i++)//找到要输出的前一个节点 
 		p=p->next;
 		//如果步数是2，正常向下进行
		 //如果步数是1，另作讨论
 		cout<<p->next->data;
 		q=p->next;//删除这个节点 
 		p->next=q->next;
 		delete q;
 		p=p->next;
 		m--;
 		if(m)
 		cout<<" ";
	 }
	 cout<<endl;
 }
int main()
{
	LinkList head;
	int m,n;
	while(1)
	{
		InitList(head);
		cin>>m>>n;
		if(m==0&&n==0)
		return 0;
	CreateList(head,m);
	Choose(head,m,n);
	}
	
}
