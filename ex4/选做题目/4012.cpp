#include<iostream>
using namespace std;
#define MaxInt 32767
#define MVNum 100
typedef struct
{
	int vexs[MVNum];//顶点表
	int arcs[MVNum][MVNum];//邻接矩阵
	int vexnum, arcnum;//图的当前点数和边数
}AMGragh;
void CreateUDN(AMGragh &G)//建立邻接矩阵 
{
	int v1, v2;
	int w;
	for (int i = 1; i <= G.vexnum; i++)//输入各点
		G.vexs[i]=i;
	for (int i = 1; i <= G.vexnum; i++)//初始化各边
	{
		for (int j = 1; j <= G.vexnum; j++)
		{
			G.arcs[i][j] = MaxInt;//设为无穷 
		}
	}
	int n, m;
	for (int i = 0; i < G.arcnum; i++)//输入各边
	{
		cin >> v1 >> v2>> w;
		G.arcs[v1][v2] = w;//无向的话对称 
		G.arcs[v2][v1] = w;
	}//建矩阵完成
}

//
void DIJ(AMGragh G)
{
	int v0;
	bool S[MVNum];//记录v0~vi是否确定最短路径
	int Path[MVNum];//记录v0~vi直接前驱
	int D[MVNum];//记录最短路径长度
	cin >> v0; 
	//初始化
	int n = G.vexnum;
//	int locv = LocateVex(G, v0);//定位v0的下标
	for (int i = 1; i <= n; i++)
	{
		S[i] = false;//初始最短路径都未确定
		D[i] = G.arcs[v0][i];//其余节点到起点的初始路径长度，有边的是边权，无边的是无穷
		if (D[i] < MaxInt)//v0和vi之间有边，vi的前驱置为v0
			Path[i] = v0;
		else
			Path[i] = -1;
	}
	S[v0] = true;//设置第一个结点 
	D[v0] = 0;
	int v;//用来记录每次循环选出的点的标号
	for (int i = 1; i <= n; i++)//先选出来再进行对比更新 
	{
		int min = MaxInt;//默认从0号开始 
		for (int w = 1; w <= n; w++)//起点不一定是第一个，可用求余循环？ 
		{
			if (!S[w] && D[w] < min)//该点未被选中过，并且有边，第一次就选到了起点 
			{
				v = w;
				min = D[w];
			}
		}
		S[v] = true;//被选中 
			for (int w = 1; w <= n; w++)//更新每一个点当前最短路径的长度 
			{
				if (!S[w] && D[v] + G.arcs[v][w] < D[w])//如果到被选中的点有边且
														//通过这条路径长度变小 
				{
					D[w] = D[v] + G.arcs[v][w];// 更新路径长度以及前驱结点 
					Path[w] = v;
				}
			}	
	}
	int max=D[1];
	int maxv=1;
	for(int i = 1;i <= n; i++)
	{
		if(D[i]>max&&D[i]<MaxInt)
		{
			max=D[i];
			maxv=i;	
		}
	}
	cout<<maxv<<endl;
	cout<<max<<endl; 
}
int main()
{
	AMGragh  G;
	while (1)
	{
		cin >> G.vexnum >> G.arcnum;
		if (G.vexnum == 0 && G.arcnum == 0)
			return 0;
		CreateUDN(G);
		DIJ(G);
	}
}
