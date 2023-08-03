#include<iostream>//顺序表创建输出 
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
void CreateList(SqList& L)
{
	int n;
	while(1)
	{
		cin>>L.elem[n].Name>>L.elem[n].No>>L.elem[n].price;
		if(L.elem[n].price<BB)
		return;
		n++;
		L.length++;
	}
}
void Print(SqList L)
{
	for(int i=0;i<L.length;i++)
	{
		cout<<L.elem[i].Name<<" "<<L.elem[i].No<<" "<<setiosflags(ios::fixed)<<setprecision(2)<<L.elem[i].price;
		if(i!=L.length-1)
		cout<<endl;
	}
}
int main()
 {
 	SqList L; 
 	if(InitList(L))
 	{
 		CreateList(L);
 		cout<<L.length<<endl;
 		Print(L);
 		
	 }
	 return 0;
 }
