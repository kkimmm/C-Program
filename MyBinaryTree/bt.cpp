#include <iostream>
using namespace std;
struct BiNode
{
	char data;
	BiNode *lchild, *rchild;
};

void CreatBiTree(BiNode *&T)
{
	char ch;
	ch = getchar();
	if (ch== '#')//ע��ʹ��''������""
		T = NULL;
	else
	{
		T = new BiNode;
		T->data = ch;
		CreatBiTree(T->lchild);
		CreatBiTree(T->rchild);
	}
}

//�������
void PreOrderTraverse(BiNode *&T)
{
	if (T)
	{
		cout << T->data;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

//��������
void MidOrderTraverse(BiNode *&T)
{
	if (T)
	{		
		MidOrderTraverse(T->lchild);
		cout << T->data;
		MidOrderTraverse(T->rchild);
	}
}

//��������
void LastOrderTraverse(BiNode *&T)
{
	if (T)
	{
		LastOrderTraverse(T->lchild);
		LastOrderTraverse(T->rchild);
		cout << T->data;		
	}
}


int main()
{
	BiNode *T;
	cout << "please input a binary tree(using PreOrder), input # means null or leaf node" << endl;
	CreatBiTree(T);

	cout << "using PreOrder we have the binary tree:" << endl;
	PreOrderTraverse(T);
	cout << endl;

	cout << "using MidOrder we have the binary tree:" << endl;
	MidOrderTraverse(T);
	cout << endl;

	cout << "using LastOrder we have the binary tree:" << endl;
	LastOrderTraverse(T);
	cout << endl;
	return 0;
}