#include <iostream>
using namespace std;

//����ڵ����ʽ
struct Node
{
	int data;
	Node *next; //�ýṹ����Node����һ���ڲ�ָ�루������ϵ int *p��
};

Node *Creat()
{
	//����ͷ���
	Node *head, *p;//����������ָ��*head��*p
	head = new Node;//����һ���ڵ㲢��headָ��ýڵ㣬���Ľڵ�����ͷ���
	p = head;//pҲָ���˸ýڵ�


	//����ͷ����̵Ľڵ㣬������������һ��������
	int x, c = 1;
	while (c)
	{
		cout << "please input a number for creating a link list ,press 0 to end" << endl;
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

	head = head->next;//ȥ��ͷ�ڵ㣬������ʾ��ʱ���ֻ��ʾһ����ͷ�ڵ�ĵ����������ӡ�������ӡͷ�ڵ�Ļ�������ͷ�ڵ�û�и�ֵ��һ���������ĵ�ַ
	p->next = NULL;
	return head;

}

//��ӡ����



//����ڵ��������������
void Len(Node *head)
{
	int k=0;
	Node *p = head;
	while (p != NULL)
	{
		p = p->next;
		k++;
	}
	cout << k;
}

void HasLoop(Node *head)
{
	Node *fast, *slow;
	int step1 = 1;
	int step2 = 2;
	fast = head;
	slow = head;
	while(fast!=NULL&&fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
		{
			return;
		}
	}


}

//������ת�������ڴ����������ʱ��ͷ�ڵ�ָ���˵�һ���ڵ㣬��˰������ַ�����תʱ���Ὣ��һ���ڵ㵱��ͷ�ڵ�Դ�������һ���ڵ㲻��䶯��
void Reverse(Node *head)
{
	Node *p1, *p2, *p3;
	p1 = head->next;
	p2 = p1->next;
	p1->next = NULL;
	
	while (p2 != NULL)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;

	}

	head->next = p1;
}


//��O(n/2)ʱ���ڻ�������м�λ�õ����ݣ�˼·�����ÿ�������ָ�룬����һ����ָ��ָ����βʱ���ڶ�����ָ��պ�ָ�������в�
void GetMidNod(Node *head)
{
	Node *p1, *p2;
	p1 = head;
	p2 = head;
	while (p1->next != NULL)
	{
		if (p1->next->next != NULL)
		{
			p1 = p1->next->next;
			p2 = p2->next;
		}
		else
		{
			p1 = p1->next;
		}
		
	}

	cout << "the middle data of the link list is:" << p2->data << endl;
}


//��ͷ��β��ӡ������
void RPrintList(Node *head)
{
	if (head == NULL)
	{
		return;
	}
	else
	{
		RPrintList(head->next);
		cout << head->data;
	}
}

//��ȡĳ��λ�õ�����
Node *GetElem(Node *head,int i)
{
	Node *p;
	p = head;
	int k = 1;
	while (p != NULL && k < i)
	{
		p = p->next;
		k++;
	}
	cout << p->data;
	cout << endl;
	return head;
}


//��ĳ��λ�ò��봫�������
Node *InsertElem(Node *head, int i,int j)
{
	Node *p;
	p = head;
	int k = 1;
	while (p!=NULL && k<i-1)
	{
		p = p->next;
		k++;
	}

	Node *s;
	s = new Node;
	s->data = j;

	s->next = p->next;
	p->next = s;

	return head;
}

//ɾ��ĳ��λ�õ�����
Node *DelElem(Node *head, int i)
{
	Node *p;
	p = head;
	int k = 1;
	while (p ->next!=NULL && k <i-1)
	{
		p = p->next;
		k++;
	}

	p->next=p->next->next;

	return head;
}

void printl(Node *head)
{
	Node *p = head;
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
}

void Destory(Node *head)
{
	Node *p, *q;
	p = head;
	while (p!= NULL)
	{
		q = p;
		p = p->next;
		delete q;
	}
	head = NULL;
}

int main()
{
	int i, j;

	Node *head = Creat();//Creat�������ص���һ��ָ�루��ַ��������൱��Node *head = head(head��һ����ַ)
	printl(head);

	cout << "the length of the linklist is:";
	Len(head);
	cout << endl;

	HasLoop(head);

	Reverse(head);
	printl(head);

	GetMidNod(head);

	cout << "print the reverse of the list using recursion:";
	RPrintList(head);
	cout << endl;

	cout << "input a postion you want to get:";
	cin >> i;
	head = GetElem(head, i);
	printl(head);


	cout << "input a position you want to insert:";
	cin >>i;
	cout << "input a number you want to insert:";
	cin >> j;
	head = InsertElem(head, i,j);
	printl(head);

	cout << "input the position you want to delet:";
	cin >> i;
	head = DelElem(head, i);
	printl(head);

	cout << "b";
	Destory(head);//��ȫ�����˴��������� ������ʹ��printl(head)��	
	cout << "a";
	return 0;
}