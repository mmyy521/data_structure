#include<iostream>
using namespace std;
typedef struct LNode 
{
	int data;
	struct LNode *next;
}LNode,*LinkList;
//��û��ͷ��� 
void Create(LinkList &p)//���������������ض�ֵ 
{
	int n;
	cin>>n;
	if(n==0) 
	p = NULL;
	else
	{
		p=new LNode;
		p->data=n;
		Create(p->next);	
	}
}
LinkList Create0(int n)//��֪�ڵ���� ���� 
{
	LinkList p=NULL;
	if(n>0)
	{
		p=new LNode;
		cin>>p->data;
		p->next=Create0(n-1);
	}
	return p;
 } 
 int GetMax(LinkList p)
 {
 	if(!p->next)//��ֹ������pָ�����һ���ڵ� 
 	return p->data;
 	else
 	{
 		int max=GetMax(p->next);
		 return p->data>=max?p->data:max;//���һ�㷵��p->data��ͽ��е����ڶ����������� 
	 }
  } 
void Output(LinkList p)//�ݹ���� 
{
	if(p==NULL)
	return;
	else
	{
		cout<<p->data<<" ";
		Output(p->next);
	}
}
void Print(LinkList p)//��ͨ��� 
{
	LinkList q;
	while(q)
	{
		cout<<q->data<<" ";
		q=q->next;
	}
 } 
 int GetLength(LinkList p)
 {
 	if(!p->next)
 	return 1;
 	else
 	{
 		return GetLength(p->next)+1;
	 }
  } 
double GetAve(LinkList p,int n)
{
	if(!p->next)
	return p->data;
	else
	{
		double ave=GetAve(p->next,n-1);
		return (ave*(n-1)+p->data)/n;//�ؼ���� 
	 } 
 } 
 LinkList Reverse(LinkList p){
//�ݹ���ת���� 
//https://www.cnblogs.com/mld-code-life/p/12705213.html
    if(p->next == NULL)    
	return p; 
    LinkList q = p->next;
    LinkList head = Reverse(q);
    p->next = NULL;
    q->next = p;
    return head;
    
}
int main()
{
	LinkList L;
	Create(L);
//	int n;
//	cin>>n;
//	L=Create0(n);
	
	Output(L);cout<<endl;
	cout<<"length:"<<GetLength(L)<<endl;
	cout<<"ave:"<<GetAve(L,GetLength(L))<<endl;
	cout<<" max:"<<GetMax(L)<<endl; 
	
	L=Reverse(L);
	Output(L);
//	Print(L);
	return 0;
}
