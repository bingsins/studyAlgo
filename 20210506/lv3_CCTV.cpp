#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
	sort(routes.begin(), routes.end());

	int nCamCount = 1;
	int nCamIndex = routes[0][1];

	for (auto route : routes)
	{
		if (route[1] < nCamIndex)
		{
			nCamIndex = route[1];
		}
		else
		{
			if (route[0] > nCamIndex)
			{
				nCamIndex = route[1];
				nCamCount++;
			}
		}
	}

	return nCamCount;
}