#include<iostream>
using namespace std;
typedef struct LNode 
{
	int data;
	struct LNode *next;
}LNode,*LinkList;
//都没有头结点 
void Create(LinkList &p)//结束条件是输入特定值 
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
LinkList Create0(int n)//已知节点个数 创建 
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
 	if(!p->next)//截止条件是p指向最后一个节点 
 	return p->data;
 	else
 	{
 		int max=GetMax(p->next);
		 return p->data>=max?p->data:max;//最后一层返回p->data后就进行倒数第二层的这条语句 
	 }
  } 
void Output(LinkList p)//递归输出 
{
	if(p==NULL)
	return;
	else
	{
		cout<<p->data<<" ";
		Output(p->next);
	}
}
void Print(LinkList p)//普通输出 
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
		return (ave*(n-1)+p->data)/n;//关键语句 
	 } 
 } 
 LinkList Reverse(LinkList p){
//递归逆转链表 
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
