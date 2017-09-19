#include <iostream>
using namespace std;

int BinarySearch(int A[10],int low,int high, int n)
{
	int mid;
	
	mid = (low + high) / 2;
	if (A[mid] == n)
		return mid;
	else if (A[mid] < n)
	{
		low = mid + 1;
		return BinarySearch(A, low, high, n);
	}
	else if (A[mid] > n)
	{
		high = mid - 1;
		return BinarySearch(A, low, high, n);
	}

}

int main()
{
	int n,m;
	int A[10] = { 1, 20, 33, 44, 50, 61, 78, 80, 91,100 };
	cout << "chose one of the number:1, 20, 33, 44, 50, 61, 78, 80, 91,100 "<<endl;
	cout << "if your choses is not one of those number, the algorithm will crash" << endl;
	cin >> n;
	m = BinarySearch(A,1,10,n);
	cout << "the number's positon is: "<<m+1<<endl;

	return 0;
}