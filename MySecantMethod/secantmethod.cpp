#include <iostream>
using namespace std;

double f(double x)
{
	return x*x+10*x+1;
}

double solve(double x1,double x2)
{
	return  (x1*f(x2) - x2*f(x1)) / (f(x2) - f(x1));
}

int main()
{
	double x1 = -10, x2 = 10,x3;

	for (int i = 0; i < 100; i++)
	{
		x3 = solve(x1, x2);
		if (f(x3)*f(x1) < 0)
			x2 = x3;
		else
			x1 = x3;
	}

	cout << x3 << endl;
	return 0;
}