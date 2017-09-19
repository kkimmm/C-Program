/* ͼ�Ĵ洢������*/
#include<iostream>  
using namespace std;
//-----------------------------------  
//�ڽӾ���Ĵ洢����Ⱥ͹�ȱ���  
//-----------------------------------  

/*�ڽӾ�������Ͷ���*/
#define MAX 10000000  
#define MAX_VERTEX_NUM 20  
typedef enum{ DG, DN, UDG, UDN }GraphKind;//����ͼ��������������ͼ��������  
typedef struct
{
	char vexs[MAX_VERTEX_NUM];//��һά����洢������Ϣ  
	int edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�ö�ά����䵱�������洢����ߵ���Ϣ  
	int x, y;//�������ͱ���  
	GraphKind kind;//ͼ������  
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


//����ͼ��������ȱ���
int visited[MAX_VERTEX_NUM];

void DF_AM(MGraph &G, int i)//��ȱ�������
{
	int j;
	cout << G.vexs[i] << " ";
	visited[i] = 1;//��Ǹö����Ѿ���������
	for (j = 0; j<G.x; j++)//ѭ��������������
	{
		if ((G.edges[i][j]) == 1 && (visited[j]) == 0)//�ý��������������������δ��������
			DF_AM(G, j);
	}
}

void DF_Traverse_AM(MGraph &G)//������ȱ���
{
	int i;	
	for (i = 0; i<G.x; i++)//G.x=6
	{
		visited[i] = 0;
	}
	for (i = 0; i<G.y; i++)
	{
		if (!visited[i])//��δ������
			DF_AM(G, i);//����һ��
	}
}



int  main()
{
	MGraph G;
	CreateUDG_AM(G,6,6);
	DF_Traverse_AM(G);
	cout<<endl;	
	BF_Traverse_AM(G);
}