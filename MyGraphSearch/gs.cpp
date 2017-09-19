/* 图的存储及遍历*/
#include<iostream>  
using namespace std;
//-----------------------------------  
//邻接矩阵的存储及深度和广度遍历  
//-----------------------------------  

/*邻接矩阵的类型定义*/
#define MAX 10000000  
#define MAX_VERTEX_NUM 20  
typedef enum{ DG, DN, UDG, UDN }GraphKind;//有向图，有向网，无向图，无向网  
typedef struct
{
	char vexs[MAX_VERTEX_NUM];//用一维数组存储顶点信息  
	int edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//用二维数组充当矩阵，来存储顶点边的信息  
	int x, y;//顶点树和边数  
	GraphKind kind;//图的种类  
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


//无向图的深度优先遍历
int visited[MAX_VERTEX_NUM];

void DF_AM(MGraph &G, int i)//深度遍历函数
{
	int j;
	cout << G.vexs[i] << " ";
	visited[i] = 1;//标记该顶点已经被遍历过
	for (j = 0; j<G.x; j++)//循环遍历其它顶点
	{
		if ((G.edges[i][j]) == 1 && (visited[j]) == 0)//该结点有相连的其它顶点且未被遍历且
			DF_AM(G, j);
	}
}

void DF_Traverse_AM(MGraph &G)//深度优先遍历
{
	int i;	
	for (i = 0; i<G.x; i++)//G.x=6
	{
		visited[i] = 0;
	}
	for (i = 0; i<G.y; i++)
	{
		if (!visited[i])//若未被遍历
			DF_AM(G, i);//遍历一下
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