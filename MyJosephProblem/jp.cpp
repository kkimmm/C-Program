#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next; //�ýṹ����Node����һ���ڲ�ָ�루������ϵ int *p��
};

Node *Creat(int n)
{
	//����ͷ���
	Node *head, *p;//����������ָ��*head��*p
	head = new Node;//����һ���ڵ㲢��headָ��ýڵ㣬���Ľڵ�����ͷ���
	p = head;//pҲָ���˸ýڵ�


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


//��ӡ����
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