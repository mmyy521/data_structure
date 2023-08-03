#include<iostream>
using namespace std;
#define MVnum 100
typedef struct ArcNode //��ߵ���Ϣ�Ľṹ�壬�յ�
{
	int Adjvex;
	struct ArcNode* Nextarc;
} ArcNode;
typedef struct VNode//��ͷ���Ľṹ������,���
{
	int data;
	ArcNode* firstarc;
}VNode,AdjList[MVnum];
typedef struct//��ͷ���+����Ľṹ��
{
	AdjList vertices;//ÿһ������
	int vexnum, arcnum;
}AlGragh;
int CreateUDG(AlGragh& G)
{
	int v1,v2;
	ArcNode *p1, *p2,*r1,*r2;
	for (int i = 1; i <= G.vexnum; i++)
	{
		G.vertices[i].data = i;
		G.vertices[i].firstarc = NULL;
	}
	int flag=0;
	for (int j = 1; j <= G.arcnum; j++)
	{
		cin >> v1 >> v2;
		p1 = new ArcNode;
		p1->Adjvex = v2;
		p2 = new ArcNode;
		p2->Adjvex = v1;
		if(flag==0)
		{
			p1->Nextarc=G.vertices[v1].firstarc;
			G.vertices[v1].firstarc = p1;
			r1=p1;
			p2->Nextarc = G.vertices[v2].firstarc;
			G.vertices[v2].firstarc = p2;
			r2=p2;
			flag=1;
		}
		else
		{
			p1->Nextarc=NULL;
			r1->Nextarc=p1;
			r1=p1;
			p2->Nextarc=NULL;
			r2->Nextarc=p2;
			r2=p2;
		}
	}
	return 1;
}
//void DFS_AL(AlGragh G,int v)
//{
//	cout<<v<<" ";
//	visited[v]=true;
//	ArcNode *p;
//	p=G.vertices[v].firstarc;
//	while(p)
//	{
//		if(!visited[p->Adjvex])
//		DFS_AL(G,p->Adjvex);
//		p=p->Nextarc;
//	}
//}
int TheLast(bool visited[],AlGragh G)
{
	int num=0;
	for(int i=1;i<=G.vexnum;i++)
	{
		if(visited[i]!=true)
		num++;
	}
	if(num==1)
	return 1;
	else
	return 0;
}
void DFS(AlGragh G,int v)
{
	bool visited[MVnum];
	ArcNode *p;//ջ
	int num=0;
	int S[MVnum];
	S[0]=v;
	int top=1;
	p=G.vertices[v].firstarc; 
	cout<<S[top-1]<<" ";
	visited[S[top-1]]=true; 
	S[top++]=p->Adjvex;
	int flag=0;	
	while(top>0)
	{
		if(flag==0)//���µ�Ԫ����ջ  
		{
			if(TheLast(visited,G))
			cout<<S[top-1];
			else
			cout<<S[top-1]<<" ";
			visited[S[top-1]]=true; 
			int first=p->Adjvex; 
			p=G.vertices[first].firstarc;
		}
		else
		p=G.vertices[S[top-1]].firstarc;
		while(p)
		{
			if(visited[p->Adjvex]!=true)//�ҵ���һ��δ��������ջ����һ��ѭ��ʱ��� 
			{
				S[top]=p->Adjvex;
				top++;
				flag=0;
				break;
			}
			p=p->Nextarc;
		}
		if(p==NULL)//�ýڵ���ٽӵ�ȫ�����ʹ����ýڵ��ջ�����˵���һ�ڵ㣿 
		{
			top--;
			flag=1;	
		}
	 } 
}
int main()
{
	while(1)
	{
		AlGragh G;
		cin >> G.vexnum >> G.arcnum;
		if (G.vexnum == 0&&G.arcnum==0)
			return 0;
		CreateUDG(G);
		int v;
		cin>>v;
		DFS(G,v);
		cout<<endl;
	}
 } 
