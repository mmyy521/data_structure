#include<iostream>//����ѡ�������� 
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
		cout<<p->data<<endl;//ֻ��1����������� 
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
 		//��������2Сʱ�������ѭ�� 
 		for(int i=0;i<n-2;i++)//�ҵ�Ҫ�����ǰһ���ڵ� 
 		p=p->next;
 		//���������2���������½���
		 //���������1����������
 		cout<<p->next->data;
 		q=p->next;//ɾ������ڵ� 
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
