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

void travelthreadtree(Binode *&H)     //������������� ��ͷ�ڵ�(�½�����ͷ�ڵ㲢����ԭ����������ͷ�ڵ�)��ʼ
{
	Binode *p;
	p = H->lchild;                     //pΪ������ͷ�ڵ�
	while (p != H)
	{
		while (p->ltag == 0)            //�������� �� һֱ����
			p = p->lchild;
		cout<< p->data;
		while (p->rtag == 1 && p->rchild != H)  //������������һֱ�������
		{
			p = p->rchild;
			cout<<p->data;
		}
		p = p->rchild;                   //��û������ʱ ��ʾ��������
	}
}

void thread(Binode *&T)               //������
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
		pre = T;                    //˳���������� �ڵ� ��������������� ���� ������
		thread(T->rchild);
	}
}

void threading(Binode *&H, Binode *&T)  //����ͷ�ڵ�
{
	H = new Binode;
	H->rchild = H;
	H->rtag = 0;
	if (!T)                //������Ϊ��
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
		pre->rchild = H;    // ����ѭ��  �Ա�����
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
