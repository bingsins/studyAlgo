#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
	int m_nSize;
	int m_nResult;

	enum
	{
		eNONE = -1,
		eLT = 0,
		eRT,
		eLB,
		eRB,
		eWHOLE,
		ePAINT_CNT,

		eORIGIN = 0,
		eTOP,
		eBOTTOM,
		eLEFT,
		eRIGHT,
		eCHECK_CNT,

		eBEFORE = 0,
		eDOING,
		eDONE,
	};

	struct stCheckNode
	{
		long lChecked;
		long lPaintType;

		stCheckNode()
		{
			lChecked = eBEFORE;
			lPaintType	= eNONE; 
		}
	};

	vector<vector<stCheckNode>> vstCheckNode;

	void DFS(long lCheckType, int i, int j, vector<string>& grid)
	{
		if (i < 0 || i >= m_nSize || j < 0 || j >= m_nSize)
			return;
		
		if (vstCheckNode[i][j].lChecked == eDONE)
			return;

		switch (lCheckType)
		{
		case eORIGIN:
		{
			if (grid[i][j] == ' ')
			{
				vstCheckNode[i][j].lChecked = eDONE;
				vstCheckNode[i][j].lPaintType = eWHOLE; 
				DFS(eTOP, i - 1, j, grid);
				DFS(eBOTTOM, i + 1, j, grid);
				DFS(eLEFT, i, j - 1, grid);
				DFS(eRIGHT, i, j + 1, grid);
			}
			else if (grid[i][j] == '\\')
			{ 
				vstCheckNode[i][j].lChecked = (vstCheckNode[i][j].lChecked == eBEFORE) ? eDOING : eDONE;

				if (vstCheckNode[i][j].lPaintType == eRT)
				{
					vstCheckNode[i][j].lPaintType = eLB;
					DFS(eLEFT, i, j - 1, grid);
					DFS(eBOTTOM, i + 1, j, grid);
				}
				else
				{
					vstCheckNode[i][j].lPaintType = eRT;
					DFS(eRIGHT, i, j + 1, grid);
					DFS(eTOP, i - 1, j, grid);
				}
			}
			else if (grid[i][j] == '/')
			{
				vstCheckNode[i][j].lChecked = (vstCheckNode[i][j].lChecked == eBEFORE) ? eDOING : eDONE;

				if (vstCheckNode[i][j].lPaintType == eRB)
				{
					vstCheckNode[i][j].lPaintType = eLT;
					DFS(eLEFT, i, j - 1, grid);
					DFS(eTOP, i - 1, j, grid);
				}
				else
				{
					vstCheckNode[i][j].lPaintType = eRB;
					DFS(eRIGHT, i, j + 1, grid);
					DFS(eBOTTOM, i + 1, j, grid);
				}
			}

			m_nResult++;
		}
		break;
		case eTOP:
		{
			if (grid[i][j] == ' ')
			{
				vstCheckNode[i][j].lChecked = eDONE;
				vstCheckNode[i][j].lPaintType = eWHOLE;
				DFS(eTOP, i - 1, j, grid);
				DFS(eLEFT, i, j - 1, grid);
				DFS(eRIGHT, i, j + 1, grid);
			}
			else if (grid[i][j] == '\\')
			{
				if (vstCheckNode[i][j].lPaintType == eLB)
					return;

				vstCheckNode[i][j].lChecked = (vstCheckNode[i][j].lChecked == eBEFORE) ? eDOING : eDONE;
				vstCheckNode[i][j].lPaintType = eLB;
				DFS(eLEFT, i, j - 1, grid);
			}
			else if (grid[i][j] == '/')
			{
				if (vstCheckNode[i][j].lPaintType == eRB)
					return;

				vstCheckNode[i][j].lChecked = (vstCheckNode[i][j].lChecked == eBEFORE) ? eDOING : eDONE;
				vstCheckNode[i][j].lPaintType = eRB;
				DFS(eRIGHT, i, j + 1, grid);
			}
		}
		break;
		case eBOTTOM:
		{
			if (grid[i][j] == ' ')
			{
				vstCheckNode[i][j].lChecked = eDONE;
				vstCheckNode[i][j].lPaintType = eWHOLE;
				DFS(eBOTTOM, i + 1, j, grid);
				DFS(eLEFT, i, j - 1, grid);
				DFS(eRIGHT, i, j + 1, grid);
			}
			else if (grid[i][j] == '\\')
			{
				if (vstCheckNode[i][j].lPaintType == eRT)
					return;

				vstCheckNode[i][j].lChecked = (vstCheckNode[i][j].lChecked == eBEFORE) ? eDOING : eDONE;
				vstCheckNode[i][j].lPaintType = eRT;
				DFS(eRIGHT, i, j + 1, grid);
			}
			else if (grid[i][j] == '/')
			{
				if (vstCheckNode[i][j].lPaintType == eLT)
					return;

				vstCheckNode[i][j].lChecked = (vstCheckNode[i][j].lChecked == eBEFORE) ? eDOING : eDONE;
				vstCheckNode[i][j].lPaintType = eLT;
				DFS(eLEFT, i, j - 1, grid);
			}
		}
		break;
		case eLEFT:
		{
			if (grid[i][j] == ' ')
			{
				vstCheckNode[i][j].lChecked = eDONE;
				vstCheckNode[i][j].lPaintType = eWHOLE;
				DFS(eTOP, i - 1, j, grid);
				DFS(eBOTTOM, i + 1, j, grid);
				DFS(eLEFT, i, j - 1, grid);
			}
			else if (grid[i][j] == '\\')
			{
				if (vstCheckNode[i][j].lPaintType == eRT)
					return;

				vstCheckNode[i][j].lChecked = (vstCheckNode[i][j].lChecked == eBEFORE) ? eDOING : eDONE;
				vstCheckNode[i][j].lPaintType = eRT;
				DFS(eTOP, i - 1, j, grid);
			}
			else if (grid[i][j] == '/')
			{
				if (vstCheckNode[i][j].lPaintType == eRB)
					return;

				vstCheckNode[i][j].lChecked = (vstCheckNode[i][j].lChecked == eBEFORE) ? eDOING : eDONE;
				vstCheckNode[i][j].lPaintType = eRB;
				DFS(eBOTTOM, i + 1, j, grid);
			}
		}
		break;
		case eRIGHT:
		{
			if (grid[i][j] == ' ')
			{
				vstCheckNode[i][j].lChecked = eDONE;
				vstCheckNode[i][j].lPaintType = eWHOLE;
				DFS(eTOP, i - 1, j, grid);
				DFS(eBOTTOM, i + 1, j, grid);
				DFS(eRIGHT, i, j + 1, grid);
			}
			else if (grid[i][j] == '\\')
			{
				if (vstCheckNode[i][j].lPaintType == eLB)
					return;

				vstCheckNode[i][j].lChecked = (vstCheckNode[i][j].lChecked == eBEFORE) ? eDOING : eDONE;
				vstCheckNode[i][j].lPaintType = eLB;
				DFS(eBOTTOM, i + 1, j, grid);
			}
			else if (grid[i][j] == '/')
			{
				if (vstCheckNode[i][j].lPaintType == eLT)
					return;

				vstCheckNode[i][j].lChecked = (vstCheckNode[i][j].lChecked == eBEFORE) ? eDOING : eDONE;
				vstCheckNode[i][j].lPaintType = eLT;
				DFS(eTOP, i - 1, j, grid);
			}
		}
		break;
		}
	}

	int regionsBySlashes(vector<string>& grid)
	{
		m_nSize = grid[0].size();

		m_nResult = 0;

		for (int i = 0; i < m_nSize; i++)
		{
			vector<stCheckNode> temp(m_nSize);
			vstCheckNode.push_back(temp);
		}

		for (int i = 0; i < m_nSize; i++)
		{
			for (int j = 0; j < m_nSize; j++)
			{
				DFS(eORIGIN, i, j, grid);
			}
		}
		DFS(eORIGIN, 0, 0, grid);
						
		return m_nResult;
	}
};

void main()
{
	Solution *solution = new Solution();

	vector<string> grid;

	grid.push_back("/\\");
	grid.push_back("\\/");

	int nResult = solution->regionsBySlashes(grid);

	cout << "Result: " << nResult << endl;

	delete solution;
	system("pause");
}