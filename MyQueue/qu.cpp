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

//创建一个空的队列
void InitQueue(LinkQueue &Q)
{
	QNode *q = new QNode;
	q->next = NULL;
	Q.front = q;
	Q.rear = q;
}



//入队列
void EnQueue(LinkQueue &Q, double e)
{
	QNode *p = new QNode;
	p->next = NULL;
	p->data = e;
	Q.rear->next = p;
	Q.rear = p;	
}

//出队列，按照队列的原则：fist in fist out，因此应该是从对首开始出队列
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

//显示队列
void ShowQueue(LinkQueue Q)
{
	QNode *p;
	p = Q.front->next;//指向队头的下一个，即第一个数据元素
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
	LinkQueue *Q = new LinkQueue;  //定义一个队列Q
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
	/*由于此处销毁了队列之后只保存了Q.front,如果使用前面的ShowqQueue()调用的话会出现问题*/
	/*因为 p = Q.front->next;这里Q.front并没有next可以指向，因此需要稍微修改*/
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