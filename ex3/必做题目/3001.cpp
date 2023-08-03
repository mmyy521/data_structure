#include<iostream>
#include<string.h>
#include<map>
using namespace std;
typedef char** HuffmanCode;
typedef struct
{
	char ch;
	int weight;
	int parent, lchild, rchild;
}HTNode,*HuffmanTree;
void Select(HuffmanTree HT, int n, int& s1, int& s2)//ѡ����С���� 
{
	int flag=0;
	for(int i=1;i<=n;i++)
	if(HT[i].parent==0)//��ʼ��Ϊδ��ѡ��� 
	{
		s1=s2=i;
		break;
	}	
	for (int i = 1; i <= n; i++)//�ҵ���С�� 
	
	{
		if (HT[i].weight < HT[s1].weight&&HT[i].parent==0)
		{
			s1 = i;
		}	
	}
	if(s2==s1)
	for(int i=1;i<=n;i++)
	if(HT[i].parent==0&&i!=s1)//�����С���ǳ�ʼ���ģ��ͻ�һ�������ں����Ƚ� 
	{
		s2=i;
		break;
	}	
	for (int i = 1; i <= n; i++)
	{
		if (HT[i].weight <= HT[s2].weight&&i!=s1&&HT[i].parent==0)
		{
			s2 = i;
			flag=1;
		}
		if(HT[i].parent==0)//�����Ƿ�ʣ������δ��ѡ�� 
		flag++;	
	}
	if(flag==2)
	{
		for(int i=1;i<=n;i++)//��һ������ʡ����ʹ��ǰ��һ�������ܱ�֤ǰ������й� 
		{
			if(i!=s1&&HT[i].parent==0)
			s2=i;
		}
	}
//	cout<<s1<<" "<<s2<<endl;
}
void CreateMap(char *str, int &n, map<char, int>& m)//����map���� ,ֱ�ӵõ�Ȩֵ 
{
	for (int i = 0; i < strlen(str); i++)
		{
			if (m.count(str[i]) > 0)//������ַ��Ѿ�����
			{
				m.find(str[i])->second++;
			}
			else
			{
				m[str[i]] = 1;
			}
		}
	n = m.size();//n��¼��ͬ�ַ��ĸ���  
}
void CreateHuffmanTree(HuffmanTree& HT, int n, map<char, int> ma)//����������� 
{
	if (n <= 1)
		return;
	int m = 2 * n - 1;
	HT = new HTNode[m + 1];
	//��ʼ������ 
	for (int i = 1; i <= m; i++)//��0�����ã���1��ʼ
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	int k = 1;
	map<char, int> ::iterator iter;
	for (iter = ma.begin(); iter != ma.end(); iter++)
	{
		HT[k].ch = iter->first;
		HT[k].weight = iter->second;
		k++;
	}
	//�������Ĺ��� 
	int s1, s2;
	for (int i = n + 1; i <= m; i++)
	{
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i;//��С�������ڵ�˫��ֵ��Ϊi
		HT[s2].parent = i;
		HT[i].lchild = s1;//�½������Һ��Ӹ�Ϊs1,s2
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}
void CreateHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n)//������������� 
{
	HC = new char* [n + 1];//HC��һ���ַ������� 
	char cd[n];
	cd[n - 1] = '\0';//���һλ��ʼ��Ϊ'\0' 
	for (int i = 1; i <= n; i++)//��1��ʼ
	{
		int start = n - 1;//���뵹�ű�
		int c = i;//��ǰ�ڵ��±�
		int f = HT[i].parent;//����˫���±�
		while (f != 0)//�����ҵ����ڵ�
		{
			--start;
			if (HT[f].lchild == c)
				cd[start] = '0';
			else
				cd[start] = '1';
			c = f;//��ǰ�ڵ����
			f = HT[f].parent;//��ǰ˫�׽�����
		}
		HC[i] = new char[n - start];
		strcpy(HC[i], &cd[start]);//��ֵ�ӵ�һ������λ��ʼ 
	}
	//delete cd;
}
void Print(HuffmanTree HT,HuffmanCode HC,int n, map<char, int> m)//��� 
{
	map<char, int> ::iterator iter;
	int l=0;
	for (iter = m.begin(); iter != m.end(); iter++)//1.��������Ȩֵ 
	{
		l++;
		cout << iter->first << ":" << iter->second;
		if(l==n)
		cout<<endl;
		else
		cout<<" ";	
	}
	for (int i = 1; i <= 2 * n - 1; i++)//�������������� 
	{
		cout << i << " " << HT[i].weight <<" " << HT[i].parent <<" " << HT[i].lchild << " " << HT[i].rchild << endl;
	}
	for (int i = 1; i <= n; i++)//���ÿһ���ַ���Ӧ�ı��� 
	{
		cout << HT[i].ch << ":" << HC[i];
		if(i!=n)
		cout<<" ";
		else
		cout<<endl;
	}
	int q=1;
	char code[500];
	for(iter = m.begin(); iter != m.end(); iter++) //������� 
	{
		for(int i=0;i<iter->second;i++)
		{
			//cout<<HC[q];
			strcat(code,HC[q]);	
		}
		q++;
	}
	//cout<<endl; 
	cout<<code<<endl;
	int t=2*n-1;
	for(int i=0;code[i]!='\0';i++)//������� 
	{
		if(code[i]=='0')
		t=HT[t].lchild;
		else if(code[i]=='1')
		t=HT[t].rchild;
		if(HT[t].lchild==0&&HT[t].rchild==0)
		{
			cout<<HT[t].ch;
			t=2*n-1;
		}
	}
	cout<<endl;
}
int main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	while (1)
	{
		map<char, int> m;
		int n;
		char str[500];
		cin >> str;
		if (strcmp(str,"0")==0)
			return 0;
		CreateMap(str, n, m);
		CreateHuffmanTree(HT, n, m);
		CreateHuffmanCode(HT, HC, n);
		Print(HT,HC,n,m);
	//	cout<<str<<endl;
	}
}

