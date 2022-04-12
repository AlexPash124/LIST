#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List<int> A;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		A.pushBack(rand() % 10);
	}

	for (int i = 0; i < A.getSize(); i++)
	{
		cout << A[i]<<"\t";
	}
	
	//A.pop_front();
	A.clear();
	cout << endl;

	for (int i = 0; i < A.getSize(); i++)
	{
		cout << A[i] << "\t";
	}
}

