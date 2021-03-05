#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
	string smallestSubsequence(string text)
	{
		string strResult;

		map <char, vector<int>> mSpellIndex;
		for (int i = 0; i < (int)text.size(); i++)
		{
			vector<int> vIndex;
			vIndex.push_back(i);

			pair<map<char, vector<int>>::iterator, bool> InsertResult = mSpellIndex.insert(pair<char, vector<int>>(text[i], vIndex));

			if (InsertResult.second != true)
			{
				mSpellIndex.find(InsertResult.first->first)->second.push_back(i);
			}
		}

		map<char, vector<int>>::iterator iterPick = mSpellIndex.begin();
		while (mSpellIndex.empty() != true)
		{
			bool bCurCharFix = true;
			int nPickCharMin = iterPick->second.front();

			for (map<char, vector<int>>::iterator iterOther = mSpellIndex.begin(); iterOther != mSpellIndex.end(); iterOther++)
			{
				if (iterOther != iterPick)
				{
					int nOtherCharMax = iterOther->second.back();
					if (nPickCharMin > nOtherCharMax)
					{
						bCurCharFix = false;
						iterPick++;
						break;
					}
				}
			}

			if (bCurCharFix == true)
			{
				strResult.push_back(iterPick->first);

				mSpellIndex.erase(iterPick);

				for (map<char, vector<int>>::iterator iterEraseIndex = mSpellIndex.begin(); iterEraseIndex != mSpellIndex.end(); iterEraseIndex++)
				{
					vector<int>::iterator iterVec = iterEraseIndex->second.begin();

					while (*iterVec < nPickCharMin)
					{
						iterVec = iterEraseIndex->second.erase(iterVec);
					}
				}

				iterPick = mSpellIndex.begin();
			}
		}

		return strResult;
	}

	string smallestSubsequence(string text)
	{
		map<char, int> mSpellCount;
		for (auto c : text)
			mSpellCount[c]++;

		int nResultSize = mSpellCount.size();
		string strResult;

		for (int i = 0; i < (int)text.size(); i++)
		{
			for (string::reverse_iterator riter = strResult.rbegin(); riter != strResult.rend(); riter++)
			{
				if (strResult.find(text[i]) != string::npos)
					break;

				if (*riter >= text[i])
				{
					if (mSpellCount[*riter] > 0)
					{
						strResult.pop_back();
						continue;
					}
				}

				strResult.push_back(text[i]);
				break;
			}

			if (strResult.empty() == true)
			{
				strResult.push_back(text[i]);
			}

			mSpellCount[text[i]]--;
		}

		return strResult;
	}
};

void main()
{
	Solution *solution = new Solution();

	//solution->smallestSubsequence("cdadabcc");
	//solution->smallestSubsequence("bcbcbcababa");
	//solution->smallestSubsequence("bbbbaaaababaaabbbabbabaabaabbabaaaababbb");
	//solution->smallestSubsequence("ddeeeccdce");
	//solution->smallestSubsequence("acfdfdgaadgfacfgffeddeddaadfdcbegaeecfafffdecgeebd");
	//solution->smallestSubsequence("bdaccdbddc");
	//solution->smallestSubsequence("gffeddedfdcbegaeecfafffdec");
	//solution->smallestSubsequence("degbgjchgibedhgcdicccdhjjcegicgjejfbhijedbafgjigff");
	//solution->smallestSubsequence("nfrgpdkaawogejjtsiilzbwduusydlijrbyfvacgeguvccpdvhfdxzygndxzpzwaffxgvijhyblrrjtlinysreitegavkrtbzeyzrokwhtwzegxsjbbwqczlfxndsnfxjnxhsezsmxtvkcxevrboxjqrthujosysfwpgrbpozbvugdjvgpeutulqusssruktnghecvwq");
	solution->smallestSubsequence("leetcode");

	delete solution;
	system("pause");
}

