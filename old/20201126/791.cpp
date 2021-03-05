class Solution {
public:
	string customSortString(string S, string T)
	{
		string strResult;

		for (auto c : S)
		{
			int nCount = count(T.begin(), T.end(), c);
			if (nCount > 0)
			{
				for (int i = 0; i < nCount; i++)
					strResult.push_back(c);

				T.erase(remove(T.begin(), T.end(), c), T.end());
			}
		}

		strResult += T;

		return strResult;
	}
};