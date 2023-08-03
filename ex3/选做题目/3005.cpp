#include<iostream>
using namespace std;
typedef struct BiNode
{
    char data;
    struct  BiNode* lchild, * rchild; //左右孩子指针
}BiNode, * BiTree;
void CreateBiTree(BiTree& T)
{
    char ch;
    cin >> ch;
    if (ch == '0')//递归结束，建空树
        T = NULL;  
    else 
    {
        T = new BiNode;    
        T->data = ch;                                  	//生成根结点
        CreateBiTree(T->lchild);  //递归创建左子树
        CreateBiTree(T->rchild); //递归创建右子树
    }
}


int Width(BiTree T)
{
    if (T == NULL)
        return 0;
    else
    {
        BiTree Q[100],p;//队列指针
        int front = 1;//队头
        int rear = 1;//队尾
        int last = 1;//同一层最右面的结点在队列里的标号
        int temp = 0;//当前宽度
        int maxw = 0;//最大宽度
        Q[rear] = T;//队尾等于根节点
        while (front <= last)//在front没有加到rear的时候不停循环 
        {
            p = Q[front++];//front=1，Q[1]=T，p=T，分支节点就是队头结点
            temp++;
            if (p->lchild != NULL)//当前层入队
                Q[++rear] = p->lchild;
            if (p->rchild != NULL)
                Q[++rear] = p->rchild;
            if (front > last)//队头的标号比遍历完的一层最右面标号大，就把最右更新一下 
            {
                last = rear;//更新最右面结点的标号为队尾标号
                if (temp > maxw)//更新temp，temp计数记的是遍历完的上上层数，数目 
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
