#include<iostream>  //1.��û��ʵ�����´洢��ɾ���ڵ㣬�ٴ�����ʱ����� 
using namespace std;//2.ɾ�������´洢 
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
//����һ 
// void CreateList(LinkList L,int &n)//�ڴ�����ʱ��Ͳ��� 
// {
// 	LinkList p,r;
// 	int flag=0;
// 	int t;
// 	cin>>n;
// 	t=n;
// 	for(int i=0;i<n;i++)		//һ��ѭ��������n������ 
// 	{
// 		flag=0;
// 		p=new LNode;
// 		cin>>p->bk.Name>>p->bk.No>>p->bk.Price;
//	 if(i==0)//��һ���ڵ�ֱ������ 
//	 {
//	 	r=L;
// 		p->next=NULL;
// 		r->next=p;
//	 }
//	 else if(i==1)//�ڶ����ڵ�͵�һ���Ƚ� 
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
//		while(r->next)//����Ľڵ㶼�͸ýڵ�Ƚ� 
//		{
//			r=r->next;
//		if(strcmp(p->bk.Name,r->bk.Name)==0)
//		//	if(p->bk.Price==r->bk.Price)
//			{
//				delete p;
//				flag=1;//�������ظ��� 
//				t--;
//			}		
//		}
//		if(!flag)		//û�з����ظ������ϴ˽ڵ� 
//		{
//			p->next=NULL;
// 			r->next=p;
// 		//	r=p;
//		}
//	 }	
//	 }
//	 n=t;//���ս�������Ľڵ��� 
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
			if(strcmp(p->bk.No,r->bk.No)==0)//��������ͬ��ʱ�� 
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

