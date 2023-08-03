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
	*s.top++ = e;//先完成赋值操作，top指针再上移
	return OK;
}
int Pop(Stack& s, char& e)
{
	if (s.top == s.base)
		return ERROR;
	e = *--s.top;//先把指针下移再赋值
	return OK;
}
char GetTop(Stack s)
{
	if (s.top != s.base)
		return *(s.top - 1);
}
char Precede(char a, char b)//栈顶运算符和下一个相比
{
	if ( b == ')')
		//此时出栈 ，出栈后再判断是否要运算 
		return '=';
	else if ((a == '+' || a == '-') && (b == '*' || b == '/') || a == '(' || a == '='|| b == '(')
		//此时入栈 
		return '<';
	else
		return '>';//此时做运算 
	
}
void CreateTree(BiTree &T,char s[])//建立表达式二叉树 
{
	BiTree p,opt[100];
	Stack S;
	InitStack(S);
	Push(S,'=');
	int top=0,flag;
	for(int i=0;s[i]!='=';i++)
	{
		if(s[i]<='9'&&s[i]>='0')//如果是数字就把节点压入树根栈 
		{
			p=new BiNode;
			p->data=s[i];
			p->lchild=NULL;
			p->rchild=NULL;
			opt[++top]=p;
		}
		else //不是的话判断优先级 
		{
			switch(Precede(GetTop(S),s[i])) 
			{
				case '<'://外面的优先级高 /优先级比栈顶运算符高，就压入栈
					{
						Push(S, s[i]);
						break;
					}
				case '>'://优先级比栈顶低就建二叉树压入树根栈 
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
						Push(S, s[i]);//再把这个压入运算符栈 
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
	while (GetTop(S) != '=')//将运算式遍历完之后，如果运算符栈还有运算符说明没完 
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
