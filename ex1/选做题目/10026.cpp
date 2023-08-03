#include<iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;
void InitList(LinkList& L)
{
    L = new LNode;
    L->next = NULL;
}
void CreateList(LinkList L, int n)
{
    LinkList p, r;
    r = L;
    while (n--)
    {
        p = new LNode;
        cin >> p->data;
       p->next = NULL;
        r->next = p;
        r = p;  
    }
}
int FindMax(LinkList L)
{
    LinkList p;
    p = L->next;
    int Max;
    Max = p->data;
    while (p)
    { 
        if (p->data > Max)
            Max = p->data;
        p = p->next;
    }
    return Max;
}
int main()
{
    LinkList L;
    InitList(L);
    int n;
    while (1)
    {
        cin >> n;
        if (n == 0)
            return 0;
        CreateList(L, n);
        cout << FindMax(L) << endl;
        L->next= NULL;
    }
    
    return 0;
}
