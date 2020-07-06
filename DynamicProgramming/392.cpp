#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	bool isSubsequence(string s, string t);
};

bool Solution::isSubsequence(string s, string t)
{
	int nSizeS = s.size();
	int nSizeT = t.size();
	int nIndexT = 0;
	int nIndexS = 0;

	if (nSizeS == 0)	return true;

	for (int i = nIndexT; i < nSizeT; i++)
	{
		if (s[nIndexS] == t[i])
		{
			nIndexT = i + 1;
			nIndexS++;
		}
	}

	return (nIndexS == nSizeS) ? true : false;
}

void main()
{
	Solution *solution = new Solution();
	
	string sS, sT;
	
	cout << "string s: ";
	cin >> sS;

	cout << "string t: ";
	cin >> sT;

	bool bRet = solution->isSubsequence(sS, sT);

	if (bRet == true)
		cout << "Result: true\n";
	else
		cout << "Result: false\n";

	delete solution;
	system("pause");
}