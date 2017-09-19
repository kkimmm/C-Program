#include <iostream>
using namespace std;
#define MAXSIZE 200

struct CirculQueue
{
	int data[MAXSIZE];
	int fornt, rear;
}C;

void InitQueue(CirculQueue &C)
{
	//C.base = (int*)malloc(MAXSIZE*sizeof(int));
	C.fornt = C.rear = 0;
}


void InsertQueue(CirculQueue &C,int i)
{
	if ((C.rear + 1) % MAXSIZE == C.fornt)
	{
		cout << "the queue is full!";
	}
	else
	{
		C.data[C.rear] = i;		
		C.rear = (C.rear + 1) % MAXSIZE;
		
	}
}

void DelQueue(CirculQueue &C)
{
	if (C.rear == C.fornt)
	{
		cout << "the queue is empty!";
	}
	else
	{
		C.fornt = (C.fornt + 1) % MAXSIZE;
	}
}

void ShowQueue(CirculQueue &C)
{
	while ((C.fornt) % MAXSIZE != C.rear)
	{
		cout << C.data[C.fornt];
		C.fornt ++;
	}
		
}

int main()
{	
	InitQueue(C);
	
	for (int i =1; i <= 10; i++)
	{
		InsertQueue(C, i);
	}
	cout << "the circular queue is:" << endl;
	//ShowQueue(C); //���������ShowQueue()�е�front���õ�int��д�ģ�ÿ��ʹ��һ�ξͻὫfront�ı䣬���Ե�ǰ��ʹ�ù���֮���ı����Ľ����
	cout << endl;


	DelQueue(C);
	cout << "after delete the circular queue is:" << endl;
	ShowQueue(C);
	cout << endl;

	return 0;
}