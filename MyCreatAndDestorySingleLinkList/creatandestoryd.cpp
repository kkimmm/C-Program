#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

//尾插法建立单链表
Node *PreCreat()
{
	Node *head, *p;
	head = new Node();
	p = head;

	int x, c = 1;

	while (c)
	{
		cout << "input a number for creat link list, press 0 to end:";
		cin >> x;
		if (x != 0)
		{
			Node *s = new Node();

			s->data = x;
			p->next = s;
			p = s;
		}
		else
		{
			c = 0;
			cout << "input done!" << endl;
		}
		
	}
	
	
	head = head->next;
	p->next = NULL;

	return head;
}

//头插法建立单链表
Node *BehCreat()
{
	Node *head;
	head = new Node();
	head->next = NULL;

	int x, c = 1;

	while (c)
	{
		cout << "input a number for creat link list, press 0 to end:";
		cin >> x;
		if (x != 0)
		{
			Node *s = new Node();
			s->data = x;
			s->next = head->next;
			head->next = s;
			
		}
		else
		{
			c = 0;
			cout << "input done!" << endl;
		}

	}


	head = head->next;
	

	return head;
}


void DelList(Node *head)
{
	Node *p, *q;
	p = head->next;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	head->next = NULL;
}


void ShowList(Node *head)
{
	Node *p;
	p = head;
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;		
	}

}

int main()
{
	//Node *head = PreCreat();//头插法创建单链表
	Node *head = BehCreat();//尾插法创建单链表
	cout << "the link list is:";
	ShowList(head);
	cout << endl;

	DelList(head);
	cout << "after delete the link list is:";//由于前面创建的时候，头节点指向的是第一个节点，而这里删除的时候是保留了头节点的，因此第一个节点数据并不会被删除
	ShowList(head);
	cout << endl;


	return 0;
}