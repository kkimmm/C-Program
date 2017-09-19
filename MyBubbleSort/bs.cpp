#include <iostream>
using namespace std;

//方法一，常用方法
/*void Bubble(int a[],int n)
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = n-1; j>i; j--)
		{
			if (a[j-1]>a[j])
			{
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
}*/

//方法二
void Bubble(int a[], int n)
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j =0; j<n-1; j++)
		{
			if (a[j]>a[j+1])
			{
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main()
{
	int a[] = { 13, 15, 64, 2, 5,48 };
	Bubble(a, 6);
	for (int i = 0; i < 6; i++)
	{
		cout << a[i]<<endl;
	}
	return 0;
}