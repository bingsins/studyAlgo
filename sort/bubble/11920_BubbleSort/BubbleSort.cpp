////////////////////// Baekjoon ver //////////////////////////
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <functional>

using namespace std;

int main()
{
	int n, k;

	// get first line
	cin >> n >> k;

	priority_queue<int, vector<int>, greater<int>> pqNumArray;
	int *NumArray = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> NumArray[i];
	}

	// sorted k elements
	for (int i = 0; i < k; i++)
	{
		pqNumArray.push(NumArray[i]);
	}

	for (int i = k; i < n; i++)
	{
		pqNumArray.push(NumArray[i]);
		cout << pqNumArray.top() << " ";
		pqNumArray.pop();
	}
	while (!pqNumArray.empty())
	{
		cout << pqNumArray.top() << " ";
		pqNumArray.pop();
	}
	cout << "\n";

	delete[] NumArray;

	system("pause");

	return 0;
}

////////////////////// BubbleSort ver //////////////////////////
/*
#include <iostream>

using namespace std;

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void OneStepBubbleSort(int n, int NumArray[])
{
	for (int i = 0; i < n - 1; i++)
	{
		if (NumArray[i] > NumArray[i + 1])
		{
			Swap(&NumArray[i], &NumArray[i + 1]);
		}
	}
}

int main()
{
	int n, k;

	// get first line
	cin >> n >> k;

	// get second line
	int	 *NumArray = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> NumArray[i];
	}

	// bubble sort
	for (int i = 1; i <= k; i++)
	{
		OneStepBubbleSort(n, NumArray);
	}

	// print result
	for (int i = 0; i < n; i++)
	{
		cout << NumArray[i] << " ";
	}
	cout << "\n";

	delete[] NumArray;
	system("pause");

	return 0;
}
*/