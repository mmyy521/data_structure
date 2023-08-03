#include<iostream>
using namespace std;
#define MaxInt 32767
#define MVNum 100
typedef struct
{
	int vexs[MVNum];//�����
	int arcs[MVNum][MVNum];//�ڽӾ���
	int vexnum, arcnum;//ͼ�ĵ�ǰ�����ͱ���
}AMGragh;
void CreateUDN(AMGragh &G)//�����ڽӾ��� 
{
	int v1, v2;
	int w;
	for (int i = 1; i <= G.vexnum; i++)//�������
		G.vexs[i]=i;
	for (int i = 1; i <= G.vexnum; i++)//��ʼ������
	{
		for (int j = 1; j <= G.vexnum; j++)
		{
			G.arcs[i][j] = MaxInt;//��Ϊ���� 
		}
	}
	int n, m;
	for (int i = 0; i < G.arcnum; i++)//�������
	{
		cin >> v1 >> v2>> w;
		G.arcs[v1][v2] = w;//����Ļ��Գ� 
		G.arcs[v2][v1] = w;
	}//���������
}

//
void DIJ(AMGragh G)
{
	int v0;
	bool S[MVNum];//��¼v0~vi�Ƿ�ȷ�����·��
	int Path[MVNum];//��¼v0~viֱ��ǰ��
	int D[MVNum];//��¼���·������
	cin >> v0; 
	//��ʼ��
	int n = G.vexnum;
//	int locv = LocateVex(G, v0);//��λv0���±�
	for (int i = 1; i <= n; i++)
	{
		S[i] = false;//��ʼ���·����δȷ��
		D[i] = G.arcs[v0][i];//����ڵ㵽���ĳ�ʼ·�����ȣ��бߵ��Ǳ�Ȩ���ޱߵ�������
		if (D[i] < MaxInt)//v0��vi֮���бߣ�vi��ǰ����Ϊv0
			Path[i] = v0;
		else
			Path[i] = -1;
	}
	S[v0] = true;//���õ�һ����� 
	D[v0] = 0;
	int v;//������¼ÿ��ѭ��ѡ���ĵ�ı��
	for (int i = 1; i <= n; i++)//��ѡ�����ٽ��жԱȸ��� 
	{
		int min = MaxInt;//Ĭ�ϴ�0�ſ�ʼ 
		for (int w = 1; w <= n; w++)//��㲻һ���ǵ�һ������������ѭ���� 
		{
			if (!S[w] && D[w] < min)//�õ�δ��ѡ�й��������бߣ���һ�ξ�ѡ������� 
			{
				v = w;
				min = D[w];
			}
		}
		S[v] = true;//��ѡ�� 
			for (int w = 1; w <= n; w++)//����ÿһ���㵱ǰ���·���ĳ��� 
			{
				if (!S[w] && D[v] + G.arcs[v][w] < D[w])//�������ѡ�еĵ��б���
														//ͨ������·�����ȱ�С 
				{
					D[w] = D[v] + G.arcs[v][w];// ����·�������Լ�ǰ����� 
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
