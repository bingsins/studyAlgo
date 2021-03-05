#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <map>

using namespace std;

class Solution
{
public:
	struct greater
	{
		bool operator()(pair<int, int> a, pair<int, int> b)
		{
			return a.second < b.second;
		}
	};

	vector<int> rearrangeBarcodes(vector<int>& barcodes) 
	{
		vector<int> vResult;
		
		map<int, int> m;
		for (auto i : barcodes)
			m[i]++;

		priority_queue < pair<int, int>, vector<pair<int, int>>, greater> pq;
		
		for (auto i : m)
			pq.push(make_pair(i.first, i.second));

		pair<int, int> p = pq.top();	pq.pop();
		vector<vector<int>> v(p.second);
		
		int nRow		= 0;			// Vector Row Group Index
		int nIndex		= 0;			// Loop iterator
		int nRange		= p.second;		// Loop Range
		int nVectorSize	= p.second;		// Vector Size(max key value)

		while (1)
		{
			if (nRow != 0)
			{
				for (nIndex = nRow; nIndex < nVectorSize; nIndex++)
				{
					v[nIndex].push_back(p.first);
					nRange--;

					if (nRange <= 0)
						break;
				}

				if (nRange > 0)
				{
					for (nIndex = 0; nIndex < nRange; nIndex++)
						v[nIndex].push_back(p.first);
				}
			}
			else
			{
				for (nIndex = nRow; nIndex < nRange; nIndex++)
					v[nIndex].push_back(p.first);
			}

			if (pq.empty() == true)
				break;

			p = pq.top(); pq.pop();
			nRange = p.second;
			nRow = (nIndex < nVectorSize) ? nIndex : 0;
		}

		for (auto i:v)
			for (auto j:i)
				vResult.push_back(j);
			
		return vResult;
	}
};

void main()
{
	Solution *solution = new Solution();

	vector<int> barcodes;

	barcodes.push_back(1);
	barcodes.push_back(1);
	barcodes.push_back(3);
	barcodes.push_back(3);
	barcodes.push_back(2);
	barcodes.push_back(2);
	barcodes.push_back(2);

	vector<int> vResult = solution->rearrangeBarcodes(barcodes);
	
	int nSize = vResult.size();
	for (int i = 0; i < nSize; i++)
	{
		cout << "[" << i << "]:" << vResult[i] << endl;
	}

	delete solution;
	system("pause");
}


/* // big, small, big, small, ... -> exception: 1, 3, 2, 2
class Solution
{
public:
	struct greater
	{
		bool operator()(int a, int b)
		{
			return a < b;
		}
	};

	struct less
	{
		bool operator()(int a, int b)
		{
			return a > b;
		}
	};

	vector<int> rearrangeBarcodes(vector<int>& barcodes) 
	{
		vector<int> vResult;
		
		priority_queue<int, vector<int>, less> pqAscending;
		priority_queue<int, vector<int>, greater> pqDescending;

		int nSize = barcodes.size();
		for (int i = 0; i < nSize; i++)
		{
			pqAscending.push(barcodes[i]);
			pqDescending.push(barcodes[i]);
		}

		bool bAscending = true;
		for (int i = 0; i < nSize; i++)
		{
			if (bAscending == true)
			{
				vResult.push_back(pqAscending.top());
				pqAscending.pop();
			}
			else
			{
				vResult.push_back(pqDescending.top());
				pqDescending.pop();
			}

			bAscending = !bAscending;
		}

		return vResult;
	}
};
*/
