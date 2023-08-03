#include<iostream>//双向链表排序 
using namespace std;
typedef struct TwoL
{
	int data;
	TwoL *prior,*next;
 } TwoL,*TLink;
 void Init(TLink &T)
 {
 	T=new TwoL;
 	T->data=0;
 	T->next=T->prior=NULL;
 }
 void Create(TLink &T,int n)
 {
 	int e;
 	TLink p,q; 
 	q=T; 
 	for(int i=0;i<n;i++)//前插法 
 	{
 		cin>>e;
 		p=new TwoL;
 		p->data=e;
 		p->next=p->prior=NULL;
 		if(q->next==NULL)//如果是第一个节点，没有后面节点的前驱这个指针 
 		{
 			p->next=q->next;
 			q->next=p;
 			p->prior=q;
		 }
 		else
 		{
 			q->next->prior=p;
			 p->next=q->next;
			 q->next=p;
			 p->prior=q; 
		 }
 		
	 }
 }
 void DBubble(TLink L)
 {
 	TLink p=L->next;
	while(p->next)
		p=p->next;
	TLink last=p;//找到最后一个	
	TLink first=L->next;
	while(1)
	{
		if(first!=last)
		{	
			for(p=first;p!=last;p=p->next)
				if(p->data>p->next->data)
				{
					int t=p->data;
					p->data=p->next->data;
					p->next->data=t;
				}
			last=last->prior;
		}
		else
			break;
		if(first!=last)
		{
			for(p=last;p!=first;p=p->prior)
				if(p->data<p->prior->data)
				{
					int t=p->data;
					p->data=p->prior->data;
					p->prior->data=t;
				}
			first=first->next;
		}
		else
			break;
	}

 }
 
 void Print(TLink T)
 {
 	TLink p=T->next;
 	while(p)
 	{
 		if(p->next)
 		cout<<p->data<<" ";
 		else
 		cout<<p->data<<endl;
 		p=p->next;
	 }
  } 
  int main()
  {
  	while(1)
	  {
	  	int n;
	  	TLink T=NULL;
	  	cin>>n;
	  	if(n==0)
	  	return 0;
	  	Init(T); 
	  	Create(T,n);
	  	DBubble(T);
	  	Print(T);
	   } 
}
