#include<iostream>//最贵图书的查找 
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
		cin>>L.elem[i].Name>>L.elem[i].No>>L.elem[i].price;
	}
}
void Max(SqList L)
{
	int n;
	SqList L1;
	InitList(L1);
	float Mprice=L.elem[0].price; 
	for(int i=0;i<L.length;i++)
	{
		if(L.elem[i].price>Mprice)
		{
			Mprice=L.elem[i].price;
		}
		
	}
	for(int j=0;j<L.length;j++)
	{
		if(L.elem[j].price==Mprice)
	//	
	{
		L1.elem[n]=L.elem[j];
		n++;
	}
		
	}
	cout<<n<<endl;
	for(int i=0;i<n;i++)
	cout<<L1.elem[i].Name<<" "<<L1.elem[i].No<<" "<<setiosflags(ios::fixed)<<setprecision(2)<<L1.elem[i].price<<endl;
	
}
int main()
{
	SqList L;
	if(InitList(L))
	{
		cin>>L.length;
		CreateList(L);
		Max(L);
	}
	return 0;
}
