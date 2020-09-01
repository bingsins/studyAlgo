#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	struct stNode
	{
		int nCount;
		char cKey;

		stNode()
		{
			nCount = 0;
			cKey = NULL;
		}

		stNode(char c)
		{
			nCount = 1;
			cKey = c;
		}

		unsigned operator == (char c)
		{
			return (cKey == c);
		}
	};

	vector<stNode> CharCount(string s)
	{
		int nSize = s.size();
		vector<stNode> v;

		stNode stFirstNode;
		v.push_back(stFirstNode);

		for (int i = 0; i < nSize; i++)
		{
			vector<stNode>::iterator iter = find(v.begin(), v.end(), s[i]);
			if (iter != v.end())
			{
				int nIndex = distance(v.begin(), iter);
				v[nIndex].nCount++;
			}
			else
			{
				stNode node(s[i]);
				v.push_back(node);
			}
		}

		return v;
	}

	vector<stNode> Heapify(vector<stNode> vHeap, stNode node, int nIndex)
	{
		vHeap[nIndex] = node;

		while (nIndex > 1)
		{
			if (vHeap[nIndex].nCount > vHeap[nIndex / 2].nCount)
			{
				swap(vHeap[nIndex], vHeap[nIndex / 2]);
			}

			nIndex = nIndex / 2;
		}

		return vHeap;
	}

	string frequencySort(string s)
	{
		vector<stNode> v = CharCount(s);

		int nHeapSize = v.size();

		vector<stNode> vHeap(nHeapSize);

		for (int i = 1; i < nHeapSize; i++)
		{
			stNode node = v[i];
			vHeap = Heapify(vHeap, node, i);
		}

		string strResult;

		while (vHeap.size() > 1)
		{
			stNode node = vHeap[1];

			swap(vHeap[1], vHeap[nHeapSize-1]);
			vHeap.pop_back();
			nHeapSize--;
			
			int nCount = node.nCount;
			for (int i = 0; i < nCount; i++)
			{
				strResult.push_back(node.cKey);
			}
			
			int nSize = vHeap.size();
			vector<stNode> vHeapSort(nSize);
			for (int i = 1; i < nSize; i++)
			{
				stNode node = vHeap[i];
				vHeapSort = Heapify(vHeapSort, node, i);
			}

			copy(vHeapSort.begin(), vHeapSort.end(), vHeap.begin());
		}

		return strResult;
	}
};

void main()
{
	Solution *solution = new Solution();
	
	string strResult = solution->frequencySort("raaeaedere");

	cout << "Result: " << strResult << endl;

	delete solution;
	system("pause");
}