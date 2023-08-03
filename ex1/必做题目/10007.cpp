#include<iostream>//顺序表最佳位置查找 
#include <iomanip>
#include<string.h>
using namespace std;
#define Maxsize 100
#define OK 1
#define ERROR 0
#define OVERFLOW -1 
#define BB 0.0000000001
typedef struct
{
	char No[50];
	char Name[50];
	float price;

}Book;
typedef struct
{
	Book* elem;
	int length;
}SqList;
//构建空表
int InitList(SqList& L)
{
	L.elem = new Book[Maxsize];
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	return OK;
}
void CreateList(SqList &L)
{
	for(int i=0;i<L.length;i++)
	{
		cin>>L.elem[i].Name>>L.elem[i].No>>L.elem[i].price;
	}
}
void FindBest(SqList L)
{
	int n;
	cin>>n;
	int m;
	for(int j=0;j<n;j++)
	{
		cin>>m;
		if(m<=0||m>L.length)
		{
			cout<<"Sorry，the book on the best position doesn't exist!"<<endl;
			continue;
		}
		int t=m-1; 
		cout<<L.elem[t].Name<<" "<<L.elem[t].No<<" "<<setiosflags(ios::fixed)<<setprecision(2)<<L.elem[t].price<<endl;
		
	}
	
}
int main()
{
	SqList L;
	if(InitList(L))
	{
		cin>>L.length;
		CreateList(L);
		FindBest(L); 
	 } 
	 return 0;
}
