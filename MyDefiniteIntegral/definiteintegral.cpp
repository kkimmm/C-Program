#include <iostream>
using namespace std;

double f1(double x)
{
	return  x;
}

double f2(double x)
{
	return x*x;
}

double  DefiniteIntrgral(double a,double b,double (*p)(double x))
{
	int n = 1000;
	double h=(b-a)/n, x, sum = 0.0;
	for (int i = 1; i <= n; i++)
	{
		x = a + (i - 1)*h;
		sum = sum+(p(x)+p(x+h))*h/2;
	}
	return sum;
}

int main()
{
	double a =0, b = 10;
	double  s1 = DefiniteIntrgral(a, b, f1);
	double  s2 = DefiniteIntrgral(a, b,f2);
	cout << s1+s2 <<endl;
	return 0;
}