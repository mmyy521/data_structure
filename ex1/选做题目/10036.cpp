#include<iostream>//找个数大于一半的数 
#define Maxsize 100
#define OVERFLOW -2
using namespace std;
typedef struct
{
	int a;
	int num;
}Data;
typedef struct
{
	Data* elem;
	int length;
}SqList;
//构建空表
int InitList(SqList& L)
{
	L.elem = new Data[Maxsize];
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	return 1;
}
void CreateList(SqList& L)
{ 
	for(int i=0;i<L.length;i++)
	{
		cin>>L.elem[i].a;
		L.elem[i].num=1;
		for(int j=0;j<i;j++)
		{
			if(L.elem[i].a==L.elem[j].a)
			L.elem[i].num++;
		}
	}
}
void Frequency(SqList L)
{
	int max=L.elem[0].num;
	int n;
	for(int i=0;i<L.length;i++)
	{
		if(L.elem[i].num>max)
		{
			n=i;
			max=L.elem[i].num;	
		}
	//	cout<<L.elem[i].a<<": "<<L.elem[i].num<<endl;
	}
	if(max>L.length/2)
	cout<<L.elem[n].a<<endl;
	else
	cout<<-1<<endl;
}
int main()
 {
 	SqList L; 
 	InitList(L);
 	while(1)
 	{
 		cin>>L.length;
 		if(L.length==0)
 		return 0;
 		CreateList(L);
 		Frequency(L);
	 }
 }
