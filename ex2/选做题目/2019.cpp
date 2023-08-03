#include<iostream>
#include<string.h>
using namespace std; 
typedef struct LNode{
	char data;
 	struct LNode *next;
 }LNode,*LinkList;
int Create(LinkList &L,char *x)
{
	LinkList p,q;
	L=new LNode;
	L->data=x[0];
	q=L;
	for(int i=1;i<strlen(x);i++)
	{
		p=new LNode;
		p->data=x[i];
		p->next=NULL;
		q->next=p;
		q=q->next;
	}
	return 1;
}
LinkList Reverse(LinkList p){
    if(p->next == NULL)    
	return p; 
    LinkList q = p->next;
    LinkList head = Reverse(q);
    p->next = NULL;
    q->next = p;
    return head;
    
}
void Output(LinkList p){
//递归从前向后输出链表
	if (p==NULL) return;
    else{
		cout<<p->data;
		Output(p->next);//先操作，再调用 
	}
}
int main()
{
	LinkList L1,L2;
	while(1)
	{
		char x[500];
		cin>>x;
		if(strcmp(x,"0")==0)
		return 0; 
		Create(L1,x);
		L2= Reverse(L1);
		Output(L2);
		cout<<endl;
	}
	
}
