#include<iostream>  
using namespace std;

/*邻接矩阵的类型定义*/
#define MAX 10000000  
#define MAX_VERTEX_NUM 20  
typedef struct
{
	char vexs[MAX_VERTEX_NUM];//用一维数组存储顶点信息  
	int edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//用二维数组充当矩阵，来存储顶点边的信息  
	int x, y;//顶点树和边数  
}MGraph;

/*构造无向图的邻接矩阵*/
void CreateUDG_AM(MGraph &G, int n, int e)
{
	G.x = n;
	G.y = e;

	int i, j, k;
	cout << "请输入6个节点:" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> G.vexs[i];//输入顶点信息 		
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			G.edges[i][j] = 0;//将矩阵初始化为0  		
		}
	}

	for (k = 0; k<e; k++)
	{
		cout << "请输入边对应的两个节点(注意是从0开始):";
		cin >> i >> j;//这里只用输入对称的边就行，也就是输入下矩阵或是上矩阵  
		G.edges[i][j] = G.edges[j][i] = 1;//输入边的信息  
	}

}

int visited[MAX_VERTEX_NUM];
const int Queue_Size = 100;

//使用队列进行广度遍历，先定义队列（循环）
typedef struct circlQueue
{
	int *elem;
	int rear;
	int front;
	int queueSize;
}circlQueue;

//初始化  
void initQueue_C(circlQueue &Q)
{
	Q.elem = new int[Queue_Size];
	Q.front = Q.rear = 0;//首尾指针相等说明队列为空。  
	Q.queueSize = Queue_Size;
}

//入队列  
void enterQueue_C(circlQueue &Q, int x)
{
	if (((Q.rear + 1) % Q.queueSize) == Q.front)//判断栈满的情况  
		cout << "Queue OverFlow!";
	Q.elem[Q.rear] = x;
	Q.rear = (Q.rear + 1) % Queue_Size;//尾指针应以此种方式加1，才会实现循环队列。  
}

//出队列  
char outputQueue_C(circlQueue &Q)
{
	int e;
	if (Q.rear == Q.front)
		cout << "Queue Empty";
	e = Q.elem[Q.front];
	Q.front = (Q.front + 1) % Q.queueSize;;//头指针应以此种方式加1，才会实现循环队列。  
	return e;
}

//广度遍历  
void BF_Traverse_AM(MGraph &G)
{
	int i, j, v;
	for (i = 0; i<G.x; i++)
		visited[i] = 0;
	circlQueue Q;
	initQueue_C(Q);
	for (i = 0; i<G.x; i++)
	{
		if (!visited[i])
		{
			cout << G.vexs[i] << " ";
			visited[i] = 1;
			enterQueue_C(Q, i);
			while (Q.front != Q.rear)
			{//这个循环是将队列里面的顶点取出来，然后进行下面的for循环  
				v = outputQueue_C(Q);
				for (j = 0; j<G.x; j++)
				{//这个循环是将顶点的全部邻接点依次访问并且入队列  
					if (G.edges[v][j] && (!visited[j]))
					{
						cout << G.vexs[j] << " ";
						visited[j] = 1;
						enterQueue_C(Q, j);
					}
				}
			}
		}
	}
}

int  main()
{
	MGraph G;
	CreateUDG_AM(G, 6, 6);	
	cout << "广度优先遍历顺序为：";
	BF_Traverse_AM(G);
	cout << endl;
	return 0;
}
