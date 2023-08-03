#include<iostream>
#include<map>
#include<string.h>
using namespace std;
int main()
{
	
	while (1)
	{
		map<char, int> m;
		char ch[500];
		cin >> ch;
		if (strcmp(ch, "0") == 0)
			return 0;
	for (int i = 0; i < strlen(ch); i++)
	{
		if (m.count(ch[i]) > 0)//如果该字符已经存在
		{
			m.find(ch[i])->second++;
		}
		else
		{
			m[ch[i]] = 1;
		}
	}
	map<char, int> ::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++)
		cout << iter->first << ":" << iter->second << endl;
	}
}
