#include<iostream>
using namespace std;
typedef struct BiNode
{
    char data;
    struct  BiNode* lchild, * rchild; //���Һ���ָ��
}BiNode, * BiTree;
void CreateBiTree(BiTree& T)
{
    char ch;
    cin >> ch;
    if (ch == '0')//�ݹ������������
        T = NULL;  
    else 
    {
        T = new BiNode;    
        T->data = ch;                                  	//���ɸ����
        CreateBiTree(T->lchild);  //�ݹ鴴��������
        CreateBiTree(T->rchild); //�ݹ鴴��������
    }
}


int Width(BiTree T)
{
    if (T == NULL)
        return 0;
    else
    {
        BiTree Q[100],p;//����ָ��
        int front = 1;//��ͷ
        int rear = 1;//��β
        int last = 1;//ͬһ��������Ľ���ڶ�����ı��
        int temp = 0;//��ǰ���
        int maxw = 0;//�����
        Q[rear] = T;//��β���ڸ��ڵ�
        while (front <= last)//��frontû�мӵ�rear��ʱ��ͣѭ�� 
        {
            p = Q[front++];//front=1��Q[1]=T��p=T����֧�ڵ���Ƕ�ͷ���
            temp++;
            if (p->lchild != NULL)//��ǰ�����
                Q[++rear] = p->lchild;
            if (p->rchild != NULL)
                Q[++rear] = p->rchild;
            if (front > last)//��ͷ�ı�űȱ������һ���������Ŵ󣬾Ͱ����Ҹ���һ�� 
            {
                last = rear;//������������ı��Ϊ��β���
                if (temp > maxw)//����temp��temp�����ǵ��Ǳ���������ϲ�������Ŀ 
                    maxw = temp;
                temp = 0;
            }
        }
        return maxw;
    }
}
int main()
{
    BiTree Tree1,Tree2;
    while(1)
    {
        CreateBiTree(Tree1);
        if (Tree1 == NULL)
            return 0;
        int n = Width(Tree1);
        cout << n<<endl;
    }
    

}
