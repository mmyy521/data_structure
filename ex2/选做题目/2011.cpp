//若m=0，返回n+1。
//若m>0且n=0，返回Ackermann(m-1,1)。
//若m>0且n>0，返回Ackermann(m-1,Ackermann(m,n-1))。
//Ackermann(0,n)=n+1
//Ackermann(1,n)=n+2
//Ackermann(2,n)=2*n+3
//Ackermann(3,n)=2^(n+3)-3
//Ackermann(4,n)=2^2^2^……^2-3，乘幂中共有n+3个2。
#include<iostream>
#include<stdio.h>
#include<malloc.h>
using namespace std;
#define Maxsize 500
typedef struct ElemType
{
    int m;
    int n;

}ElemType;
typedef struct {
	ElemType *base;
	ElemType *top;
	int maxsize;
}Stack;
void InitStack(Stack &s)
{
	s.base = (ElemType *)malloc(Maxsize * sizeof(ElemType));
	s.top=s.base;
	s.maxsize=Maxsize;
}
void Push(Stack &s,ElemType e)
{
	if(s.top-s.base==500)
	exit(0);
	*s.top=e;
	s.top++;
	
}
void Pop(Stack &s,ElemType &e)
{
	s.top--;
	e=*s.top;
}
void Ackermann(Stack S,int m,int n)
{
    InitStack(S);
    S.top->m = m;
    S.top->n = n;
        do
        {
            while (S.top->m)
            {
                while (S.top->n)
                {
                    S.top++;
                    S.top->m = (S.top - 1)->m;
                    S.top->n = (S.top - 1)->n-1;
                }
                S.top->m--;//最高层确实是ack(m,0)=ack(m-1,1)
                S.top->n= 1;
            }
            if (S.top > S.base)//非栈底，同时这时栈底m也不可能为0的
            {
                S.top--;
                S.top->m--;
                S.top->n = (S.top+1)->n + 1;
            }
        } while (S.top!= S.base || S.top->m!=0);
        int ack = S.top->n + 1;
        cout<<ack<<endl;
    
    
//	if(m=0)
//	{
//		cout<<n+1;
//		return;
//	}
//	else if(m>0&&n==0)
//	{
//		while(m>=0)
//		{
//			
//		}
//	}
 } 
int main() 
{
	int m,n;
	Stack s;
	while(1)
	{
		cin>>m>>n;
		if(m==0&&n==0)
		return 0;
		Ackermann(s,m,n); 
	}
}
