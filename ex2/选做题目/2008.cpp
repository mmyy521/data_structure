#include<iostream>
#define Maxsize 500
#define OK 1
#define ERROR 0
#define OVERFLOW -2 
using namespace std;
typedef struct Queue
{
	int* base;
	int front;
	int rear;
	int tag;
}Queue;
int InitQueue(Queue& q)
{
	q.base = new int[Maxsize];
	if (!q.base)
		exit(OVERFLOW);
	q.front = q.rear=0;
	q.tag = 0;
	return OK;
}
int InQueue(Queue &q,int e)
{
	if (q.tag==1&&q.rear==q.front)
		return ERROR;
	q.base[q.rear] = e;
	q.rear = (q.rear + 1) % Maxsize;
	if (q.tag == 0)
		q.tag = 1;
	return OK;
}
int OutQueue(Queue &q, int& e)
{
	if (q.tag==0&&q.rear==q.front)
		return ERROR;
	e = q.base[q.front];
	q.front = (q.front + 1) % Maxsize;
	if (q.tag == 1)
		q.tag = 0;
	return OK;
}
int main()
{
	Queue q;
	int n;
	int x;
	cin>>n;
	while (n!=0)
	{
		InitQueue(q);	
		for(int i=0;i<n;i++)
		{
			cin >> x;
			InQueue(q, x);
		}
		for (int i = 0; i < n; i++)
		{
			OutQueue(q, x);
			cout << x ;
			if(i!=n-1)
			cout<<" ";
			else
			cout<<endl; 
			
		}
		cin >> n;
	}
}

