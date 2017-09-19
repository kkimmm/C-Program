#include<iostream>  
using namespace std;

/*�ڽӾ�������Ͷ���*/
#define MAX 10000000  
#define MAX_VERTEX_NUM 20  
typedef struct
{
	char vexs[MAX_VERTEX_NUM];//��һά����洢������Ϣ  
	int edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�ö�ά����䵱�������洢����ߵ���Ϣ  
	int x, y;//�������ͱ���  
}MGraph;

/*��������ͼ���ڽӾ���*/
void CreateUDG_AM(MGraph &G, int n, int e)
{
	G.x = n;
	G.y = e;

	int i, j, k;
	cout << "������6���ڵ�:" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> G.vexs[i];//���붥����Ϣ 		
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			G.edges[i][j] = 0;//�������ʼ��Ϊ0  		
		}
	}

	for (k = 0; k<e; k++)
	{
		cout << "������߶�Ӧ�������ڵ�(ע���Ǵ�0��ʼ):";
		cin >> i >> j;//����ֻ������ԳƵı߾��У�Ҳ���������¾�������Ͼ���  
		G.edges[i][j] = G.edges[j][i] = 1;//����ߵ���Ϣ  
	}

}

int visited[MAX_VERTEX_NUM];
const int Queue_Size = 100;

//ʹ�ö��н��й�ȱ������ȶ�����У�ѭ����
typedef struct circlQueue
{
	int *elem;
	int rear;
	int front;
	int queueSize;
}circlQueue;

//��ʼ��  
void initQueue_C(circlQueue &Q)
{
	Q.elem = new int[Queue_Size];
	Q.front = Q.rear = 0;//��βָ�����˵������Ϊ�ա�  
	Q.queueSize = Queue_Size;
}

//�����  
void enterQueue_C(circlQueue &Q, int x)
{
	if (((Q.rear + 1) % Q.queueSize) == Q.front)//�ж�ջ�������  
		cout << "Queue OverFlow!";
	Q.elem[Q.rear] = x;
	Q.rear = (Q.rear + 1) % Queue_Size;//βָ��Ӧ�Դ��ַ�ʽ��1���Ż�ʵ��ѭ�����С�  
}

//������  
char outputQueue_C(circlQueue &Q)
{
	int e;
	if (Q.rear == Q.front)
		cout << "Queue Empty";
	e = Q.elem[Q.front];
	Q.front = (Q.front + 1) % Q.queueSize;;//ͷָ��Ӧ�Դ��ַ�ʽ��1���Ż�ʵ��ѭ�����С�  
	return e;
}

//��ȱ���  
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
			{//���ѭ���ǽ���������Ķ���ȡ������Ȼ����������forѭ��  
				v = outputQueue_C(Q);
				for (j = 0; j<G.x; j++)
				{//���ѭ���ǽ������ȫ���ڽӵ����η��ʲ��������  
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
	cout << "������ȱ���˳��Ϊ��";
	BF_Traverse_AM(G);
	cout << endl;
	return 0;
}
