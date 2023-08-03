//#include<iostream>
//using namespace std;
//#define Maxsize 500
//#define OK 1
//#define ERROR 0
//#define OVERFLOW -2
//typedef struct
//{
//	int* base;
//	int* top;
//	int maxsize;
//}Stack;
//int InitStack(Stack& s)
//{
//	s.base = new int[Maxsize];
//	s.top = s.base;
//	s.maxsize = Maxsize;
//	return OK;
//}
//int Push(Stack& s,int e)
//{
//	s.top=e;
//	s.top++;
//}
//int Pop(Stack& s,int &e)
//{
//	s.top--;
//	e=s.top;
//}
//void Find(Stack &s,int n,int a[500][3])
//{
//	for(int i=0;i<n;i++)
//{

//	}
// } 
#include<iostream>
using namespace std;
#define MAX 100
int sum;
int flag;
int p[MAX];
int m[MAX][3];
void DFS(int n)
{
	if(n==sum)
	{
		flag=1;
		return ;
	}
	for(int i=0;i<3;i++)
	{
		if(m[n][i]&&!p[m[n][i]])
		{
			p[m[n][i]]=1;
			DFS(m[n][i]);
			p[m[n][i]]=0;
		}
	}
}
int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
		flag=0;
		for(int i=1;i<=n;i++)
			p[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)
				cin>>m[i][j];
		cin>>sum;	
		p[1]=1;
		DFS(1);
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}

