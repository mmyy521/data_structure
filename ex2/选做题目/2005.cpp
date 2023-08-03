#include<iostream>
#include<iomanip>
#include<ctype.h>
using namespace std;
#define Maxsize 300
#define ERROR 0
#define OK 1
typedef struct
{
	double* base;
	double* top;
	int stacksize;
}Stack;
void InitStack(Stack& s)
{
	s.base = new double[Maxsize];
	if (!s.base)
		exit(0);
	s.top = s.base;
	s.stacksize = Maxsize;
}
double Push(Stack& s, double e)
{
	if (s.top - s.base == s.stacksize)
		return ERROR;
	*s.top++ = e;//����ɸ�ֵ������topָ��������
	return OK;
}
double Pop(Stack& s, double& e)
{
	if (s.top == s.base)
		return ERROR;
	e = *--s.top;//�Ȱ�ָ�������ٸ�ֵ
	return OK;
}
double GetTop(Stack s)
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
void Evaluate(Stack OPND)
{
	char poly;
	cin>>poly;
	while (poly != '=')
	{
		InitStack(OPND);
		for (int i = 0; poly!='='; i++)
		{
			if (poly >= '0' && poly <= '9')//����� ���֣���ѹ��OPNDջ
			{
				double x = (double)poly - 48;
				Push(OPND,x);
			}
			else if(poly=='+'||poly=='-'||poly=='*'||poly=='/')
			{
				double a, b;
				Pop(OPND, a);
				Pop(OPND, b);
				Push(OPND, Operate(b, poly, a));
			}
			double a=GetTop(OPND);
			cin>>poly;
		}
		cout << setiosflags(ios::fixed) << setprecision(2) << GetTop(OPND)<<endl;
		cin>>poly;
	}
}
int main()
{
	Stack OPND;
	Evaluate(OPND);
	return 0;
}
