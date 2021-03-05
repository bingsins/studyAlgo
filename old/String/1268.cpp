#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
	{
		int nResultSize = searchWord.size();
		vector<vector<string>> vResult(nResultSize);

		sort(products.begin(), products.end());

		string strCurSearch;

		for (int i = 0; i < nResultSize; i++)
		{
			strCurSearch.push_back(searchWord[i]);

			int nSearchCount = 0;

			for (int j = 0; j < (int)products.size(); j++)
			{
				long lSearchResult = products[j].find(strCurSearch);

				if (lSearchResult == 0)
				{
					vResult[i].push_back(products[j]);
					nSearchCount++;
				}
				else if (lSearchResult < 0)
					continue;

				if (nSearchCount >= 3)
					break;
			}		
		}

		return vResult;
	}
};

void main()
{
	Solution *solution = new Solution();

	vector<string> vProducts;
	vProducts.push_back("mobile");
	vProducts.push_back("mouse");
	vProducts.push_back("moneypot");
	vProducts.push_back("monitor");
	vProducts.push_back("mousepad");

	string strSearchWord = "mouse";

	vector<vector<string>> vOutput = solution->suggestedProducts(vProducts, strSearchWord);
	
	delete solution;
	system("pause");
}