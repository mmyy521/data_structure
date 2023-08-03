#include<iostream>
#include<string.h>
using namespace std;
#define Maxsize 200
#define ERROR 0
#define OK 1
typedef struct BiNode 
{
	char data;
	struct BiNode *lchild,*rchild;
}BiNode, * BiTree;
typedef struct
{
	char* base;
	char* top;
	int stacksize;
}Stack;
void InitStack(Stack& s)
{
	s.base = new char[Maxsize];
	if (!s.base)
		exit(0);
	s.top = s.base;
	s.stacksize = Maxsize;
}
int Push(Stack& s, char e)
{
	if (s.top - s.base == s.stacksize)
		return ERROR;
	*s.top++ = e;//����ɸ�ֵ������topָ��������
	return OK;
}
int Pop(Stack& s, char& e)
{
	if (s.top == s.base)
		return ERROR;
	e = *--s.top;//�Ȱ�ָ�������ٸ�ֵ
	return OK;
}
char GetTop(Stack s)
{
	if (s.top != s.base)
		return *(s.top - 1);
}
char Precede(char a, char b)//ջ�����������һ�����
{
	if ( b == ')')
		//��ʱ��ջ ����ջ�����ж��Ƿ�Ҫ���� 
		return '=';
	else if ((a == '+' || a == '-') && (b == '*' || b == '/') || a == '(' || a == '='|| b == '(')
		//��ʱ��ջ 
		return '<';
	else
		return '>';//��ʱ������ 
	
}
void CreateTree(BiTree &T,char s[])//�������ʽ������ 
{
	BiTree p,opt[100];
	Stack S;
	InitStack(S);
	Push(S,'=');
	int top=0,flag;
	for(int i=0;s[i]!='=';i++)
	{
		if(s[i]<='9'&&s[i]>='0')//��������־Ͱѽڵ�ѹ������ջ 
		{
			p=new BiNode;
			p->data=s[i];
			p->lchild=NULL;
			p->rchild=NULL;
			opt[++top]=p;
		}
		else //���ǵĻ��ж����ȼ� 
		{
			switch(Precede(GetTop(S),s[i])) 
			{
				case '<'://��������ȼ��� /���ȼ���ջ��������ߣ���ѹ��ջ
					{
						Push(S, s[i]);
						break;
					}
				case '>'://���ȼ���ջ���;ͽ�������ѹ������ջ 
					{
						char e;
						BiTree a, b;
						Pop(S, e);
						a=opt[top--];
						b=opt[top--];
						p=new BiNode;
						p->data=s[i];
						p->lchild=b;
						p->rchild=a;
						opt[++top]=p;
						if(s[i]!=')'&&s[i]!='=')
						Push(S, s[i]);//�ٰ����ѹ�������ջ 
						break; 
					}
					case '=':
						{
							char e;
							BiTree a, b;
							Pop(S, e);
							while(e!='(')
							{
								a=opt[top--];
								b=opt[top--];
								p=new BiNode;
								p->data=e;
								p->lchild=b;
								p->rchild=a;
								opt[++top]=p;
								Pop(S,e);
							}
						}
				default:break;
			}
		}
	}
	while (GetTop(S) != '=')//������ʽ������֮����������ջ���������˵��û�� 
		{
			char e;
			BiTree a, b;
			Pop(S, e);
			a=opt[top--];
			b=opt[top--];
			p=new BiNode;
			p->data=e;
			p->lchild=b;
			p->rchild=a;
			opt[++top]=p;
		}
	T=opt[top];
}
int Operate(int a, char b, int c)
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
int IsData(BiTree T)
{
	if(T->data<='9'&&T->data>='0')
	return 1;
	else
	return 0;
}
int Calculate(BiTree T)
{
	int l,r=0;
	if(T->lchild==NULL&&T->rchild==NULL)
	{
		return T->data-'0';
	}
	else
	{
		l=Calculate(T->lchild);
		r=Calculate(T->rchild);
		return Operate(l,T->data,r);
	}
}
void PreOrderTraverse(BiTree T)
{
    if (T)
    {
        PreOrderTraverse(T->lchild);
        cout << T->data;
        PreOrderTraverse(T->rchild);
    }
}
int main()
{
	while(1)
	{
		BiTree T;
		char s[100];
		cin>>s;
		if(s[0]=='=')
		return 0;
		CreateTree(T,s);
		cout<<Calculate(T)<<endl;
//		PreOrderTraverse(T);
//		cout<<endl;
	}
}
