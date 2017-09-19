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
	cout << "������Ҫ�ƶ������ӵĸ���:";
	cin >> n;
	cout << "���ӵ��ƶ�˳��Ϊ��" << endl;
	c = Hanoi(n,'A', 'B','C',count);
	cout <<"�ܵ��ƶ�����Ϊ��"<< c << endl;
	return 0;
}