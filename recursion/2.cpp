#include<iostream>
using namespace std;
void conversion(int n)
{
	if(n==0)	
	return;
	else	
	{
		int i=n%2;	
		conversion(n/2);
		cout<<i;//����ڵ��õĺ��棬�����������	
	}
}
int main()
{conversion(13); return 0;}

