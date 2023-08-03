#include<iostream>
using namespace std;
#include<string.h>
void Insert_ch(char* ch, char* s,int pos)
{
	int m = strlen(ch);
	int n = strlen(s);
	char cc[500];
	for (int i = m + n; i >= 0 ; i--)
	{
		if(i==m+n)
		cc[i]='\0';
		else if (i < pos - 1)
		{
			cc[i] = ch[i];
		}
		else if (i >= pos - 1 && i < pos + n-1)
		{
			cc[i] = s[i - pos + 1];
		}
		else
		{
			cc[i] = ch[i - n];
		}
	}
	for(int i=0;i<strlen(cc);i++)
		cout<<cc[i];
		cout<<endl;
}
int main()
{
	char ch[500], s[500];
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0)
			return 0;
		cin >> ch;
		cin >> s;
		Insert_ch(ch,s,n);
	}
}
