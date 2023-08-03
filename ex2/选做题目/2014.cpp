using namespace std;
#include<iostream>
#include<iomanip>
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
double GetAve(LinkList p,int n)
{
	if(p->next==NULL)
	return p->data; 
	else
	{
		double ave=GetAve(p->next,n-1);
		return (ave*(n-1)+p->data)/n;
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
 		LinkList L=create_list(n); 
 		cout<<setiosflags(ios::fixed)<<setprecision(2)<<GetAve(L,n)<<endl;	
	 }
 
 }
