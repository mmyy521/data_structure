#include<iostream>//多项式计算 
using namespace std;
typedef struct LNode
{
	int coef;
	int index;
	struct LNode *next;
 } LNode,*LinkList;
 void InitList(LinkList &L)
 {
 	L=new LNode;
 	L->next=NULL;
} 
void CreateList(LinkList L,int n)
{
	LinkList p,q;
	q=L;
	while(n--)
	{
		p=new LNode;
		cin>>p->coef>>p->index;
		p->next=q->next;
		q->next=p;
		q=p;
	}
}
void Sort(LinkList &L,int n)
 {
 	LinkList p,q,r;
 	
 	for(int k=0;k<n-1;k++)
	{
		q = L;		//从头结点开始 
 		p = q->next;
 		r = p->next;
		bool flag = true;      //外层循环优化，如果未交换则退出循环 ,说明遍历之后是已序。 
		for(int j=0;j<n-1-k;j++)
		{
				if(p->index<r->index) 
				{
					p->next=r->next;	//交换节点 
					r->next=q->next;
					q->next=r;
					r=p->next;
					q=q->next;
					flag=false;
				}
				else
				{
					q=p;			//节点后移 
					p=r;
					r=r->next;
				}
				
		}
		if(flag)
		break;
	}
 }
 void DeleteV(LinkList L,int &n)
 {
 	LinkList p,q,r,pre;
 	pre=L;
	q=p=L->next;
	r=q->next;
	while(p&&r)
	{
		while(r)//如果只有一个r=NULL直接退出 
		{
			if(p->index==r->index)//都和前面的一个固定值比较，发现相同的就删除后面的节点 
			{
				p->coef=p->coef+r->coef;
				q->next=r->next;
				r=r->next;
				n--; 
			}
			else if(r->coef==0)
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
		if(p->coef==0)//如果合并后系数是0删除该项
		{
		 	pre->next=p->next;
		 	n--;
		 }
		else
		pre=p;
		p=q=p->next;
			if(p==NULL)
			break;
			r=p->next;	
	} 
}
void Print(LinkList L)
{
	LinkList p;
	p=L->next;
	if(p==NULL)//一个元素都没有的情况 
	{
		cout<<0<<endl;
		return;
	}	
	if(p->next==NULL)//只有一个元素的情况 
	{
		if(p->coef==0)
		cout<<0<<endl;
		else if(p->index==0)
		cout<<p->coef<<endl;
		else
		cout<<p->coef<<"x^"<<p->index<<endl;
		return; 
	 } 
	while(p)//有大于等于2个元素 
	{
		if(p->coef==0)
		{
			p=p->next;
			continue;
		}
		else if(p->index==0)
		{
			cout<<p->coef;
		}
		else
		cout<<p->coef<<"x^"<<p->index;
		if(p->next&&p->next->coef>0)
		cout<<"+";
		p=p->next;
	}
	cout<<endl;
}
void Add(LinkList L1,LinkList L2,LinkList L3)
{
	LinkList p,q,r,h,qprior;
	p=L1->next;
	r=L3;
	int nL3,flag;
	while(p)
	{
		flag=0;
		qprior=L2;
		q=L2->next;
		while(q)
		{
			if(p->index==q->index)//判断 有相等的 
			{
				h=new LNode;
				h->coef=p->coef+q->coef;//开辟一个节点加进L3 
				h->index=p->index; 
				h->next=r->next;
				r->next=h;
				r=h;
				nL3++; 
				flag=1;//记录出现合并项  
				qprior->next=q->next;//删除L2中的合并项 
				q=q->next;
			}
			else
			{
				qprior=qprior->next;//没有相同就向下遍历 
				q=q->next;
			}	
		}
		if(flag==0)//没有合并的就把L1该节点接到L3,要找得到该节点在原链表中的后继，
								//不能改变后继指针指向，所以必须 复制这个节点的值 
		{
			h=new LNode;
			h->coef=p->coef;
			h->index=p->index; 
			h->next=r->next;
			r->next=h;
			r=h;
			nL3++; 
		}
		p=p->next;
	}
	q=L2->next;
	if(q)
	r->next=q;
	while(q)
	{
		q=q->next;
		nL3++;
	}
	DeleteV(L3,nL3);
	Sort(L3,nL3);
	Print(L3);
}
void Subtract(LinkList L1,LinkList L2,LinkList L3)
{
	LinkList p,q,r,h,qprior;
	p=L1->next;
	r=L3;
	int nL3,flag;//发现问题出现在L3的计数上 
	while(p)
	{
		flag=0;
		qprior=L2;
		q=L2->next;
		while(q)
		{
			if(p->index==q->index)//判断 有相等的 
			{
				if(flag==0)//第一个发现相同的 
				{
					flag=1;//记录出现合并项  
					h=new LNode;
					h->coef=p->coef-q->coef;//开辟一个节点加进L3 
					h->index=p->index; 
					h->next=r->next;
					r->next=h;
					r=h;
				}
				else//不是第一个发现，不需要新开辟节点 
				{
					r->coef-=q->coef;
				}	 	
				qprior->next=q->next;//删除L2中的合并项 
				q=q->next;
			}
			else
			{
				qprior=qprior->next;//没有相同就向下遍历 
				q=q->next;
			}	
		}
		if(flag==1)
		nL3++; 
		if(flag==0)//没有合并的就把L1该节点接到L3,要找得到该节点在原链表中的后继，
					//不能改变后继指针指向，所以必须 复制这个节点的值 
		{
			h=new LNode;
			h->coef=p->coef;
			h->index=p->index; 
			h->next=r->next;
			r->next=h;
			r=h;
			nL3++; 
		}
		p=p->next;
	}
	q=L2->next;
	while(q)
	{
		q->coef=-q->coef;
		q=q->next;
		nL3++;
	}
	q=L2->next;
	if(q)
	r->next=q;
	DeleteV(L3,nL3);
	Sort(L3,nL3);
	Print(L3);
}
void Multiply(LinkList L1,LinkList L2,LinkList L3)
{
	LinkList p,q,r,h;
	p=L1->next;
	r=L3;
	int nL3;
	while(p)
	{
		q=L2->next;
		while(q)
		{
			h=new LNode;
			h->coef=p->coef*q->coef;
			h->index=p->index+q->index;
			h->next=r->next;
			r->next=h;
			r=h;
			nL3++;
			q=q->next;
		}
		p=p->next; 
	}
	DeleteV(L3,nL3);
	Sort(L3,nL3);
	Print(L3);
}
void Derivation(LinkList L1,LinkList L2)
{
	LinkList p,q; 
	p=L1->next;
	q=L2->next; 
	while(p)
	{
		p->coef=p->coef*p->index;
		p->index--;
		p=p->next;
	}
	while(q)
	{
		q->coef=q->coef*q->index;
		q->index--;
		q=q->next;
	}
}
int main()
{
	LinkList L1,L2,L3;
	InitList(L1);
	InitList(L2);
	InitList(L3);
	int num,n,m;
	char ch;
	cin>>num;
	for(int i=0;i<num;i++)
	{
		InitList(L1);
		InitList(L2);
		InitList(L3);
		cin>>n>>m;
		CreateList(L1,n);	
		CreateList(L2,m);
		cin>>ch;
		switch(ch)
		{
			case '+':
				{
					Add(L1,L2,L3);
					break;
				}
			case '-':
				{
					Subtract(L1,L2,L3);
					break;
				}
			case '*':
				{
					Multiply(L1,L2,L3);
					break;
				}
			case '\'': 
				{
					Derivation(L1,L2);
					Print(L1);
					Print(L2);
					break;
				}	
		}
	} 
	return 0;
}
