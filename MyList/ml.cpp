#include <iostream>
using namespace std;

#define MAX 100
int Len = 0;
int A[MAX];

void GetElem(int i)
{
	if (i<0 || i>Len || Len ==0)
	{
		cout << "error! " << endl;
	}
	else
	{
		cout << "the number is:" << A[i - 1] << endl;
		
	}
	
}

void InsertElem(int i,int j)
{
	int num;
	if (i<0 || i>Len || Len == MAX)
	{
		cout << "error!" << endl;
	}
	else
	{
		for (num =Len; num >= i-1; num--)
		{
			A[num+1] = A[num];
							
		}
		A[i-1] = j;
		Len++;		
	}
}

void DelElem(int i)
{
	int num;
	if (i<0 || i>Len)
	{
		cout << "error!" << endl;
	}
	else
	{
		for (num = i; num <= Len; num++)
		{
			A[num-1] = A[num];
		}
		Len--;
	}
}


void Print()
{
	for (int i = 0; i <Len; i++)
	{
		cout << A[i];
		
	}
	cout << endl;
}


int main()
{
	int i, k, j;

	cout << "input a number for list length:";
	cin >> Len;
	for (i = 0; i < Len; i++)
	{
		cin >> k;
		A[i] = k;
	}
	Print();
	
	
	cout << "which position you want to get" << endl;
	cin >> i;
	GetElem(i);
	Print();

	cout << "which position you want to insert" << endl;
	cin >> i;
	cout <<"which number you want to insert" << endl;
	cin >> j;
	InsertElem(i,j);
	Print();
	cout << Len;

	cout << "which position you want to delet" << endl;
	cin >> i;
	DelElem(i);
	Print();

	return 0;
}