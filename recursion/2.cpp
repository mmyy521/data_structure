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
		cout<<i;//输出在调用的后面，就是逆序输出	
	}
}
int main()
{conversion(13); return 0;}

