#include<iostream>
using namespace std;
#define OVERFLOW -2
typedef struct

{

  int top[2], bot[2];                         //栈顶和栈底指针

   int *V;                                     //栈数组

   int m;                                                    //栈最大可容纳元素个数
}DblStack;
void InitStack(DblStack &s,int m)
{
	s.V = new int[m];
	if (!s.V)
	exit(OVERFLOW);
	s.top[0]=s.bot[0]=-1;
	s.top[1]=s.bot[1]=m;
}
int IsEmpty(DblStack s,int flag,int m)
{
	if(flag==0)
	{
		if(s.top[0]==-1)
		return 0;
		else
		return 1;
	}
	else
	{
		if(s.top[1]==m)
		return 0;
		else 
		return 1;
	}
}

int IsFull(DblStack s,int m)//第一行输出 ，总表是否满 
{
	if(s.top[0]-s.top[1]==1||s.top[1]-s.top[0]==1)
	return 1;
	else
	return 0;
}
void Push(DblStack &s,int e,int flag)
{
	if(flag==0)
	{
		s.top[0]++;
		s.V[s.top[0]]=e;
	}
	else
	{
		s.top[1]--;
		s.V[s.top[1]]=e;
	}
}
void Pop(DblStack &s,int &e,int flag)
{
	if(flag==0)
	{
		e=s.V[s.top[0]];
		s.top[0]--;
	}
	else
	{
		e=s.V[s.top[1]];
		s.top[1]++;
	}
}

int main()
{
	DblStack S;
	int m,l1,l2,l3,l4,e;
	while(1) 
	{
		
		cin>>m;
		if(m==0)
		return 0;
		InitStack(S,m);
		cin>>l1>>l2>>l3>>l4;
		while(l1--)
		{
			cin>>e;
			Push(S,e,0);
		}
		while(l2--)
		{
			cin>>e;
			Push(S,e,1);
		}
		cout<<IsFull(S,m)<<endl;
		
		while(l3--)
		{
			Pop(S,e,0);
			cout<<e<<" ";
		}
		cout<<IsEmpty(S,0,m)<<endl;
		
		while(l4--)
		{
			Pop(S,e,1);
			cout<<e<<" ";
		}
		cout<<IsEmpty(S,1,m)<<endl;
	}
}


 
