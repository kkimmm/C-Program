#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

//创建单向循环链表
Node *Creat()
{
	Node *head, *p;
	head = new Node;
	p = head;
	
	int x, c = 1;
	
	while (c)
	{
		cout << "input a number for creatting a circular link list:";
		cin >> x;
		if (x != 0)
		{
			Node *s;
			s = new Node;
			s->data = x;
			p->next = s;
			p = s;
		}
		else
		{
			c = 0;
			cout << "input done" << endl;
		}
	}

	p->next = head;

	return head;

}


//在某个位置插入某个值
Node *InerstElem(Node *head, int i, int j)
{
	Node *p;
	p = head;
	for (int k = 0; k < i - 1; k++)
	{
		p = p->next;
	}


	Node *s = new Node();
	s->data = j;
	s->next = p -> next;
	p->next=s;

	return head;

}

//打印链表
void ShowList(Node *head)
{
	Node *p;
	p = head;
	while (p->next!=head)
	{
		p=p->next;
		cout << p->data;
	}
}

//合并两个链表，注意由于再创建着两个循环链表时是带头节点的，所以要注意处理掉第二个链表的头节点，不然就会有一个未赋值的数据会被打印出来（实际上就是那个头节点）
Node *UnintList(Node*head, Node*head2)
{
	Node *x, *y,*temp;
	x = head;
	while (x->next != head)
	{
		x = x->next;		
	}
	
	temp = head2;
	x->next = head2->next;

	y = head2;
	while (y->next != head2)
	{
		y = y->next;
	}	
	free(temp);
	y->next = head;

	return head;
}

int main()
{
	Node *head = Creat();
	cout << "the circular link list is:";
	ShowList(head);
	cout << endl;

	int i, j;
	cout << "input the position you want to insert:";
	cin >> i;
	cout << "input the number you want to insert:";
	cin >> j;
	head = InerstElem(head, i, j);
	cout << "after insert the circular link list is:";
	ShowList(head);
	cout << endl;

	//删除等操作大同小异，不再累述


	Node *head2 = Creat();
	cout << "the circular link list 2 is:";
	ShowList(head2);
	cout << endl;
	UnintList(head, head2);
	cout << "after unite the link list is:";
	ShowList(head);
	cout << endl;
	
	return 0;

}