#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next; //用结构体名Node创建一个内部指针（可以联系 int *p）
};

Node *Creat(int n)
{
	//创建头结点
	Node *head, *p;//创建了两个指针*head和*p
	head = new Node;//创建一个节点并用head指向该节点，即改节点变成了头结点
	p = head;//p也指向了该节点


	int i=1,x;
	while (i<=n)
	{								
			Node *s;
			s = new Node;
			s->data = i;
			p->next = s;
			p = s;	
			i++;
	}	
	p->next = head;
	return head;

}


//打印链表
void printl(Node *head)
{
	Node *p;
	p = head;
	cout << "the single link list is:";
	while (p ->next!= head)
	{
		p = p->next;
		cout << p->data;
		
	}
	cout << endl;
}


int main()
{
	
	int n = 41, m = 3;;
	Node *h = Creat(n);
	printl(h);
	
	m %= n;

	while (h->next != h)
	{
		for (int i = 1; i <m; i++)
		{
			h = h->next;
		}


		cout <<"->"<< h->next->data;
		
		h->next = h->next->next;
		h = h->next;
	}
		
	return 0;
}