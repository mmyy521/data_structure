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
	*s.top++ = e;//����ɸ�ֵ������topָ��������
	return OK;
}
int Pop1(Stack1& s, char& e)
{
	if (s.top == s.base)
		return ERROR;
	e = *--s.top;//�Ȱ�ָ�������ٸ�ֵ
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
	*s.top++ = e;//����ɸ�ֵ������topָ��������
	return OK;
}
int Pop2(Stack2& s, double& e)
{
	if (s.top == s.base)
		return ERROR;
	e = *--s.top;//�Ȱ�ָ�������ٸ�ֵ
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
char Precede(char a, char b)//ջ�����������һ�����
{
	if (a == '(' && b == ')')
		//��ʱ��ջ
		return '=';
	if ((a == '+' || a == '-') && (b == '*' || b == '/') || a == '(' || a == '='|| b == '(')
		//��ʱ��ջ 
		return '<';
	else
		return '>';//��ʱ������ 
	
}

void EvaluateExpression(Stack2 OPND, Stack1 OPTR)
{
	char poly[100];	
	cin >> poly;
	while (poly[0] != '=')
	{
		InitStack1(OPTR);
		InitStack2(OPND);
		Push1(OPTR, '=');						//����һ����־�����ı�־ 
		int flag = 0;//���������һ���ǲ�������,Ҫע��flag��0��ʱ��
		for (int i = 0; poly[i] != '='; i++)
		{
			if (poly[i] >= '0' && poly[i] <= '9')//����� ���֣���ѹ��OPNDջ------------------------------ 
			{
				if (flag == 1)//�����һ���ַ�������
				{
					double x;
					Pop2(OPND, x);//������һ�����֣������������
					double y =(double)poly[i] - 48;//��ע���ַ���ת��Ϊ�����͵Ĳ�ֵ 
					x = x * 10 + y;
					Push2(OPND, x);
				}
				else if (flag > 1)//�����һ���ַ���С��
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
					Push2(OPND, x);//��һ���ַ�������������������ѹ������ջ--------ֻ���������-------------------- 
					flag = 1;//��¼״̬
				}
			}
			else//��������ҲҪ��������
			{
				if (poly[i] == '.')//С��������
				{
					double x;
					Pop2(OPND, x);//������һ�����֣������������
					i++;
					double y = (double)poly[i] - 48;
					x = x + y * 0.1;
					Push2(OPND, x);
					flag = 2;
				}
				else//��������ȱȽ����ȼ�--------------------------------------------------------------- 
				{
					flag = 0;
					switch (Precede(GetTop1(OPTR), poly[i]))
					{
					case '<':
						Push1(OPTR, poly[i]);//���ȼ���ջ��������ߣ���ѹ��ջ
						break;
					case '>'://��ߵĵ͵Ļ��������㣬���ѹ������ջ 
						char e;
						double a, b;
						Pop1(OPTR, e);
						Pop2(OPND, a);
						Pop2(OPND, b);
						Push2(OPND, Operate(b, e, a));
						if(poly[i]!=')'&&poly[i]!='=')
						Push1(OPTR, poly[i]);//�ٰ����ѹ�������ջ 
						break;
					case '='://��ȣ�����������ƥ�䣩�Ͱ�ջ�������������
						Pop1(OPTR, e);
						break;
					}
				}
			}
			double a=GetTop2(OPND);
			char b=GetTop1(OPTR);
		}
		while (GetTop1(OPTR) != '=')//������ʽ������֮����������ջ���������˵��û�� 
		{
			char e;
			double a, b;
			Pop1(OPTR, e);
			if (e == '(')//�������������� 
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




