//#include<iostream>
//using namespace std;
//typedef struct
//{
//	int data;
//	struct LNode *next; 
// } LNode,LinkList;
// //�ݹ鴴������ 
// void Create(LinkList p,int n)
// {
// 	if(n==0) return;
// 	else
// 	{
// 		p=new LNode;
// 		cin>>p->data;
// 		p->next=L->next;//ǰ�巨 
// 		L->next=p;
// 		//��巨 
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
//�ݹ鴴������	,��巨 
	int n;
	cin>>n; //��������ֵ������0���˳�
	if (n==0)  p=NULL;
    else{
		p=new LNode;
		p->data=n;
		CreatList(p->next);//�Ȳ����ٵ��� 
	}
}

void Output(LinkList p){
//�ݹ��ǰ����������
	if (p==NULL) return;
    else{
		cout<<p->data<<' ';
		Output(p->next);//�Ȳ������ٵ��� 
	}
}

int GetMax(LinkList p ){
//�ݹ�������ֵ	
    if(!p->next)	
	return p->data;
	else
	{
		int max=GetMax(p->next);//�ȵ��ú��������в��� 
		return  p->data>=max ? p->data:max;
	}

}

int GetLength(LinkList p){
//�ݹ��������Ľ�����
  if(!p->next)                                	//pָ���β������1
      return 1;
    else                                        //ÿ�ݹ�һ�Σ���������1
    {
      return GetLength(p->next)+1;
    }
}

int GetSum(LinkList p )
{//�ݹ�������������������ĺ� 
  if(!p->next)                                  	//pָ���β����������ֵ
      return p->data;
    else
        return p->data+GetSum (p->next);         	
}

double GetAverage(LinkList p,int n)
{//�ݹ��������������������ƽ��ֵ
  if(!p->next)                                  	//pָ���β����������ֵ
      return p->data;
    else
    {
      double ave=GetAverage(p->next,n-1);
      // �ݹ�����β���֮�������n-1������ƽ��ֵ
      return (ave*(n-1)+p->data)/n;         	//����ƽ��ֵ
    }
}

LinkList Reverse(LinkList p){
//�ݹ���ת���� 
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
	  CreatList(L->next);//�ݹ鴴������	  
	  Output(L->next);//�ݹ��ǰ����������	  
	  int num=GetLength(L->next);//�ݹ��������Ľ�����
	  cout<<endl;
	  cout<<"num:"<<num<<endl;
	  cout<<"max:"<<GetMax(L->next)<<endl;//�ݹ�������ֵ	
	  cout<<"sum:"<<GetSum(L->next)<<endl;//�ݹ�������������������ĺ�
	  cout<<"ave:"<<GetAverage(L->next,num)<<endl;//�ݹ��������������������ƽ��ֵ 
	  H=reverseList(L->next);//�ݹ���ת���� 
	  Output(H);//�ݹ��ǰ����������
	  return 0;	  
}

