#include<iostream>
using namespace std;
void Adjust(int a[],int start,int end)
{
	if(start >= end)
	return;
	int i=start;
	int j=end;
	while(i<j)//从后面开始找，找到负的就和前面的第一个不是负的交换 
	{
		while(i<j&&a[j]>0)
		j--;
		while(i<j&&a[i]<0)
		i++;
		a[0]=a[j];
		a[j]=a[i];
		a[i]=a[0];
		j--;
		i++;
	}
	//Adjust(a,start,i-1);
	//Adjust(a,i+1,end);
}

void Print(int c[],int n)
{
	for(int i=1;i<=n-1;i++)
	cout<<c[i]<<" ";
	cout<<c[n]<<endl;
}
int main()
{
	while(1)
	{
		int n;
		cin>>n;
	if(n==0)
	return 0;
	int a[100];
	for(int i=1;i<=n;i++)//0号单元用作辅助 
	cin>>a[i];
	Adjust(a,1,n); 
	Print(a,n);
	}
}
