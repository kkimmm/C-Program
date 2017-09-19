#include<iostream>
using namespace std;

typedef struct Binode
{
	char data;
	Binode *lchild, *rchild;
	int ltag, rtag;
};
Binode *pre;
void CreatTREE(Binode *&T)
{
	char ch;
	ch = getchar();
	if (ch == '#')
	{
		T = NULL;
	}
	else
	{
		T = new Binode;
		T->data = ch;
		T->ltag = 0;
		T->rtag = 0;
		CreatTREE(T->lchild);
		CreatTREE(T->rchild);
	}

}

void travelthreadtree(Binode *&H)     //中序遍历线索树 从头节点(新建立的头节点并不是原来二叉树的头节点)开始
{
	Binode *p;
	p = H->lchild;                     //p为二叉树头节点
	while (p != H)
	{
		while (p->ltag == 0)            //有左子树 则 一直往下
			p = p->lchild;
		cout<< p->data;
		while (p->rtag == 1 && p->rchild != H)  //根据它的线索一直往后输出
		{
			p = p->rchild;
			cout<<p->data;
		}
		p = p->rchild;                   //当没有线索时 表示有右子树
	}
}

void thread(Binode *&T)               //线索化
{
	if (T)
	{
		thread(T->lchild);
		if (!T->lchild)
		{
			T->ltag = 1;
			T->lchild = pre;
		}
		if (!pre->rchild)
		{
			pre->rtag = 1;
			pre->rchild = T;
		}
		pre = T;                    //顺序是左子树 节点 右子树的中序遍历 所有 放这里
		thread(T->rchild);
	}
}

void threading(Binode *&H, Binode *&T)  //新增头节点
{
	H = new Binode;
	H->rchild = H;
	H->rtag = 0;
	if (!T)                //二叉树为空
	{
		H->lchild = H;
		H->ltag = 0;
	}
	else
	{
		pre = H;
		H->lchild = T;
		H->ltag = 0;
		thread(T);
		H->rtag = 1;
		H->rchild = pre;   //
		pre->rchild = H;    // 构成循环  以备跳出
	}	
}



int main()
{
	Binode *T, *H;
	CreatTREE(T);
	threading(H, T);
	travelthreadtree(H);
	return 0;
}
