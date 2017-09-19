#include <iostream>
using namespace std;


int Hanoi(int n,char A,char B,char C,int &counts)
{
	
	counts++;
	if (n == 1)
	{
		cout << A << "->" << C << endl;		
	}
		
	else
	{
		Hanoi(n - 1, A, C, B,counts);	
		cout << A << "->" << C<<endl;		
		Hanoi(n - 1, B, A, C,counts);
		
	}
	return counts;

}

int main()
{
	int n, count = 0, c;
	cout << "请输入要移动的盘子的个数:";
	cin >> n;
	cout << "盘子的移动顺序为：" << endl;
	c = Hanoi(n,'A', 'B','C',count);
	cout <<"总的移动步数为："<< c << endl;
	return 0;
}