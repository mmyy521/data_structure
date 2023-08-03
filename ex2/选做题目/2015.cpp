#include<iostream>
#define Maxsize 500
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;
typedef struct
{
	char* base;
	char* top;
	int maxsize;
}Stack;
int InitStack(Stack& s)
{
	s.base = new char[Maxsize];
	if (!s.base)
		exit(OVERFLOW);
	s.top = s.base;
	s.maxsize = Maxsize;
	return OK;
}
int Push(Stack& s,char e)
{
	if (s.top - s.base == s.maxsize)
		return ERROR;
	*s.top = e;
	s.top++;
	return OK;
}
int Pop(Stack& s, char& e)
{
	if (s.base == s.top)
		return ERROR;
	s.top--;
	e = *s.top;
	return OK;
}
char GetTop(Stack s)
{
	return *(s.top-1);
}
char Precede(char a, char b)
{
	if (b == '=' || b == ')')//此时出栈输出
		return 'Y';
	else if(((a=='+'||a=='-')&&(b=='+'||b=='-'))||((a=='*'||a=='/')&&(b=='*'||b=='/')))//优先级相同出栈输出后再入栈 
		return '=';
	else if (a == '(' || a=='=' || b=='(' ||(a == '+' || a == '-') && (b == '*' || b == '/'))//此时入栈
		return '<';
	else
		return '>';
}
void Exchange(Stack& s)
{
	char poly[500];
	char x;
	cin >> poly;
	while (poly[0] != '=')
	{
		InitStack(s);
		Push(s, '=');
		for (int i = 0; poly[i] != '\0'; i++)
		{
			if (poly[i] <= '9' && poly[i] >= '0')//是数字
			{
				cout << poly[i];
			}
			else
			{
				switch (Precede(GetTop(s), poly[i]))
				{
				case '<':
					Push(s, poly[i]);
					break;
				case '>':
					Pop(s, x);
					cout << x;
					while(Precede(GetTop(s),poly[i])=='=')
					{
						Pop(s, x);
						cout << x;
					}
					Push(s, poly[i]);
					break;
				case 'Y':
					if (poly[i] == ')')
					{
						while (GetTop(s) != '(')
						{
							Pop(s, x);
							cout << x;
						}
						Pop(s, x);
					}
					else
						while (GetTop(s) != '=')
						{
							Pop(s, x);
							cout << x;
						}
					break;
				case '=':
					Pop(s,x);
					cout<<x;
					Push(s,poly[i]);
					break;	
				default:
					break;
				}
			}
			char a=GetTop(s); 
		}
		cout<<endl;
		cin >> poly;
	}
}
int main()
{
	Stack s;
	InitStack(s);
	Exchange(s);
	return 0;
}


