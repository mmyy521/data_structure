#include<iostream>
using namespace std;
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;
typedef struct VNode//��ͷ���Ľṹ������,���
{
	int datatop;
	LNode* first;
}VNode,TableL[13];
typedef struct//��ͷ���+����Ľṹ��
{
	TableL vertices;//ÿһ������
	int n;			//�ܽ���� 
}AlGragh;
void Create(AlGragh &T)
{
	for(int i=0;i<13;i++)
	{
		T.vertices[i].datatop=i; 
		T.vertices[i].first=NULL;
	}
	int e;
	LNode* p=NULL,*q=NULL;
	for(int i=0;i<T.n;i++)//��巨 
	{
		cin>>e;
		int num=e%13;
		p=new LNode;
		p->data=e;
		p->next=NULL;
	if(T.vertices[num].first==NULL)
	T.vertices[num].first=p;
	else
	{
		q=T.vertices[num].first;
		while(q->next)
		q=q->next;
		q->next=p;
	}
}
}
void Delete(AlGragh &T,int e)
{
	int num=e%13;
		LNode* q,*pre;
		q=pre=T.vertices[num].first;
		if(q->data==e)
		{
			T.vertices[num].first=q->next;
		}
		else
		q=q->next;
		while(q)
		{
			if(q->data==e)
			{
				pre->next=q->next;
				break;
			}
			pre=pre->next;	
			q=q->next;
		}
		T.n--;
}
void Print(AlGragh T)
{
	LNode* p;
	for(int i=0;i<13;i++)
	{
		
		cout<<i;
		p=T.vertices[i].first;
		while(p)
		{
			cout<<" "<<p->data;
			p=p->next;
		}
		cout<<endl; 
	}
}
int main()
{
	while(1)
	{
		AlGragh T;
		cin>>T.n;
		if(T.n==0)
		return 0;
//		Init(T);
		Create(T);
		int e;
		cin>>e;
		Delete(T,e);
		Print(T);
	}
}
