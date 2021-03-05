#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int mincostTickets(vector<int>& days, vector<int>& costs);
};

int Solution::mincostTickets(vector<int>& days, vector<int>& costs)
{
	long lDaySize = days.size();
	int lLastDay = days[lDaySize - 1];

	vector<bool> vbTravel(lLastDay + 1, false);	// '+1' for day index sync

	for (int i = 0; i < lDaySize; i++)
	{
		vbTravel[days[i]] = true;
	}
	
	vector<int> vnMinCost(lLastDay + 1, 0);
	
	for (int i = 1; i < lLastDay + 1; i++)
	{		
		if (vbTravel[i] == false)
		{
			vnMinCost[i] = vnMinCost[i - 1];
		}
		else
		{
			int n1Index		= (i - 1)  > 0 ? i - 1  : 0;
			int n7Index		= (i - 7)  > 0 ? i - 7  : 0;
			int n30Index	= (i - 30) > 0 ? i - 30 : 0;

			int nBuy1day	= vnMinCost[n1Index]  + costs[0];
			int nBuy7days	= vnMinCost[n7Index]  + costs[1];
			int nBuy30days	= vnMinCost[n30Index] + costs[2];

			vnMinCost[i] = min(min(nBuy1day, nBuy7days), nBuy30days);
		}
	}

	return vnMinCost[lLastDay];
}

void main()
{
	Solution *solution = new Solution();

	vector<int> vDays;
	vector<int> vCosts(3);

	// input days
	cout << "days: ";

	string temp;
	int nDay;

	getline(cin, temp);

	stringstream streamDay;
	streamDay.str(temp);		// temp의 자료형에 맞는 값으로 parsing. ' ', '\n'는 무시
	while (streamDay >> nDay)	// 더이상 파싱할 값 없으면 0 return
	{
		vDays.push_back(nDay);
	}

	// input costs
	cout << "costs: ";
	for (int i = 0; i < 3; i++)
	{
		cin >> vCosts[i];
	}

	int nResult = solution->mincostTickets(vDays, vCosts);

	cout << "Result: " << nResult << endl;

	delete solution;
	system("pause");
}