#include<iostream>
#include<string.h>
using namespace std;
#define Maxsize 500
#define OK 1
#define ERROR 0
typedef struct String
{
	char ch;
	int length;
	struct String* next;
}String, * StringList;
void CreateList(StringList& L,char* c)
{
	StringList r;
	int i;
	for (i = 0; c[i] != '\0'; i++)
	{
		if (i == 0)
		{
			L = new String;
			L->ch = c[i];
			L->next = L;
			r = L;
		}
		else
		{
			StringList p = new String;
			p->ch = c[i];
			p->next = L;
			r->next = p;
			r = p;
		}
	}
	L->length = i;
}
int Judge(StringList L, char *ch)
{
	StringList p = L;
	int flag = 0,i = 0,j = 0;
	while(i<=strlen(ch)-L->length)
	{
		if (ch[i] == p->ch)//�����һ���ַ��غ� 
		{	
			flag = 0; 
			p = p->next;
			i++;
			j++;
			while (p != L)
			{
				if (ch[i] == p->ch)
				{
					p = p->next;
					i++;
					j++;
				}
				else//���ֲ�ͬ����ѭ�� 
				{
					flag = 1;
					i = i - j + 2;
					j = 1;
					p = L;
					break;
				}
			}
			if(flag == 0)
			{
				break;
			}
		}
		else
		{
			flag=1;
			i = i - j + 2;
			j = 1;
			p = L;
		}
	}
	if(flag == 1)//��������㣬����0 
	return 0;
	else//������㣬����1 
	return 1;
}
int main()
{
	StringList L,r;
	char ch[200];
	char c[200];
	char m[100]="0";
	while (1)
	{
		cin >> c >> ch;
		if (strcmp(c,m) == 0)
			return 0;
		CreateList(L, c);
		r=L;
		while(r->next!=L)
		{
			cout<<r->ch;
			r=r->next;
		}
		
		cout<<r->ch<<endl;
		r=L;
		int flag=0;
		while(r->next!=L)
		{
			if(Judge(r,ch)==1)//�������غϵĲ��� 
			{
				flag=1;
				break;
			}	
			r=r->next;
		}
		if(flag==1)
		cout<<"YES"<<endl;
		else	//ǰ�������������� 
		{
			if(Judge(r,ch)==1)// ���һ�ַ���
			cout<<"YES"<<endl; 
			else				//���һ��Ҳ������ 
			cout<<"NO"<<endl; 
		}
		
	}
}
