//#include<iostream>
//#define Maxsize 500
//#define OK 1
//#define ERROR 0
//using namespace std;
//typedef struct Queue
//{
//	int* base;
//	int front;
//	int rear;
//};
//int InitQueue(Queue& q)
//{
//	q.base = new int[Maxsize];
//	if (!q.base)
//		exit(OVERFLOW);
//	q.front = q.rear=0;
//	return OK;
//}
//int InQueue(Queue &q,int e)
//{
//	if ((q.rear) + 1 % Maxsize == q.front)
//		return ERROR;
//	q.base[q.rear] = e;
//	q.rear = (q.rear + 1) % Maxsize;
//	return OK;
//}
//int OutQueue(Queue &q, int& e)
//{
//	if (q.front == q.rear)
//		return ERROR;
//	e = q.base[q.front];
//	q.front = (q.front + 1) % Maxsize;
//	return OK;
//}
//int IsEmpty(Queue q)
//{
//	if (q.front == q.rear)
//		return OK;
//}
//int main()
//{
//	Queue q;
//	int m, n;
//	int x;
//	while (1)
//	{
//		InitQueue(q);
//		cin >> n >> m;
//		if (n == 0 && m == 0)
//			return 0;
//		while (n--)
//		{
//			cin >> x;
//			InQueue(q, x);
//		}
//		while (m--)
//		{
//			OutQueue(q, x);
//			cout << x << " ";
//		}
//		if (IsEmpty(q))
//			cout << "0" << endl;
//		else
//			cout << "1" << endl;
//	}
//	
//}
#include<iostream>
#define Maxsize 500
#define OK 1
#define ERROR 0
using namespace std;
typedef struct QNode
{
	int data;
	struct QNode* next;
}QNode,*QueuePtr;
typedef struct
{
	QueuePtr rear;
}LinkQueue;
void InitQueue(LinkQueue &q)
{
	q.rear = new QNode;
	q.rear->next = q.rear;
}
void InQueue(LinkQueue& q,int e)
{
	QueuePtr p;
	p = new QNode;
	p->data = e;
	p->next = q.rear->next;
	q.rear->next = p;
	q.rear = p;
}
int OutQueue(LinkQueue& q, int& e)
{
	if (q.rear->next == q.rear)
		return ERROR;
	QueuePtr r;
	r = q.rear->next->next;
	e = r->data;
	q.rear->next->next = r->next;
	if (q.rear == r)
		q.rear = q.rear->next;
	delete r;
}
int IsEmpty(LinkQueue q)
{
	if (q.rear->next == q.rear)
		return 1;
}
int main()
{
	LinkQueue q;
	int m, n;
	int x;
	while (1)
	{
		InitQueue(q);
		cin >> n >> m;
		if (n == 0 && m == 0)
			return 0;
		while (n--)
		{
			cin >> x;
			InQueue(q, x);
		}
		while (m--)
		{
			OutQueue(q, x);
			cout << x << " ";
		}
		if (q.rear->next == q.rear)
			cout << "0" << endl;
		else
			cout << "1" << endl;
	}
	
}
