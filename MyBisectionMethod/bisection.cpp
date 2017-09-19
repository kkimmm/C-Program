#include<iostream>
using namespace std;

double f(double x)
{	
	return 3*x-1;
}

int main()
{
	double x1=-10,y1,x2=10,y2,x3,y3;
	y1 = f(x1);
	y2 = f(x2);
	for (int i = 0; i < 100; i++)
	{
		x3 = (x1 + x2) / 2;
		y3 = f(x3);
		if (y3*y1 < 0)
			x2 = x3;
		else
			x1 = x3;

	}

	cout <<"零点的值为："<<x3<<endl;
	return 0;
}