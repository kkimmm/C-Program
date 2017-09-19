#include <iostream>
using namespace std;

struct QNode
{
	double data;
	QNode *next;
};
struct LinkQueue
{
	QNode *front;
	QNode *rear;
};

//����һ���յĶ���
void InitQueue(LinkQueue &Q)
{
	QNode *q = new QNode;
	q->next = NULL;
	Q.front = q;
	Q.rear = q;
}



//�����
void EnQueue(LinkQueue &Q, double e)
{
	QNode *p = new QNode;
	p->next = NULL;
	p->data = e;
	Q.rear->next = p;
	Q.rear = p;	
}

//�����У����ն��е�ԭ��fist in fist out�����Ӧ���ǴӶ��׿�ʼ������
void DelQueue(LinkQueue &Q, double e)
{
	QNode *p;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
	{
		Q.front = Q.front;
	}
	delete p;

}

//��ʾ����
void ShowQueue(LinkQueue Q)
{
	QNode *p;
	p = Q.front->next;//ָ���ͷ����һ��������һ������Ԫ��
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
}

void DestoryQueue(LinkQueue &Q)
{
	while (Q.front)
	{
		Q.rear = Q.front->next;
		delete Q.front;
		Q.front = Q.rear;
	}
}

int main()
{
	LinkQueue *Q = new LinkQueue;  //����һ������Q
	InitQueue(*Q);

	int i;
	for (i = 1; i <= 10; i++)
	{
		EnQueue(*Q, i);
	}
	cout << "now the queue is:";
	ShowQueue(*Q);
	cout << endl;
	
	int e=-1;
	DelQueue(*Q, e);
	//DelQueue(*Q, e);
	cout << "after delete the queue is:";
	ShowQueue(*Q);
	cout << endl;


	DestoryQueue(*Q);
	cout << "after destory the queue is:";
	/*���ڴ˴������˶���֮��ֻ������Q.front,���ʹ��ǰ���ShowqQueue()���õĻ����������*/
	/*��Ϊ p = Q.front->next;����Q.front��û��next����ָ�������Ҫ��΢�޸�*/
	QNode *p;
	p = Q->front;
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
	/**/
	cout << endl;


	return 0;
}