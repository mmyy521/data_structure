using namespace std;
#include<iostream>

typedef struct LNode{
	int data;
 	struct LNode *next;
 }LNode,*LinkList;
LinkList Create(int n)
{
	LinkList Node = NULL;
	if(n>0)
	{
		Node=new LNode;
		cin>>Node->data;
		Node->next=Create(n-1); 
	}
	return Node;
 } 
 int GetLength(LinkList p)
 {
 	if(p->next==NULL)
 	return 1;
 	else
 	{
 		return GetLength(p->next)+1;
	 }
 }
 int main()
 {
 	int n;
 	while(1)
 	{
 		cin>>n;
 		if(n==0)
 		return 0;
 		LinkList L=Create(n); 
 		cout<<GetLength(L)<<endl;	
	 }
 
 }

