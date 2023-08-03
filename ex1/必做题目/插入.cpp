#include<iostream>//顺序表插入 
#include <iomanip>
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
		cin>>L.elem[i].No>>L.elem[i].Name>>L.elem[i].price;
	}
}
void ListInsert(SqList& L, int i, Book e)
{
//	if (i<1 || i>L.length + 1)
//		return ERROR;
//	if (L.length == Maxsize)
//		return ERROR;
	for (int j = L.length - 1; j >= i-1;j--)
	{
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	++L.length;
}
void Print(SqList L)
{
	for(int i=0;i<L.length;i++)
	{
		cout<<L.elem[i].No<<" "<<L.elem[i].Name<<" "<<setiosflags(ios::fixed)<<setprecision(2)<<L.elem[i].price<<endl;
	}
}
int main()
{
	SqList L;
	Book e;
	if(InitList(L))
	{
		cin>>L.length;
		CreateList(L); 
			int i;
			cin >> i;
			cin >> e.No >> e.Name>>e.price;
			if (i<1 || i>L.length + 1)
			{
				cout<<"抱歉，入库位置非法！"<<endl;
				return 0;
			}
			ListInsert(L, i, e);
			Print(L);
	}
	
}
