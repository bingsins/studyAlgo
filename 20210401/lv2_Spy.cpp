int Programmers::SpyClothes(vector<vector<string>> clothes)
{
	map <string, vector<string>> mapClothes;

	for (auto cloth : clothes)
	{
		mapClothes[cloth[1]].push_back(cloth[0]);
	}

	int nResult = 1;
	for (auto iter = mapClothes.begin(); iter != mapClothes.end(); iter++)
	{
		int nCurKindCount = iter->second.size();
		nResult *= ++nCurKindCount;
	}

	return nResult - 1;
}