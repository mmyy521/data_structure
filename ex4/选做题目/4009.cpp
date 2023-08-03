#include<iostream>
using namespace std;
#define MVnum 100
typedef struct ArcNode //存边的信息的结构体，终点
{
	int Adjvex;
	struct ArcNode* Nextarc;
} ArcNode;
typedef struct VNode//存头结点的结构体数组,起点
{
	int data;
	ArcNode* firstarc;
}VNode,AdjList[MVnum];
typedef struct//存头结点+链表的结构体
{
	AdjList vertices;//每一条链表
	int vexnum, arcnum;
}AlGragh;
int CreateUDG(AlGragh& G)
{
	int v1,v2;
	ArcNode *p1, *p2;
	for (int i = 1; i <= G.vexnum; i++)
	{
		G.vertices[i].data = i;
		G.vertices[i].firstarc = NULL;
	}
	for (int j = 1; j <= G.arcnum; j++)
	{
		cin >> v1 >> v2;
		p1 = new ArcNode;
		p1->Adjvex = v2;
		p1->Nextarc = G.vertices[v1].firstarc;
		G.vertices[v1].firstarc = p1;
		//对称添加
		p2 = new ArcNode;
		p2->Adjvex = v1;
		p2->Nextarc = G.vertices[v2].firstarc;
		G.vertices[v2].firstarc = p2;
	}
	return 1;
} 
void DeleteG(AlGragh &G,int v1,int v2)
{
	ArcNode* p,*q,*p1,*pre;	
	int i;
	 for (i = 1; i <= G.vexnum; i++)
	{
		if(i==v1)
		{
			if(G.vertices[i].firstarc->Adjvex==v2) //如果要删的边在第一个邻接点 
			{
				G.vertices[i].firstarc=G.vertices[i].firstarc->Nextarc;
			}
			else
			{
				pre = G.vertices[i].firstarc;
				p1 = pre->Nextarc;
				while (p1)
				{
					if(p1->Adjvex==v2)
					{
						pre->Nextarc=p1->Nextarc;
						break;
					}
					p1 = p1->Nextarc;
					pre=pre->Nextarc;
				}
			} 
		}
		if(i==v2)
		{
			if(G.vertices[i].firstarc->Adjvex==v1) //如果要删的边在第一个邻接点 
			{
				G.vertices[i].firstarc=G.vertices[i].firstarc->Nextarc;
			}
			else
			{
				pre = G.vertices[i].firstarc;
				p1 = pre->Nextarc;
				while (p1)
				{
					if(p1->Adjvex==v1)
					{
						pre->Nextarc=p1->Nextarc;
						break;
					}
					p1 = p1->Nextarc;
					pre=pre->Nextarc;
				}
			} 
		}
	}
}
void Print(AlGragh G)
{
	ArcNode* p1;
	for (int i = 1; i <= G.vexnum; i++)
	{
		if(G.vertices[i].firstarc==NULL)
		{
			cout<< G.vertices[i].data<<endl;
			continue;	
		}
		else
		cout << G.vertices[i].data << " ";
		if (G.vertices[i].firstarc!=NULL)
		{
			p1 = G.vertices[i].firstarc;
			while (p1)
			{
				cout << p1->Adjvex;
				p1 = p1->Nextarc;
				if(p1==NULL)
				cout<<endl;
				else
				cout<<" ";
			}
		}
		else
		cout << endl;
	}
}
int main()
{
	AlGragh G;
	while(1)
	{
		cin >> G.vexnum >> G.arcnum;
		if (G.arcnum == 0)
			return 0;
		CreateUDG(G);
		int v1,v2;
			cin>>v1>>v2;
			DeleteG(G,v1,v2);
		Print(G);
	}
}
