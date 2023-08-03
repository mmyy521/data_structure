#include<iostream>
#include<string.h>
using namespace std;
#define Maxsize 3100
#define ERROR 0
#define OK 1
typedef struct
{
	int* base;
	int* top;
	int stacksize;
}Stack;
void InitStack(Stack& s)
{
	s.base = new int[Maxsize];
	if (!s.base)
		exit(0);
	s.top = s.base;
	s.stacksize = Maxsize;
}
int Push(Stack& s, int e)
{
	if (s.top - s.base == s.stacksize)
		return ERROR;
	*s.top = e;//先完成赋值操作，top指针再上移
	s.top++; 
	return OK;
}
int Pop(Stack& s, int& e)
{
	if (s.top == s.base)
		return ERROR;
	e = *s.top;//先把指针下移再赋值
	s.top--;
	return OK;
}
void Judge(Stack s)
{
	char poly[800];
 	int t=1;
	cin >> poly;
	while (poly[0]!='0')
	{
		InitStack(s);
		int flag = 0;
		for(int i=0;poly[i]!='\0';i++)
		{
			if (poly[i]== 'I')
			{
				Push(s, t);
			}
			else if (poly[i] == 'O')
			{
				if (s.top != s.base)
					Pop(s, t);
				else
				{
					flag = 1;
					break;
				}
			}
		}
	
		if (flag == 0&&s.top==s.base)//必须判断栈的终态是不是空，否则判断错误 
		cout<<"TRUE"<<endl;
		else
		cout<<"FALSE"<<endl;
		cin >> poly;
	}
}
int main()
{
	Stack s;
	InitStack(s);
	Judge(s);
	return 0;
}
