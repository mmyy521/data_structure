#include<iostream>
using namespace std;
#define MVnum 100
typedef struct ArcNode //��ߵ���Ϣ�Ľṹ�壬�յ�
{
	char Adjvex;
	struct ArcNode* Nextarc;
} ArcNode;
typedef struct VNode//��ͷ���Ľṹ������,���
{
	char data;
	ArcNode* firstarc;
}VNode,AdjList[MVnum];
typedef struct//��ͷ���+����Ľṹ��
{
	AdjList vertices;//ÿһ������
	int vexnum, arcnum;
}AlGragh;
int Located(AlGragh G,char v)
{
	for(int i=1;i<=G.vexnum;i++)
	if(G.vertices[i].data==v)
	return i;
}
int CreateUDG(AlGragh& G)
{
	char v1,v2,v;
	ArcNode *p1,*p2,*r1,*r2;
	for (int i = 1; i <= G.vexnum; i++)
	{
		cin>>v;
		G.vertices[i].data = v;
		G.vertices[i].firstarc = NULL;
	}
	for (int j = 1; j <= G.arcnum; j++)
	{
		int tv1,tv2;
		cin >> v1 >> v2;
		tv1=Located(G,v1);
		tv2=Located(G,v2);
		p1 = new ArcNode;
		p1->Adjvex = v2;
		p1->Nextarc = G.vertices[tv1].firstarc;
		G.vertices[tv1].firstarc = p1;
		//�Գ����
		p2 = new ArcNode;
		p2->Adjvex = v1;
		p2->Nextarc = G.vertices[tv2].firstarc;
		G.vertices[tv2].firstarc = p2;
	}
	return 1;
}
int Two(AlGragh G,int v,int vi,int k)
{
	bool visited[MVnum]={false};
	ArcNode *p;//ջ
	int num=1;
	char S[MVnum];
	char Path[MVnum];
	S[0]=v;
	int top=1;
	Path[num]=S[0];
	int flag=0;	
	int Yes=0; 
	int t=0;
	int t0=Located(G,v);
	p=G.vertices[t0].firstarc; 
	visited[t0]=true;
	if(p==NULL)
	return 0;
	else
	{
		S[top]=p->Adjvex;
		top++;
		Path[++num]=S[top];
	}
	while(top>0)
	{
		if(flag==0)//���µ�Ԫ����ջ  
		{
			if(S[top-1]==vi)
			{
				Yes=1;
				break;
			}
			t=Located(G,S[top-1]);
			visited[t]=true; 
			t=Located(G,p->Adjvex); 
			p=G.vertices[t].firstarc;
		}
		else
		{
			t=Located(G,S[top-1]); 
			p=G.vertices[t].firstarc;
		}
		
		while(p)
		{
			t=Located(G,p->Adjvex); 
			if(visited[t]!=true)//�ҵ���һ��δ��������ջ����һ��ѭ��ʱ��� 
			{
				S[top]=p->Adjvex;
				top++;
				Path[++num]=S[top];
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
	 if(Yes==1&&num-1==k)
	 return 1;
	 else
	 return 0;
}
int main()
{
	while(1)
	{
		AlGragh G;
		int k;
		cin >> G.vexnum >> G.arcnum>>k;
		if (G.vexnum == 0&&G.arcnum==0)
			return 0;
		CreateUDG(G);
		char v,vi;
		cin>>v>>vi;
		int yes=Two(G,v,vi,k);
		if(yes==1)
		cout<<"YES"<<endl;
	 	else
		cout<<"NO"<<endl;
	}
 } 
