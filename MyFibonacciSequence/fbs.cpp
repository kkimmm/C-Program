#include <iostream>
using namespace std;

int Fabonacci(int n)
{	
	if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	else
	{
		return Fabonacci(n - 1) + Fabonacci(n - 2);		
	}

	

}

int main()
{
	int i,j;
	cout << "input a number:";
	cin >> i;

	cout << "the fibonacci sequence is:"<<endl;
	for (int n = 1; n <= i; n++)
	{
		j = Fabonacci(n);		
		cout<< j;
		cout << endl;
	}
	
	

}