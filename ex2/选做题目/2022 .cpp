#include<iostream>
using namespace std;
void Ajust(int* a, int* a1, int* a2,int n)
{
	int j=0, k=0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 0)
		{
			a1[j] = a[i];
			j++;
		}
		else
		{
			a2[k] = a[i];
			k++;
		}
	}
	for (int i = 0; i < j; i++)
		a[i] = a1[i];
	for (int i = 0; i < k; i++)
	{
		a[i+j] = a2[i];
	}
		
}
int main()
{
	int array[500];
	int a1[500],a2[500];
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0)
			return 0;
		for (int i = 0; i < n; i++)
			cin >> array[i];
		Ajust(array, a1, a2,n);
		for (int i = 0; i < n; i++)
		{
			cout << array[i];
			if (i != n - 1)
				cout << " ";
		}
		cout << endl;
	}
}
