#include<iostream>
using namespace std;
int Judge(int a[50][50],int m,int n)
{
	for (int i = 0; i < m; i++)//�к�
	{
		for (int j = 0; j < n - 1; j++)	//�к�
		{//����a[i][j]�ͺ���ı�
			for (int k = j + 1; k < n; k++)//����������Ƚ�
			{
				if (a[i][j] == a[i][k])
					return 1;
			}
			//������û����ͬ���м�һ,˫��ѭ��
			for (int r = i + 1; r < m; r++)//��������ÿһ��ÿһ��
			{
				for (int p = 0; p < n; p++)
				{
					if (a[i][j] == a[r][p])
						return 1;
				}
			}
		}
	}
	return 0;
}
int main()
{
	int n,m;
	int a[50][50];
	while (1)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			return 0;
		for (int i = 0; i < n; i++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> a[i][k];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int k = 0; k < m; k++)
			{
				cout<< a[i][k]<<" ";
			}
			cout << endl;
		}
		if (Judge(a, n, m) == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
