//#include<iostream>
//using namespace std;
//#define Maxsize 500
//typedef struct Stack
//{
//	int* base;
//	int* top;
//	int maxsize;
//} Stack;
//void InitStack(Stack& s)
//{
//	s.base = new int(Maxsize);
//	s.top = s.base;
//	s.maxsize = Maxsize;
//}
//int main()
//{
//	Stack s;
//	int n, x;
//	while (1)
//	{
//		InitStack(s);
//		cin >> n;
//		if (n == 0)
//			return 0;
//		int flag = 0;
//		while (n--)
//		{
//			cin >> x;
//			if (flag == 1)
//				continue;
//			if (x != -1)
//			{
//				//��һ�������ȼ�һ������
//				*s.top = x;s.top++;
//			}
//			else if (s.top == s.base)
//			{
//				cout << "POP ERROR" << endl;
//				flag = 1;
//			}
//			else
//			{
//				s.top--;
//				cout << *s.top << endl;	
//			}
//		}
//	}
//	return 0;
//}
#include <iostream>

#define MAXSIZE 100
#define OK 0
#define OVERFLOW -2
#define ERROR 1

using namespace std;
typedef int Status;

typedef struct {
    int *base;
    int *top;
    int stackSize;
} SqStack;

//��ʼ��
Status InitStack(SqStack &S)
{
    S.base = new int[MAXSIZE]; //����ռ�
    if (!S.base) 
  exit(OVERFLOW);//����ʧ�ܣ��쳣�˳�
    S.top = S.base;
    S.stackSize = MAXSIZE;
    return OK;
}

Status Push(SqStack &S, int e)
{
    if(S.top-S.base==MAXSIZE) //˵��ջ��
        return ERROR;
    *S.top++=e;//Ԫ��e��ջ
    return OK;
}

Status Pop(SqStack &S)
{
    if (S.top==S.base) 
  return ERROR; //ջ��
    S.top--;
    return OK;
}

Status GetTop(SqStack S)
{
    int e;
    if (S.top==S.base)
  return ERROR;//ջ��
    e=*(S.top-1);//����
    return e;
}


int main()
{
 
 int n;
 int a[100];
 
 while(scanf("%d",&n),n)
 {
  SqStack S;
  InitStack(S); 
  int flag=0;
  //for(int i=1;i<=n;i++)
  // scanf("%d",&a[i]);
  for(int j=1;j<=n;j++)
  {
   scanf("%d",&a[j]);
   if(flag==1)
    continue;
   if(a[j]==-1)
   {
    if(S.top!=S.base)//ջ��Ϊ��
    {
     printf("%d\n",GetTop(S));
     Pop(S);
    }
    else
    {
     printf("POP ERROR\n");
    // break;
     flag=1;
    }
   }
   else
    Push(S,a[j]);
  }
 }
 return 0;
}
