#include<iostream>//找共同后缀 
using namespace std;
typedef struct LNode
{
    char ch;
    struct LNode* next;
}LNode, * LinkList;
void InitList(LinkList& L)
{
    L = new LNode;
    L->next = NULL;
}
void CreateList(LinkList L, int n)
{
    LinkList p, r;
    r = L;
    while (n--)
    {
        p = new LNode;
        cin >> p->ch;
        p->next = NULL;
        r->next = p;
        r = p;  
    }
}
void FindSuffix(LinkList L1,LinkList L2)
{
	LinkList p,q,startp,startq,currq;
	p=L1->next;
	q=L2->next;
	int flag=0;
	while(1)
	{
		flag=0;
		currq=q;
		while(p)//将L1的每个字母都与L2中的一个字母比较 
		{
		  	if(p->ch==q->ch)  //当找到两个字符串有相同的字母时 
			{
				startp=p;//记录字母在两个链表的位置 
				if(q->next==NULL&&p->next)
				{
					while(p->next)
					{
						p=p->next;
					}
					if(p->ch==q->ch)
					{
						p=NULL;
						q=NULL;
						break;
					}
				}
				p=p->next;
				q=q->next; 
				while(p&&q)//判断是否后续的字母都一样 
				{
					if(p->ch!=q->ch)//发现有不一样的时候停止循环，记录状态 
					{
						flag=1;
						break;
					}
					p=p->next;
					q=q->next;
				}
			}
			if(p==NULL||q==NULL)
			break;
 			p=p->next;
		}
		if(p==NULL&&q==NULL&&flag==0)
			break;
		else
		{
			p=L1->next;
			q=currq->next;
		}
	}
//	while(startp)
//	{
		cout<<startp->ch;
//		startp=startp->next;
//	}
}
int main()
{
	LinkList L1,L2;
	int m,n;
	InitList(L1);
	InitList(L2);
	while(1)
	{
		cin>>m>>n;
		if(m==0||n==0)
		return 0;
		CreateList(L1,m);
		CreateList(L2,n);
		FindSuffix(L1,L2);
	}
}
