//#include<iostream>
//using namespace std;
//typedef struct
//{
//	int data;
//	struct LNode *next; 
// } LNode,LinkList;
// //递归创建链表 
// void Create(LinkList p,int n)
// {
// 	if(n==0) return;
// 	else
// 	{
// 		p=new LNode;
// 		cin>>p->data;
// 		p->next=L->next;//前插法 
// 		L->next=p;
// 		//后插法 
// 		Create(p->next);
//	 }	
//} 
using namespace std;
#include<iostream>

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

void CreatList(LinkList &p)
{
//递归创建链表	,后插法 
	int n;
	cin>>n; //输入结点数值，输入0则退出
	if (n==0)  p=NULL;
    else{
		p=new LNode;
		p->data=n;
		CreatList(p->next);//先操作再调用 
	}
}

void Output(LinkList p){
//递归从前向后输出链表
	if (p==NULL) return;
    else{
		cout<<p->data<<' ';
		Output(p->next);//先操作，再调用 
	}
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

int GetLength(LinkList p){
//递归求解链表的结点个数
  if(!p->next)                                	//p指向表尾，返回1
      return 1;
    else                                        //每递归一次，结点个数加1
    {
      return GetLength(p->next)+1;
    }
}

int GetSum(LinkList p )
{//递归求解链表中所有整数的和 
  if(!p->next)                                  	//p指向表尾，返回其数值
      return p->data;
    else
        return p->data+GetSum (p->next);         	
}

double GetAverage(LinkList p,int n)
{//递归求解链表中所有整数的平均值
  if(!p->next)                                  	//p指向表尾，返回其数值
      return p->data;
    else
    {
      double ave=GetAverage(p->next,n-1);
      // 递归求解除尾结点之外的其余n-1个结点的平均值
      return (ave*(n-1)+p->data)/n;         	//返回平均值
    }
}

LinkList Reverse(LinkList p){
//递归逆转链表 
//https://www.cnblogs.com/mld-code-life/p/12705213.html
    if(p->next == NULL)    
	return p; 
    LinkList q = p->next;
    LinkList head = Reverse(q);
    p->next = NULL;
    q->next = p;
    return head;
    
}
LinkList reverseList(LinkList head) {
    if(head==NULL || head->next==NULL)
        return head;
    LinkList newHead=reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
}

int main( ){	  
	  LinkList  L,H;
	  L=new LNode;
	  L->next=NULL;
	  CreatList(L->next);//递归创建链表	  
	  Output(L->next);//递归从前向后输出链表	  
	  int num=GetLength(L->next);//递归求解链表的结点个数
	  cout<<endl;
	  cout<<"num:"<<num<<endl;
	  cout<<"max:"<<GetMax(L->next)<<endl;//递归求解最大值	
	  cout<<"sum:"<<GetSum(L->next)<<endl;//递归求解链表中所有整数的和
	  cout<<"ave:"<<GetAverage(L->next,num)<<endl;//递归求解链表中所有整数的平均值 
	  H=reverseList(L->next);//递归逆转链表 
	  Output(H);//递归从前向后输出链表
	  return 0;	  
}

