#include<iostream>//����ʽ���� 
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
		q = L;		//��ͷ��㿪ʼ 
 		p = q->next;
 		r = p->next;
		bool flag = true;      //���ѭ���Ż������δ�������˳�ѭ�� ,˵������֮�������� 
		for(int j=0;j<n-1-k;j++)
		{
				if(p->index<r->index) 
				{
					p->next=r->next;	//�����ڵ� 
					r->next=q->next;
					q->next=r;
					r=p->next;
					q=q->next;
					flag=false;
				}
				else
				{
					q=p;			//�ڵ���� 
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
		while(r)//���ֻ��һ��r=NULLֱ���˳� 
		{
			if(p->index==r->index)//����ǰ���һ���̶�ֵ�Ƚϣ�������ͬ�ľ�ɾ������Ľڵ� 
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
		if(p->coef==0)//����ϲ���ϵ����0ɾ������
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
	if(p==NULL)//һ��Ԫ�ض�û�е���� 
	{
		cout<<0<<endl;
		return;
	}	
	if(p->next==NULL)//ֻ��һ��Ԫ�ص���� 
	{
		if(p->coef==0)
		cout<<0<<endl;
		else if(p->index==0)
		cout<<p->coef<<endl;
		else
		cout<<p->coef<<"x^"<<p->index<<endl;
		return; 
	 } 
	while(p)//�д��ڵ���2��Ԫ�� 
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
			if(p->index==q->index)//�ж� ����ȵ� 
			{
				h=new LNode;
				h->coef=p->coef+q->coef;//����һ���ڵ�ӽ�L3 
				h->index=p->index; 
				h->next=r->next;
				r->next=h;
				r=h;
				nL3++; 
				flag=1;//��¼���ֺϲ���  
				qprior->next=q->next;//ɾ��L2�еĺϲ��� 
				q=q->next;
			}
			else
			{
				qprior=qprior->next;//û����ͬ�����±��� 
				q=q->next;
			}	
		}
		if(flag==0)//û�кϲ��ľͰ�L1�ýڵ�ӵ�L3,Ҫ�ҵõ��ýڵ���ԭ�����еĺ�̣�
								//���ܸı���ָ��ָ�����Ա��� ��������ڵ��ֵ 
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
	int nL3,flag;//�������������L3�ļ����� 
	while(p)
	{
		flag=0;
		qprior=L2;
		q=L2->next;
		while(q)
		{
			if(p->index==q->index)//�ж� ����ȵ� 
			{
				if(flag==0)//��һ��������ͬ�� 
				{
					flag=1;//��¼���ֺϲ���  
					h=new LNode;
					h->coef=p->coef-q->coef;//����һ���ڵ�ӽ�L3 
					h->index=p->index; 
					h->next=r->next;
					r->next=h;
					r=h;
				}
				else//���ǵ�һ�����֣�����Ҫ�¿��ٽڵ� 
				{
					r->coef-=q->coef;
				}	 	
				qprior->next=q->next;//ɾ��L2�еĺϲ��� 
				q=q->next;
			}
			else
			{
				qprior=qprior->next;//û����ͬ�����±��� 
				q=q->next;
			}	
		}
		if(flag==1)
		nL3++; 
		if(flag==0)//û�кϲ��ľͰ�L1�ýڵ�ӵ�L3,Ҫ�ҵõ��ýڵ���ԭ�����еĺ�̣�
					//���ܸı���ָ��ָ�����Ա��� ��������ڵ��ֵ 
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
