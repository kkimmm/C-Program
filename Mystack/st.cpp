
//实现的均是顺序栈

#include <iostream>
using namespace std;

#define STACK_INIT_SIZE 100 //初始分配空间大小
#define INCREMENTSIZE 10 //存储空间分配增量

struct SeqStack
{
	int *bottom;
	int *top;
	int size;
}s;


//创建一个空的栈
void InitStack(SeqStack &s) //&s表示引用
{
	s.bottom = (int*)malloc(STACK_INIT_SIZE*sizeof(int));
	s.top = s.bottom;
	s.size = STACK_INIT_SIZE;
}


//将传入的数据e入栈
void Push(SeqStack &s, int e)
{
	if (s.top - s.bottom >= s.size)
	{  //判断栈是否已满
		s.bottom = (int*)realloc(s.bottom, (s.size + INCREMENTSIZE)*sizeof(int));  //栈满则追加空间
		
		s.top = s.bottom + s.size;
		s.size += INCREMENTSIZE;
	}

	*(s.top) = e;
	s.top++;	
}


int StackLength(SeqStack s)
{
	return s.top - s.bottom;
}

//出栈
void Pop(SeqStack &s,int e)
{
	if (s.top ==s.bottom)
	{
		cout << "the stack is empty" << endl;
	}
	s.top--;
	e = *(s.top);
	cout <<"now the elem you pop is:"<< e<<endl;
}

//显示栈
void ShowStack(SeqStack s)
{
	if (s.bottom == NULL)
	{
		cout << "the stack is not exist";
	}
	for (int i = StackLength(s)-1; i >=0; i--)
	{
		cout << s.bottom[i] << endl;
	}
}

//清空栈
void ClearStack(SeqStack &s)
{
	s.top = s.bottom;
}

//销毁栈
void DestroyStack(SeqStack &s)
{
	free(s.bottom);
	s.bottom = s.top = NULL;//s.bottom的值为NULL，表示顺序栈不存在
	s.size = 0;	
}


int main()
{
	InitStack(s);
	int data[10];
	for (int i = 0; i<10; i++){
		data[i] = i;
		Push(s, data[i]);
	}
	cout << "now the stack we creat is:"<<endl;
	ShowStack(s);
	cout << endl;

	int e=0;
	Pop(s,e);
	cout << "after pop the stack is:" << endl;
	ShowStack(s);

	/*ClearStack(s);
	cout << "after clear the stack is:" << endl;
	ShowStack(s);
	*/

	DestroyStack(s);
	cout << "after destory the stack is:" << endl;
	ShowStack(s);

	return 0;
}


//下面是调用内置的栈操作
/*
#include<iostream>
#include<stack> 
using namespace std;

int main()
{
stack <int>stk;
//入栈
for(int i=0;i<50;i++){
stk.push(i);
}
cout<<"栈的大小:"<<stk.size()<<endl;
while(!stk.empty())
{
cout<<stk.top()<<endl;
stk.pop();
}
cout<<"栈的大小:"<<stk.size()<<endl;
return 0;
}

*/