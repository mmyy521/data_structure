#include<iostream>
using namespace std;
void Display(int n)
{	int i;
	for(i = 1; i <= n; i++)
	cout<<' '<<n;
	cout<<endl;
	if(n > 0) 
	Display(n - 1);//�����������һ���ĵ��� 
}

int main()
{Display(4); return 0;}

