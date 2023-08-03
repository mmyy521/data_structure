#include<iostream>//数组的分割 
#define Maxsize 500
#define OK 1
#define ERROR 0
#define OVERFLOW -1 
using namespace std;
typedef struct 
{
	int* data;
	int Length; 
}SqList;
int InitList(SqList& L)
{
	L.data = new int[Maxsize];
	if (!L.data)
		exit(OVERFLOW);
	L.Length = 0;
	return OK;
}
void CreateList(SqList L)
{	
	for(int i=0;i<L.Length;i++)
	{
		cin>>L.data[i];
	}
}
int Judge(SqList L)
{
	int flag=0;
	int temp=L.data[L.Length/2];
	for(int i=0;i<=L.Length/2;i++)
	{
		if(L.data[i]<=temp&&L.data[L.Length-i]>=temp)
		{
			flag=1;
			break;
		}
	}
	if(flag=0)
	return OK;
	else
	return ERROR;
}
void quicksort(SqList &L,int start,int end)
{
	if(start >= end)//这一步不能少，需要判断需不需要返回上一层函数 
	return;
	if(Judge(L)==1)
	return;
	int i=start;
	int j=end;
	int key = L.data[i];
	while(i<j)
	{
		while(i < j && L.data[j] >= key)
		j--;
		L.data[i]=L.data[j];
		while(i < j && L.data[i] <= key)
		i++;
		L.data[j]=L.data[i];
	}
	L.data[i]=key;
	quicksort(L,start,i-1);
	quicksort(L,i+1,end);
}
int Partition(int a[],int n)
{
	int low=0,high=n-1;
	int low0=0,high0=n-1;
	int s1,s2,pivokey;
	int flag=1;
	int k=n/2;
	while(flag)
	{
		pivokey=a[low];
		while(low<high)
		{
			while(low<high&&a[high]>=pivokey)
			--high;
			if(low!=high)
			a[low]=a[high];
			while(low<high&&a[low]<=pivokey)
			++low;
			if(low!=high)
			a[high]=a[low];
		}
		a[low]=pivokey;
		if(low==k-1)
		flag=0;
		else
		{
			if(low<k-1)
			{
				low0=++low;
				high=high0;
			}
			else
			{
				high0=--high;
				low=low0;
			}
		}
	}
	for(int i=0;i<k;i++)
	{
		cout<<a[i];
		if(i!=k-1)
		cout<<" ";
	}
	cout<<endl;
	for(int i=k;i<n;i++)
	{
		cout<<a[i];
		if(i!=n-1)
		cout<<" ";
	}
	cout<<endl;
	return 1;
 } 
 
void Print (SqList L)
{
	for(int i=0;i<L.Length/2;i++)
	{
		cout<<L.data[i];
		if(i<L.Length/2-1)
		cout<<" ";
	}
	cout<<endl;
	for(int j=L.Length/2;j<L.Length;j++)
	{
		cout<<L.data[j]; 
		if(j<L.Length-1)
		cout<<" ";
	}
	cout<<endl;
}
int main()
{
//	SqList L;
//	InitList(L);
//	while(1)
//	{
//		cin>>L.Length;
//		if(L.Length==0)
//		return 0;
//		CreateList(L);
//		quicksort(L,0,L.Length-1);
//		Print(L);
//	}
	int a[50];
	int n;
	while(1)
	{
		cin>>n;
		if(n==0)
		return 0;
		for(int i=0;i<n;i++)
		cin>>a[i];
		Partition(a,n);
	}
 } 
