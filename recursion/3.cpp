#include<iostream>
using namespace std;
void conversion(int n)
{
	if(n==0)	
	return;
	else
	{	
		n=n/2;	
		conversion(n);
		cout<<n%2;	
	}
}

int main()
{conversion(13); return 0;}

