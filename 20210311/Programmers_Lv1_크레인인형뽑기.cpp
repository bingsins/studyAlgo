int ClawMachineGame(vector<vector<int>> board, vector<int> moves)
{
	int nSize = board.size();
	int nDuplicateCount = 0;
	stack<int> stackBox;

	for (int nMove : moves)
	{
		int nCol = nMove - 1;
		for (int nRow = 0; nRow < nSize; nRow++)
		{
			int nCurrentClaw = board[nRow][nCol];

			if (nCurrentClaw > 0)
			{
				int nTopClawOfBox = (stackBox.empty() == true) ? -1 : stackBox.top();
				if (nTopClawOfBox == nCurrentClaw)
				{
					stackBox.pop();
					nDuplicateCount++;
				}
				else
				{
					stackBox.push(nCurrentClaw);
				}

				board[nRow][nCol] = 0;
				break;
			}
		}
	}

	return nDuplicateCount * 2;
}