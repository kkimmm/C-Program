#include <iostream>
using namespace std;

//定义节点的形式
struct Node
{
	int data;
	Node *next; //用结构体名Node创建一个内部指针（可以联系 int *p）
};

Node *Creat()
{
	//创建头结点
	Node *head, *p;//创建了两个指针*head和*p
	head = new Node;//创建一个节点并用head指向该节点，即改节点变成了头结点
	p = head;//p也指向了该节点


	//创建头结点后继的节点，并将他们连成一条单链表
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

	head = head->next;//去掉头节点，这样显示的时候就只显示一个无头节点的单链表，方便打印；否则打印头节点的话，由于头节点没有赋值是一个随机分配的地址
	p->next = NULL;
	return head;

}

//打印链表



//计算节点个数，即链表长度
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

//单链表反转。由于在创建单链表的时候将头节点指向了第一个节点，因此按照这种方法逆转时，会将第一个节点当成头节点对待，即第一个节点不会变动。
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


//在O(n/2)时间内获得链表中间位置的数据，思路是设置快慢两个指针，当第一个快指针指向链尾时，第二个慢指针刚好指向链表中部
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


//从头到尾打印单链表
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

//获取某个位置的数据
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


//在某个位置插入传入的数据
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

//删除某个位置的数据
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

	Node *head = Creat();//Creat函数返回的是一个指针（地址），因此相当于Node *head = head(head是一个地址)
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
	Destory(head);//完全销毁了创建的链表， 不能再使用printl(head)了	
	cout << "a";
	return 0;
}