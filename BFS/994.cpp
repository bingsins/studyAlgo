#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
	enum
	{
		eVISITED_CELL	= -1,
		eEMPTY_CELL		= 0,
		eFRESH_ORANGE,
		eROTTEN_ORANGE,
	};

	struct stRottenSpot
	{
		int nRow;
		int nCol;

		stRottenSpot(int row, int col)
		{
			nRow = row;
			nCol = col;
		}
	};
	
	queue<stRottenSpot> m_qRottenOrangeSpot;

	bool HasFreshOrange(vector<vector<int>>& grid)
	{
		int nSize = grid.size();
		for (int i = 0; i < nSize; i++)
		{
			vector<int>::iterator iter = find(grid[i].begin(), grid[i].end(), eFRESH_ORANGE);
			if (iter != grid[i].end())
				return true;
		}

		return false;
	}

	void GetRottenOrangeSpot(vector<vector<int>>& grid)
	{
		int nSize = grid.size();
		for (int i = 0; i < nSize; i++)
		{
			vector<int>::iterator iter = find(grid[i].begin(), grid[i].end(), eROTTEN_ORANGE);
			while (iter != grid[i].end())
			{
				stRottenSpot stSpot(i, distance(grid[i].begin(), iter));
				m_qRottenOrangeSpot.push(stSpot);

				iter = find(++iter, grid[i].end(), eROTTEN_ORANGE);
			}
		}
	}

	void InsertQueue(int nRow, int nCol, vector<vector<int>>&grid)
	{		
		int nRowSize = grid.size();
		int nColSize = grid[0].size();
		if (nRow < 0 || nRow >= nRowSize)
			return;

		if (nCol < 0 || nCol >= nColSize)
			return;
		
		if (grid[nRow][nCol] == eFRESH_ORANGE)
		{
			grid[nRow][nCol] = eROTTEN_ORANGE;

			stRottenSpot stSpot(nRow, nCol);
			m_qRottenOrangeSpot.push(stSpot);
		}
	}

	void AdjacentRotting(stRottenSpot stSpot, vector<vector<int>>& grid)
	{
		InsertQueue(stSpot.nRow - 1, stSpot.nCol,	  grid);
		InsertQueue(stSpot.nRow + 1, stSpot.nCol,	  grid);
		InsertQueue(stSpot.nRow,	 stSpot.nCol - 1, grid);
		InsertQueue(stSpot.nRow,	 stSpot.nCol + 1, grid);
	}

	int orangesRotting(vector<vector<int>>& grid) 
	{
		int nResult = 0;

		bool bHasFreshOrange = HasFreshOrange(grid);
		if (bHasFreshOrange == false)
			return nResult;
		
		GetRottenOrangeSpot(grid);
		while (m_qRottenOrangeSpot.empty() != true)
		{
			int nSize = m_qRottenOrangeSpot.size();
			for (int i = 0; i < nSize; i++)
			{
				stRottenSpot stSpot = m_qRottenOrangeSpot.front();
				m_qRottenOrangeSpot.pop();

				AdjacentRotting(stSpot, grid);
			}

			nResult++;
		}

		bHasFreshOrange = HasFreshOrange(grid);
		if (bHasFreshOrange == true)
			return -1;
	
		return --nResult;
	}
};

void main()
{
	Solution *solution = new Solution();
	
	vector<vector<int>> grid;

	vector<int> gridRow;

	gridRow.push_back(Solution::eROTTEN_ORANGE);
	gridRow.push_back(Solution::eFRESH_ORANGE);
	gridRow.push_back(Solution::eFRESH_ORANGE);
	grid.push_back(gridRow);
	gridRow.clear();

	gridRow.push_back(Solution::eFRESH_ORANGE);
	gridRow.push_back(Solution::eFRESH_ORANGE);
	gridRow.push_back(Solution::eEMPTY_CELL);
	grid.push_back(gridRow);
	gridRow.clear();

	gridRow.push_back(Solution::eEMPTY_CELL);
	gridRow.push_back(Solution::eFRESH_ORANGE);
	gridRow.push_back(Solution::eFRESH_ORANGE);
	grid.push_back(gridRow);
	gridRow.clear();
	
	int nResult = solution->orangesRotting(grid);

	cout << "Result: " << nResult << endl;

	delete solution;
	system("pause");
}