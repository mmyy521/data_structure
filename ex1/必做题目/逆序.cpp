#include<iostream>//顺序表逆序存储 
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
void CreateList(SqList L)
{
	for(int i=L.length-1;i>=0;i--)
	{
		cin>>L.elem[i].Name>>L.elem[i].No>>L.elem[i].price;
	}
}
void Print(SqList L)
{
	for(int i=0;i<L.length;i++)
	{
		cout<<L.elem[i].Name<<" "<<L.elem[i].No<<" "<<setiosflags(ios::fixed)<<setprecision(2)<<L.elem[i].price<<endl;
	}
}

void Reverse(SqList L1,SqList L2)
{
	int j=0;
	for(int i=L1.length-1;i>=0;i--)
	{
	//	L2.elem[j]=L1.elem[i];
		strcpy(L2.elem[j].Name,L1.elem[i].Name);
		strcpy(L2.elem[j].No,L1.elem[i].No);
		L2.elem[j].price=L1.elem[i].price; 
		j++;
	}
}

int main()
{
	SqList L1,L2; 
 	if(InitList(L1)&&InitList(L2))
 	{
 		cin>>L1.length; 
 		CreateList(L1);
 		Reverse(L1,L2);
 		Print(L2);		
	}	
} 
