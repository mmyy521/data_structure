//°¢¿ËÂüº¯Êı
//Ackermann(0, n) = n + 1
//Ackermann(1, n) = n + 2
//Ackermann(2, n) = 2 * n + 3
//Ackermann(3, n) = 2 ^ (n + 3) - 3
#include<iostream>
using namespace std;
int ack(int m, int n)

{
	if (m == 0)
		return n + 1;
	else if (n == 0)
		return ack(m - 1, 1);
	else
		return ack(m - 1, ack(m, n - 1));
}
int main()
{
	int n, m;
	while (1)
	{
cin >> m >> n;
if (n == 0 && m == 0)
return 0;
	int t = ack(m, n);
	cout << t << endl;
	}
	
	return 0;
}
