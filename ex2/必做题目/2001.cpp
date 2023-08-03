#include<iostream>
#include<iomanip>
using namespace std;
#define Maxsize 300
#define ERROR 0
#define OK 1
typedef struct
{
	char* base;
	char* top;
	int stacksize;
}Stack1;
typedef struct
{
	double* base;
	double* top;
	int stacksize;
}Stack2;
void InitStack1(Stack1& s)
{
	s.base = new char[Maxsize];
	if (!s.base)
		exit(0);
	s.top = s.base;
	s.stacksize = Maxsize;
}
int Push1(Stack1& s, char e)
{
	if (s.top - s.base == s.stacksize)
		return ERROR;
	*s.top++ = e;//先完成赋值操作，top指针再上移
	return OK;
}
int Pop1(Stack1& s, char& e)
{
	if (s.top == s.base)
		return ERROR;
	e = *--s.top;//先把指针下移再赋值
	return OK;
}
char GetTop1(Stack1 s)
{
	if (s.top != s.base)
		return *(s.top - 1);
}
void InitStack2(Stack2& s)
{
	s.base = new double[Maxsize];
	if (!s.base)
		exit(0);
	s.top = s.base;
	s.stacksize = Maxsize;
}
int Push2(Stack2& s, double e)
{
	if (s.top - s.base == s.stacksize)
		return ERROR;
	*s.top++ = e;//先完成赋值操作，top指针再上移
	return OK;
}
int Pop2(Stack2& s, double& e)
{
	if (s.top == s.base)
		return ERROR;
	e = *--s.top;//先把指针下移再赋值
	return OK;
}
double GetTop2(Stack2 s)
{
	if (s.top != s.base)
		return *(s.top - 1);
}
double Operate(double a, char b, double c)
{
	switch (b)
	{
	case '+':
		return a + c;
		break;
	case '-':
		return a - c;
		break;
	case '*':
		return a * c;
		break;
	case '/':
		return a / c;
		break;
	default:
		break;
	}
}
char Precede(char a, char b)//栈顶运算符和下一个相比
{
	if (a == '(' && b == ')')
		//此时出栈
		return '=';
	if ((a == '+' || a == '-') && (b == '*' || b == '/') || a == '(' || a == '='|| b == '(')
		//此时入栈 
		return '<';
	else
		return '>';//此时做运算 
	
}

void EvaluateExpression(Stack2 OPND, Stack1 OPTR)
{
	char poly[100];	
	cin >> poly;
	while (poly[0] != '=')
	{
		InitStack1(OPTR);
		InitStack2(OPND);
		Push1(OPTR, '=');						//这是一个标志结束的标志 
		int flag = 0;//用来标记上一个是不是数字,要注意flag置0的时机
		for (int i = 0; poly[i] != '='; i++)
		{
			if (poly[i] >= '0' && poly[i] <= '9')//如果是 数字，就压入OPND栈------------------------------ 
			{
				if (flag == 1)//如果上一个字符是整数
				{
					double x;
					Pop2(OPND, x);//弹出上一个数字，加上这个数字
					double y =(double)poly[i] - 48;//需注意字符型转化为浮点型的差值 
					x = x * 10 + y;
					Push2(OPND, x);
				}
				else if (flag > 1)//如果上一个字符是小数
				{
					double x;
					Pop2(OPND, x);
					double y = (double)poly[i] - 48;
					for (int i = 0; i < flag; i++)
					{
						y = y * 0.1;
					}
					x += y;
					Push2(OPND, x);
					flag++;
				}
				else
				{
					double x = (double)poly[i] - 48;
					Push2(OPND, x);//上一个字符是运算符，将这个数字压入数据栈--------只有这种情况-------------------- 
					flag = 1;//记录状态
				}
			}
			else//不是数字也要分类讨论
			{
				if (poly[i] == '.')//小数点的情况
				{
					double x;
					Pop2(OPND, x);//弹出上一个数字，加上这个数字
					i++;
					double y = (double)poly[i] - 48;
					x = x + y * 0.1;
					Push2(OPND, x);
					flag = 2;
				}
				else//运算符，先比较优先级--------------------------------------------------------------- 
				{
					flag = 0;
					switch (Precede(GetTop1(OPTR), poly[i]))
					{
					case '<':
						Push1(OPTR, poly[i]);//优先级比栈顶运算符高，就压入栈
						break;
					case '>'://外边的低的话就做运算，结果压入数据栈 
						char e;
						double a, b;
						Pop1(OPTR, e);
						Pop2(OPND, a);
						Pop2(OPND, b);
						Push2(OPND, Operate(b, e, a));
						if(poly[i]!=')'&&poly[i]!='=')
						Push1(OPTR, poly[i]);//再把这个压入运算符栈 
						break;
					case '='://相等（即左右括号匹配）就把栈顶运算符弹出来
						Pop1(OPTR, e);
						break;
					}
				}
			}
			double a=GetTop2(OPND);
			char b=GetTop1(OPTR);
		}
		while (GetTop1(OPTR) != '=')//将运算式遍历完之后，如果运算符栈还有运算符说明没完 
		{
			char e;
			double a, b;
			Pop1(OPTR, e);
			if (e == '(')//遇到左括号跳过 
				continue;
			Pop2(OPND, a);
			Pop2(OPND, b);
			Push2(OPND, Operate(b, e, a)); 
		}
		cout << setiosflags(ios::fixed) << setprecision(2) << GetTop2(OPND)<<endl;
		cin >> poly;
	}
}
int main()
{
	Stack1 OPTR;
	Stack2 OPND;
	EvaluateExpression(OPND, OPTR);
	return 0;
}




