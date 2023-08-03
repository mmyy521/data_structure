//1.先建立邻接矩阵，
//2.对于每个结点遍历其他节点算出距离D[i][j]，
//有边就向下找，找到留记录已经找过，即D[i][j]>0,直到所有的找完
//和6相比较，小于的话就S[i]++,算出比例S[i]/n输出
//*是否可以用邻接表？

#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
#define MaxInt 32767
#define MVNum 100
typedef struct
{
	int arcs[MVNum][MVNum];//邻接矩阵
	int vexnum, arcnum;//图的当前点数和边数
}AMGragh;
void CreateG(AMGragh &G)//总是忘记引用
{
	int v1, v2;
	memset(G.arcs,0,sizeof(G.arcs));
	for (int j = 0; j < G.arcnum; j++)
	{
		cin >> v1 >> v2;
		G.arcs[v1][v2] = 1;
		G.arcs[v2][v1] = 1;
	}
}//建邻接矩阵完成，没有权值，都是1
void Count(AMGragh G, int D[MVNum][MVNum], int S[],int i,int j)
{
	for (int x = 1; x <= G.vexnum; x++)
	{
		if (G.arcs[j][x] == 1&&D[i][x]==0&&x!=i)
		{
			D[i][x]=D[i][j]+1;
			if (D[i][x] <= 6)
				S[i]++;
		//	cout << ":"<<S[i] << endl;
			Count(G, D, S, i, x);
		}
	}
}
void SixDegrees(AMGragh G)
{
	int D[MVNum][MVNum]={0},S[MVNum]={0};
	for (int i = 1; i <= G.vexnum; i++)
	{
		for (int j = 1; j <= G.vexnum; j++)
		{
			if(G.arcs[i][j] == 1 && i != j)
			{
				if(D[i][j]==0)
				S[i]++;
				D[i][j]=1; 
				Count(G, D, S,i,j);
			}
		}
		double t = (S[i]+1)*100 / G.vexnum;//算上自己 
		cout << i << ":" <<" "<< fixed << setprecision(2)<< t <<"%"<< endl;
	}
}
void CoutG(AMGragh G)
{
	for(int i=1;i<G.vexnum;i++)
	{
		for(int j=1;j<G.vexnum;j++)
		{
			cout<<G.arcs[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	while (1)
	{
		AMGragh G1;
		cin >> G1.vexnum >> G1.arcnum;
		if (G1.vexnum == 0)
			return 0;
		CreateG(G1);
	//	CoutG(G);
		SixDegrees(G1);
	}
}
