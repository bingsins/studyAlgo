// Lv.3 등굣길
int m_nMaxCol;
int m_nMaxRow;
int m_nWayCount;
int WayToSchool(int m, int n, vector<vector<int>> puddles);
void WayToSchoolDP(int nCol, int nRow, vector<vector<int>> puddles);
int WayToSchool2(int m, int n, vector<vector<int>> puddles);


int Programmers::WayToSchool(int m, int n, vector<vector<int>> puddles)
{
	m_nMaxCol = m;
	m_nMaxRow = n;

	m_nWayCount = 0;

	WayToSchoolDP(1, 1, puddles);
	
	return m_nWayCount;
}

void Programmers::WayToSchoolDP(int nCol, int nRow, vector<vector<int>> puddles)
{
	if (nCol > m_nMaxCol || nRow > m_nMaxRow)
		return;

	if (nCol == m_nMaxCol && nRow == m_nMaxRow)
	{
		m_nWayCount++;
		
		if (m_nWayCount == 1000000007)
			m_nWayCount = 0;

		return;
	}

	vector<int> vCurrentSpot;
	vCurrentSpot.push_back(nCol);
	vCurrentSpot.push_back(nRow);
	vector<vector<int>>::iterator iter = find(puddles.begin(), puddles.end(), vCurrentSpot);
	if (iter != puddles.end())
		return;

	WayToSchoolDP(nCol + 1, nRow, puddles);
	WayToSchoolDP(nCol, nRow + 1, puddles);
}

int Programmers::WayToSchool2(int m, int n, vector<vector<int>> puddles)
{
	vector<int> vTemp(m);
	vector<vector<int>> vDP(n, vTemp);

	for (auto puddle : puddles)
	{
		vDP[puddle[1] - 1][puddle[0] - 1] = -1;
	}

	vDP[0][0] = 1;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 && j == 0)
				continue;

			if (vDP[j][i] == -1)
				continue;

			int nTop = 0, nLeft = 0;
			if ((j-1) >= 0 && vDP[j - 1][i] != -1)
				nTop = vDP[j - 1][i];

			if ((i-1) >= 0 && vDP[j][i - 1] != -1)
				nLeft = vDP[j][i - 1];

			vDP[j][i] = nTop + nLeft;
			vDP[j][i] %= 1000000007;
		}
	}

	return vDP[n - 1][m - 1];
}