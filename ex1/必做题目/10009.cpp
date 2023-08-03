#include<iostream>//顺序表删除 
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
int ListDelete(SqList& L, int i)
{
	if (i<1 || i>L.length)
		return ERROR;
	for (int j = i; j <= L.length; j++)
		L.elem[j - 1] = L.elem[j];
	--L.length;
	return OK;
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
	if(InitList(L))
	{
		
		cin>>L.length;
		CreateList(L); 
		int i;
		cin>>i; 
			if (i<1 || i>L.length)
			{
				cout<<"Sorry，the position to be deleted is invalid!"<<endl;
				return 0;
			}
			ListDelete(L, i);
			Print(L);
	}
	return 0;
}
