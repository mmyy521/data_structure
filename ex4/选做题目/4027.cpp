#include<iostream>
using namespace std;
int Totol(int a[],int e,int n)
{
	int num=0;
	for(int i=0;i<n;i++)
	if(a[i]<e)
	num++;
	return num;
}
void SortNum(int a[],int n,int a1[])
{
	for(int i=0;i<n;i++){
		int index=Totol(a,a[i],n);
		a1[index]=a[i];
	}
}
void Print(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<a[n-1]<<endl;
}
int main()
{
	int n;
	while(1)
	{
		cin>>n;
		if(n==0)
		return 0;
		int a[100];
		for(int i=0;i<n;i++)
		cin>>a[i]; 
		int a1[100];
		SortNum(a,n,a1);
		Print(a1,n);
	}
}
