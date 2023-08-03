#include<iostream>//顺序表排序 
#include <iomanip>
#include<string.h>
using namespace std;
#define Maxsize 1000
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
	while(1)
	{
		cin>>L.elem[L.length].No>>L.elem[L.length].Name>>L.elem[L.length].price;
		if(L.elem[L.length].price<BB)
		return;
		L.length++;
	}
}
void SelectedSort(SqList L)
{
	 for(int i=0;i<L.length;i++)
	 {
	 	int index=i;
	 	for(int j=i+1;j<L.length;j++)
	 	{
	 		if(L.elem[j].price>L.elem[index].price)
	 		index=j;
		 }
		 if(index!=i)
		 {
		 	Book temp;
			temp=L.elem[index];
			L.elem[index]=L.elem[i];
			L.elem[i]=temp;
		 }
	  } 
 } 
 void Bubble(SqList L)
 {
 	for(int i=0;i<L.length-1;i++)
	{
		for(int j=0;j<L.length-1-i;j++)
		{
			if(L.elem[j].price<L.elem[j+1].price)
			{
				Book temp;
			temp=L.elem[j];
			L.elem[j]=L.elem[j+1];
			L.elem[j+1]=temp;
			}
		}
	}
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
		CreateList(L);
	//	SelectedSort(L); 
	Bubble(L);
		Print(L);
	 } 
	 
	 return 0;
}
