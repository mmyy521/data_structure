#include<iostream>
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
//¹¹½¨¿Õ±í
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
void FindLove(SqList L)
{
	SqList sL;
	InitList(sL);
	int n;
	cin>>n;
	char name[50];
	for(int i=0;i<n;i++)
	{
		cin>>name;
		for(int j=0;j<L.length;j++)
		{
			if(strcmp(name,L.elem[j].Name)==0)
			{
//				strcpy(sL.elem[sL.length].No,L.elem[j].No);
//				strcpy(sL.elem[sL.length].Name,L.elem[j].Name);
//				sL.elem[sL.length].price=L.elem[j].price;
//				sL.length++;
				sL.elem[sL.length]=L.elem[j];
				sL.length++; 
			}
		}
		if(sL.length>0)
		{
			cout<<sL.length<<endl; 
			for(int k=0;k<sL.length;k++)
			cout<<sL.elem[k].No<<" "<<sL.elem[k].Name<<" "<<setiosflags(ios::fixed)<<setprecision(2)<<sL.elem[k].price<<endl;
		}
		else
		cout<<"Sorry£¬there is no your favourite!"<<endl;
	 } 
}
int main()
{
	SqList L;
	if(InitList(L))
	{
		cin>>L.length;
		CreateList(L);
		FindLove(L); 
	 } 
	 return 0;
}
