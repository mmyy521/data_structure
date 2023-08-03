#include<iostream>
using namespace std;
#define MaxInt 32767
#define MVNum 100
typedef struct
{
	char vexs[MVNum];//�����
	int arcs[MVNum][MVNum];//�ڽӾ���
	int vexnum, arcnum;//ͼ�ĵ�ǰ�����ͱ���
}AMGragh;
int LocateVex(AMGragh G, char v)
{
	for(int i=0;i<G.vexnum;i++)
		if (G.vexs[i] == v)
		{
			return i;
		}
}
void CreateUDN(AMGragh &G)//�����ڽӾ��� 
{
	char v1, v2;
	int w;
	for (int i = 0; i < G.vexnum; i++)//�������
		cin >> G.vexs[i];
	for (int i = 0; i < G.vexnum; i++)//��ʼ������
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j] = MaxInt;//��Ϊ���� 
		}
	}
	int n, m;
	for (int i = 0; i < G.arcnum; i++)//�������
	{
		cin >> v1 >> v2>>w;
		m = LocateVex(G, v1);
		n = LocateVex(G, v2);
		G.arcs[m][n] = w;//����Ļ��Գ� 
		G.arcs[n][m] = w;
	}//���������
}
void CoutPath(int D[], int Path[], AMGragh G,int locv,int t)
{
	if (Path[t] == locv)
		cout << G.vexs[locv]<<" ";
	else
	{
		CoutPath(D, Path, G, locv, Path[t]);
		cout << G.vexs[Path[t]]<<" ";
	}
}
//
void DIJ(AMGragh G)
{
	char v0, v1;
	bool S[MVNum];//��¼v0~vi�Ƿ�ȷ�����·��
	int Path[MVNum];//��¼v0~viֱ��ǰ��
	int D[MVNum];//��¼���·������
	cin >> v0 >> v1;
	//��ʼ��
	int n = G.vexnum;
	int locv = LocateVex(G, v0);//��λv0���±�
	for (int i = 0; i < n; i++)
	{
		S[i] = false;//��ʼ���·����δȷ��
		D[i] = G.arcs[locv][i];//����ڵ㵽���ĳ�ʼ·�����ȣ��бߵ��Ǳ�Ȩ���ޱߵ�������
		if (D[i] < MaxInt)//v0��vi֮���бߣ�vi��ǰ����Ϊv0
			Path[i] = locv;
		else
			Path[i] = -1;
	}
	S[locv] = true;//���õ�һ����� 
	D[locv] = 0;
	int v;//������¼ÿ��ѭ��ѡ���ĵ�ı��
	for (int i = 0; i < n; i++)//��ѡ�����ٽ��жԱȸ��� 
	{
		int min = MaxInt;//Ĭ�ϴ�0�ſ�ʼ 
		for (int w = 0; w < n; w++)//��㲻һ���ǵ�һ������������ѭ���� 
		{
			if (!S[w] && D[w] < min)//�õ�δ��ѡ�й��������бߣ���һ�ξ�ѡ������� 
			{
				v = w;
				min = D[w];
			}
		}
		S[v] = true;//��ѡ�� 
			for (int w = 0; w < n; w++)//����ÿһ���㵱ǰ���·���ĳ��� 
			{
				if (!S[w] && D[v] + G.arcs[v][w] < D[w])//�������ѡ�еĵ��б���
														//ͨ������·�����ȱ�С 
				{
					D[w] = D[v] + G.arcs[v][w];// ����·�������Լ�ǰ����� 
					Path[w] = v;
				}
			}	
	}
	int locv1 = LocateVex(G, v1);
	cout << D[locv1] << endl;
	CoutPath(D, Path, G,locv,locv1);
	cout << v1 << endl;
	/*
	int t = locv1;
	cout << t << " ";
	while (Path[t] != locv)
	{
		cout << Path[t]<<" ";
		t = Path[t];
	}
	cout << locv << endl;*/
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
