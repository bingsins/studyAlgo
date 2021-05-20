#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
	long long llResult = 0;

	priority_queue<long long> pq;

	for (int work : works)
		pq.push(work);

	for (int i = 0; i < n; i++)
	{
		if (pq.empty() == true)
			break;

		int nCurWork = pq.top() - 1;
		pq.pop();

		if (nCurWork != 0)
			pq.push(nCurWork);
	}

	if (pq.empty() == true) 
		return llResult;

	while (!pq.empty())
	{
		llResult += pq.top() * pq.top();
		pq.pop();
	}

	return llResult;
}