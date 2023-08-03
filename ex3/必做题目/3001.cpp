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
void Select(HuffmanTree HT, int n, int& s1, int& s2)//选择最小两项 
{
	int flag=0;
	for(int i=1;i<=n;i++)
	if(HT[i].parent==0)//初始化为未被选择的 
	{
		s1=s2=i;
		break;
	}	
	for (int i = 1; i <= n; i++)//找到最小的 
	
	{
		if (HT[i].weight < HT[s1].weight&&HT[i].parent==0)
		{
			s1 = i;
		}	
	}
	if(s2==s1)
	for(int i=1;i<=n;i++)
	if(HT[i].parent==0&&i!=s1)//如果最小的是初始化的，就换一个，便于后续比较 
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
		if(HT[i].parent==0)//计数是否剩下两个未被选择 
		flag++;	
	}
	if(flag==2)
	{
		for(int i=1;i<=n;i++)//这一步不能省，即使和前面一样，不能保证前面的运行过 
		{
			if(i!=s1&&HT[i].parent==0)
			s2=i;
		}
	}
//	cout<<s1<<" "<<s2<<endl;
}
void CreateMap(char *str, int &n, map<char, int>& m)//利用map创建 ,直接得到权值 
{
	for (int i = 0; i < strlen(str); i++)
		{
			if (m.count(str[i]) > 0)//如果该字符已经存在
			{
				m.find(str[i])->second++;
			}
			else
			{
				m[str[i]] = 1;
			}
		}
	n = m.size();//n记录不同字符的个数  
}
void CreateHuffmanTree(HuffmanTree& HT, int n, map<char, int> ma)//构造哈夫曼树 
{
	if (n <= 1)
		return;
	int m = 2 * n - 1;
	HT = new HTNode[m + 1];
	//初始化过程 
	for (int i = 1; i <= m; i++)//第0个不用，从1开始
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
	//构造树的过程 
	int s1, s2;
	for (int i = n + 1; i <= m; i++)
	{
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i;//最小的两个节点双亲值赋为i
		HT[s2].parent = i;
		HT[i].lchild = s1;//新结点的左右孩子赋为s1,s2
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}
void CreateHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n)//构造哈夫曼编码 
{
	HC = new char* [n + 1];//HC是一个字符串数组 
	char cd[n];
	cd[n - 1] = '\0';//最后一位初始化为'\0' 
	for (int i = 1; i <= n; i++)//从1开始
	{
		int start = n - 1;//编码倒着编
		int c = i;//当前节点下标
		int f = HT[i].parent;//结点的双亲下标
		while (f != 0)//回溯找到根节点
		{
			--start;
			if (HT[f].lchild == c)
				cd[start] = '0';
			else
				cd[start] = '1';
			c = f;//当前节点更换
			f = HT[f].parent;//当前双亲结点更换
		}
		HC[i] = new char[n - start];
		strcpy(HC[i], &cd[start]);//赋值从第一个编码位开始 
	}
	//delete cd;
}
void Print(HuffmanTree HT,HuffmanCode HC,int n, map<char, int> m)//输出 
{
	map<char, int> ::iterator iter;
	int l=0;
	for (iter = m.begin(); iter != m.end(); iter++)//1.输出各结点权值 
	{
		l++;
		cout << iter->first << ":" << iter->second;
		if(l==n)
		cout<<endl;
		else
		cout<<" ";	
	}
	for (int i = 1; i <= 2 * n - 1; i++)//输出哈夫曼编码表 
	{
		cout << i << " " << HT[i].weight <<" " << HT[i].parent <<" " << HT[i].lchild << " " << HT[i].rchild << endl;
	}
	for (int i = 1; i <= n; i++)//输出每一个字符对应的编码 
	{
		cout << HT[i].ch << ":" << HC[i];
		if(i!=n)
		cout<<" ";
		else
		cout<<endl;
	}
	int q=1;
	char code[500];
	for(iter = m.begin(); iter != m.end(); iter++) //输出编码 
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
	for(int i=0;code[i]!='\0';i++)//译码过程 
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

