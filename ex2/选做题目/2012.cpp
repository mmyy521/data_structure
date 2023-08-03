#include<iostream>
using namespace std;
typedef struct LNode{
	int data;
 	struct LNode *next;
 }LNode,*LinkList;

LinkList create_list(int n)
{
    LinkList list_node = NULL;
    
	if (n > 0) {
	   list_node = new LNode; 
	   cin>>list_node->data;
	   list_node->next = create_list(n - 1);
	}
	return list_node;
}
int GetMax(LinkList p ){
//递归求解最大值	
    if(!p->next)	
	return p->data;
	else
	{
		int max=GetMax(p->next);//先调用函数，再有操作 
		return  p->data>=max ? p->data:max;
	}
}
int main()
{
	LinkList p;
	int n;
	while(1)
	{
		cin>>n;
		if(n==0)
		return 0;
		p=create_list(n);
		cout<<GetMax(p)<<endl;
	}
 } 
