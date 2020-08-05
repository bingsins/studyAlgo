#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	struct node
	{
		int nVal;
		bool bApple;
		bool bChecked;
		vector<node*> pChildren;

		node()
		{
			nVal = -1;
			bApple = false;
			bChecked = false;
		}
	};

	int m_nAppleCount;
	int m_nFindAppleCount;
	int m_nCost;

	int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple)
	{
		node *pEdge = new node[n];

		m_nAppleCount = 0;
		for (int i = 0; i < n; i++)
		{
			pEdge[i].nVal = i;

			if (hasApple[i] == true)
			{
				pEdge[i].bApple = true;
				m_nAppleCount++;
			}
		}

		if (m_nAppleCount == 0)
			return 0;

		int nNum = edges.size();
		for (int i = 0; i < nNum; i++)
		{
			pEdge[edges[i][0]].pChildren.push_back(&pEdge[edges[i][1]]);
			pEdge[edges[i][1]].pChildren.push_back(&pEdge[edges[i][0]]);
		}
		
		m_nFindAppleCount = 0;
		m_nCost = -1;
		DFS(&pEdge[0]);

		return (m_nCost-1);
	}

	node* DFS(node* pTree)
	{
		if (pTree == nullptr)
			return pTree;

		if (m_nFindAppleCount >= m_nAppleCount)
			return pTree;

		m_nCost++;
		pTree->bChecked = true;

		if (pTree->bApple == true)
			m_nFindAppleCount++;

		int nChildrenNum = pTree->pChildren.size();
		bool bAllNull = true;
		for (int i = 0; i < nChildrenNum; i++)
		{
			if (pTree->pChildren[i]->bChecked == false)
			{
				pTree->pChildren[i] = DFS(pTree->pChildren[i]);

				if (pTree->pChildren[i] != nullptr)
				{
					bAllNull = false;
				}
			}
		}

		if (bAllNull == true && pTree->bApple != true)
		{
			m_nCost--;
			return nullptr;
		}
		
		m_nCost++;
		return pTree;
	}
};

void main()
{
	Solution *solution = new Solution();

	int n = 0;
	vector<vector<int>> edges;
	vector<bool> hasApple;
	vector<int> edge;

	n = 8;

	edge.push_back(0);
	edge.push_back(1);
	edges.push_back(edge);
	edge.clear();

	edge.push_back(1);
	edge.push_back(2);
	edges.push_back(edge);
	edge.clear();

	edge.push_back(2);
	edge.push_back(3);
	edges.push_back(edge);
	edge.clear();

	edge.push_back(1);
	edge.push_back(4);
	edges.push_back(edge);
	edge.clear();

	edge.push_back(2);
	edge.push_back(5);
	edges.push_back(edge);
	edge.clear();

	edge.push_back(2);
	edge.push_back(6);
	edges.push_back(edge);
	edge.clear();

	edge.push_back(4);
	edge.push_back(7);
	edges.push_back(edge);
	edge.clear();

	hasApple.push_back(true);
	hasApple.push_back(true);
	hasApple.push_back(false);
	hasApple.push_back(true);
	hasApple.push_back(false);
	hasApple.push_back(true);
	hasApple.push_back(true);
	hasApple.push_back(false);

	int nResult = solution->minTime(n, edges, hasApple);

	cout << "Result: " << nResult << endl;

	delete solution;
	system("pause");
}