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
	*s.top = e;//����ɸ�ֵ������topָ��������
	s.top++; 
	return OK;
}
int Pop(Stack& s, int& e)
{
	if (s.top == s.base)
		return ERROR;
	e = *s.top;//�Ȱ�ָ�������ٸ�ֵ
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
	
		if (flag == 0&&s.top==s.base)//�����ж�ջ����̬�ǲ��ǿգ������жϴ��� 
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
