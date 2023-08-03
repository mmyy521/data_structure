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
	int maxsize;
}Queue;
int InitQueue(Queue& q)
{
	q.base = new int[Maxsize];
	if (!q.base)
		exit(OVERFLOW);
	q.front = 0;
	q.rear = 1;
	q.maxsize = Maxsize;
	return OK;
}
int IsEmpty(Queue q)
{
	if (q.rear == (q.front + 1) % Maxsize)
		return OK;
	else
		return ERROR;
}
int IsFull(Queue q)
{
	if (q.front == q.rear)
		return OK;
	else
		return ERROR;
}
int InFront(Queue &q, int e)//front和rear都在下一个,加入第一个的时候另作讨论
{
	if (IsFull(q))
		return ERROR;
	q.base[q.front] = e;
	q.front = (q.front - 1 + Maxsize) % Maxsize;//向下标小的方向发展
	return OK;
}
int InRear(Queue& q, int e)
{
	if (IsFull(q))
		return ERROR;
	q.base[q.rear] = e;
	q.rear = (q.rear + 1) % Maxsize;//向下标大的方向发展
	return OK;
}
int OutFront(Queue& q, int& e)
{
	if (IsEmpty(q))
		return ERROR;
	q.front = (q.front + 1) % Maxsize;
	e = q.base[q.front];
	return OK;
}
int OutRear(Queue& q, int& e)
{
	if (IsEmpty(q))
		return ERROR;
	q.rear = (q.rear - 1 + Maxsize) % Maxsize;
	e = q.base[q.rear];
	return OK;
}
void RoundQueue(Queue& q)
{
	int x,n;
	while (1)
	{
		InitQueue(q);
		cin >> n;
		if (n == 0)
			return;
		for(int i=0;i<n;i++)
		{
			cin >> x;
			InFront(q, x);
		//	InRear(q, x);
		}
		for (int i = 0; i < n; i++)
		{
		//	OutFront(q, x);
			OutRear(q, x);
			cout << x ;
			if (i != n - 1)
				cout << " ";
			else
				cout << endl;
		}
	}
}
int main()
{
	Queue q;
	InitQueue(q);
	RoundQueue(q);
	return 0;
}
