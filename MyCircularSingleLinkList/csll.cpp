#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

//��������ѭ������
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


//��ĳ��λ�ò���ĳ��ֵ
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

//��ӡ����
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

//�ϲ���������ע�������ٴ���������ѭ������ʱ�Ǵ�ͷ�ڵ�ģ�����Ҫע�⴦����ڶ��������ͷ�ڵ㣬��Ȼ�ͻ���һ��δ��ֵ�����ݻᱻ��ӡ������ʵ���Ͼ����Ǹ�ͷ�ڵ㣩
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

	//ɾ���Ȳ�����ͬС�죬��������


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