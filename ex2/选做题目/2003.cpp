#include<iostream>
using namespace std;
#define Maxsize 200
#define OVERFLOW -2
typedef struct
{
	char *base;
	char *top;
	int maxsize;
}Stack;
void InitStack(Stack &s)
{
	s.base=new char[Maxsize];
	if(!s.base)
	exit(OVERFLOW);
	s.top=s.base;
	s.maxsize=Maxsize;
}
int Push(Stack &s,char e)
{
	if(s.top-s.base==s.maxsize)
	return 0;
	*s.top=e;
	s.top++;
	return 1;
}
int Pop(Stack &s,char &e)
{
	if(s.base==s.top)
	return 0;
	e=*--s.top;
	return 1;
} 
int main()
{
	Stack S;
	char e;
	char a[Maxsize];	
	while(1)
	{
		InitStack(S);
		int flag=0;
		cin>>a;
		if(a[0]=='0')
		return 0;
		for(int i=0;a[i]!='\0';i++)
		{
			Push(S,a[i]);
		}
		for(int i=0;a[i]!='\0';i++)
		{
			Pop(S,e);
			if(e!=a[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
}
 
 
