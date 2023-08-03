#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
#define MaxInt 32767
#define MVNum 100
typedef struct
{
	int vexs[MVNum];//�����
	int arcs[MVNum][MVNum];//�ڽӾ���
	int vexnum, arcnum;//ͼ�ĵ�ǰ�����ͱ���
}AMGragh;
void CreateG(AMGragh &G)//������������
{
	int v1, v2;
	for(int i=1;i<=G.vexnum+1;i++)
	{
		for(int j=1;j<=G.vexnum+1;j++)
		G.arcs[i][j]=0;
	}
	for(int i=1;i<=G.vexnum;i++)//0�ŵ�Ԫû�� 
	G.vexs[i]=i;
	for (int j = 0; j < G.arcnum; j++)
	{
		cin >> v1 >> v2;
		G.arcs[v1][v2] = 1;
		G.arcs[v2][v1] = 1;
	}
}//���ڽӾ�����ɣ�û��Ȩֵ������1
void Delete(AMGragh &G,int v1,int v2)
{
	G.arcs[v1][v2]=0;
	G.arcs[v2][v1]=0;
	G.arcnum--;
}
void Print(AMGragh G)
{
	cout<<"0"<<" ";
	for(int i=1;i<=G.vexnum;i++)
	{
		cout<<G.vexs[i];
		if(i==G.vexnum)
		cout<<endl;
		else
		cout<<" ";	
	}

	for(int i=1;i<=G.vexnum;i++)
	{
		cout<<G.vexs[i]<<" ";
		for(int j=1;j<=G.vexnum;j++)
		{
			cout<<G.arcs[G.vexs[i]][G.vexs[j]];
			if(j==G.vexnum)
			cout<<endl;
			else
			cout<<" ";
		}
		
	}
}
int main()
{
	while(1)
	{
		AMGragh G;
		cin >> G.vexnum >> G.arcnum;
		if (G.vexnum == 0&&G.arcnum==0)
			return 0;
		CreateG(G);
		int v1,v2;
		cin>>v1>>v2;
		Delete(G,v1,v2);
		Print(G);
	}
 } 
