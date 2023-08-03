#include<iostream>  //1.并没有实现重新存储，删除节点，再创建的时候查重 
using namespace std;//2.删除后重新存储 
#include<iomanip>
#include<string.h>
#define OK 1
#define ERROR 0
typedef struct
{
	char No[100];
	char Name[100];
	double Price;
 } Book;
 typedef struct LNode
 {
 	Book bk;
 	struct LNode *next;
 }LNode,*LinkList;
 int InitList(LinkList &L)
 {
 	L=new LNode;
 	L->next=NULL;
 	return OK;
 }
 void CreateList(LinkList L, int n)
{
    LinkList p, r;
    r = L;
    while (n--)
    {
        p = new LNode;
        cin>>p->bk.No>>p->bk.Name>>p->bk.Price;
       p->next = NULL;
        r->next = p;
        r = p;  
    }
}
//方法一 
// void CreateList(LinkList L,int &n)//在创建的时候就查重 
// {
// 	LinkList p,r;
// 	int flag=0;
// 	int t;
// 	cin>>n;
// 	t=n;
// 	for(int i=0;i<n;i++)		//一层循环，输入n个数据 
// 	{
// 		flag=0;
// 		p=new LNode;
// 		cin>>p->bk.Name>>p->bk.No>>p->bk.Price;
//	 if(i==0)//第一个节点直接连上 
//	 {
//	 	r=L;
// 		p->next=NULL;
// 		r->next=p;
//	 }
//	 else if(i==1)//第二个节点和第一个比较 
//	 {
// 		r=L->next;
// 		if(p->bk.Name==r->bk.Name)
// 		{
//			delete p;
//			t--;
//		}
//		else
//		{
//			p->next=NULL;
// 		    r->next=p;
//		}	
//	 }
//	 else
//	 {
// 		r=L;
//		while(r->next)//后面的节点都和该节点比较 
//		{
//			r=r->next;
//		if(strcmp(p->bk.Name,r->bk.Name)==0)
//		//	if(p->bk.Price==r->bk.Price)
//			{
//				delete p;
//				flag=1;//发现有重复的 
//				t--;
//			}		
//		}
//		if(!flag)		//没有发现重复，连上此节点 
//		{
//			p->next=NULL;
// 			r->next=p;
// 		//	r=p;
//		}
//	 }	
//	 }
//	 n=t;//最终进入链表的节点数 
// }
// 
 void DeWeight(LinkList L,int &n)
 {
// 	LinkList p,q,r;
// 	p=q=L->next;
// 	r=q->next;
// 	int flag=0;
// 	while(p->next&&p->next->next)
// 	{
// 		while(r!=NULL)
// 		{
// 			
// 			if(strcmp(p->bk.Name,r->bk.Name)==0)
// 			{
// 				q->next=r->next;
// 				r=r->next;
// 				
// 				n--;
//			 }
//			 else if(q->next&&q->next->next)
//			 {
//				q=q->next;
//				r=q->next;
//			}
//			else
//			break;
//		 }
//		 if(p->next)
//		 {
//		 	p=q=p->next;
//	 		r=q->next;
//		 }	
//	 }
	 LinkList p,q,r;
	q=p=L->next;
	r=q->next;
	while(p&&r)
	{
		while(r)
		{
			if(strcmp(p->bk.No,r->bk.No)==0)//发现有相同的时候 
			{
				q->next=r->next;
				r=r->next; 
				n--;
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
 void Print(LinkList L,int n)
 {
 	LinkList p;
 	p=L->next;
 	cout<<n<<endl;
 	while(p)
 	{
 		cout<<p->bk.No<<" "<<p->bk.Name<<" "<<setiosflags(ios::fixed)<<setprecision(2) <<p->bk.Price<<endl;

 		p=p->next;
	 }
 }
int main()
 {
 	int n=0;
 	LinkList L; 
 	if(InitList(L))
 	{
 		cin>>n; 
 		CreateList(L,n);
 		DeWeight(L,n); 
 		Print(L,n);
 		
	 }
	 return 0;
 }

