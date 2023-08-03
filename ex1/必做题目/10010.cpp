#include<iostream>//顺序表去重 
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
//void CreateList(SqList &L)
//{
//	cin>>L.elem[0].No>>L.elem[0].Name>>L.elem[0].price;
//	char no[50],name[50];
//	float pri; 
//	int n=1,flag=0;
//	for(int i=1;i<L.length;i++)
//	{
//		flag=0;
//		cin>>no>>name>>pri;
//		for(int j=0;j<n;j++)
//		{
//			if((strcmp(L.elem[j].No,no)==0)&&(strcmp(L.elem[j].Name,name)==0)&&(pri==L.elem[j].price))
//			{
//				flag=1;
//				break;	
//			}
//		}
//		if(!flag)
//		{
//		strcpy(L.elem[n].No,no);
//		strcpy(L.elem[n].Name,name); 
//		L.elem[n].price=pri;
//		n++;
//		} 
//	}
//	L.length=n; 
//} 
//
//空间换时间
void Create(SqList L)
{
	for(int i=0;i<L.length;i++)
	{
		cin>>L.elem[i].No>>L.elem[i].Name>>L.elem[i].price;
	}
 } 
//void DeWeight(SqList &L,SqList &NewL)
//{
//	NewL.elem[0]=L.elem[0];
//	NewL.length=1;
//	for(int i=0;i<L.length;i++)
//	{
//		int flag=0;
//		for(int j=0;j<NewL.length;j++)
//		{
//			if((strcmp(L.elem[i].No,NewL.elem[j].No)==0)&&(strcmp(L.elem[i].Name,NewL.elem[j].Name)==0)&&(NewL.elem[j].price==L.elem[i].price))
//		//	if(L.elem[i]==NewL.elem[j])
//			{
//				flag=1;
//				break;	
//			}
//		}
//		if(flag==0)
//		{
//			strcpy(NewL.elem[NewL.length].No,L.elem[i].No);
//			strcpy(NewL.elem[NewL.length].Name,L.elem[i].Name); 
//			NewL.elem[NewL.length].price=L.elem[i].price;
//			NewL.length++;
//		} 
//	}
//}
void  DeWeight(SqList &L)
{
	for(int i=0;i<L.length;i++)
	{
		for(int j=i+1;j<L.length;j++)
		{
			if((strcmp(L.elem[i].No,L.elem[j].No)==0)&&(strcmp(L.elem[i].Name,L.elem[j].Name)==0)&&(L.elem[j].price==L.elem[i].price))
			{
				for (int k = j; k < L.length-1; k++)
				L.elem[k] = L.elem[k+1];
				L.length--;
			}
		}
		
	}
}
void Print(SqList L)
{
	cout<<L.length<<endl;
	for(int i=0;i<L.length;i++)
	{
		cout<<L.elem[i].No<<" "<<L.elem[i].Name<<" "<<setiosflags(ios::fixed)<<setprecision(2)<<L.elem[i].price<<endl;
	}
}
int main()
 {
 	int n=0;
 	SqList L; 
 	if(InitList(L))
 	{
 		cin>>L.length;
 		Create(L);
 		SqList NewL;
		InitList(NewL); 
 		//DeWeight(L,NewL); 
 		DeWeight(L);
 		Print(L);
 		
	 }
	 return 0;
 }
 
