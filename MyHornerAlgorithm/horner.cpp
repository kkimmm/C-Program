#include <iostream>
using namespace std;

int main()
{
	int m = 2,i;
	int x = 10;
	
	int a0 = 1, a1 = 1,a2=1;

	for (i = 0; i < m; i++)
	{				
		a0 = a0 * x + a1;
		a1 = a2;
		
	}
	cout <<"the sum is:"<< a0;
	return 0;
}