long long Programmers::Immigration(int n, vector<int> times)
{
	sort(times.begin(), times.end());
	
	long long llMinTime = 0;
	long long llMaxTime = (long long)n * (long long)(*times.rbegin());

	long long llResult;
	while (llMinTime <= llMaxTime)
	{
		long long llMidTime = llMinTime + (llMaxTime - llMinTime) / 2;

		long long llTotalPossible = 0;
		for (int i : times)
		{
			long long llPossiblePeople = llMidTime / i;
			llTotalPossible += llPossiblePeople;
		}

		if (llTotalPossible >= n)
		{
			llResult = llMidTime;
			llMaxTime = llMidTime - 1;
		}
		else
		{
			llMinTime = llMidTime + 1;
		}
	}

	return llResult;
}