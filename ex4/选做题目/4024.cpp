#include<iostream>//�����ַ����� 
using namespace std;
void exchange(char &a,char&b)
{
	char c;
	c=a;
	a=b;
	b=c;
}
void Sort(char c[],int n)
{
	int i=0,j=0,k=n-1;//�����ַ����������֣� 
	while(j<=k)
	{
		if(c[j]=='R')
		{
			exchange(c[i],c[j]);
			i++;//i�����
			if(j<i)//��j��iС 
			j=i; 
		}
		else if(c[j]=='B')
		{
			exchange(c[j],c[k]);
			k--;
		 } 
		 else
		 j++;
	 } 
}
void Print(char c[],int n)
{
	for(int i=0;i<n-1;i++)
	cout<<c[i]<<" ";
	cout<<c[n-1]<<endl;
}
int main()
{
	while(1)
	{
		int n;
		cin>>n;
	if(n==0)
	return 0;
	char c[100];
	for(int i=0;i<n;i++)
	cin>>c[i];
	Sort(c,n);
	Print(c,n);
	}
}
