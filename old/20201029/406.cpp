class Solution {
public:
	bool Compare(vector<int> v1, vector<int> v2);
	struct stCompare
	{
		bool operator()(vector<int> v1, vector<int> v2)
		{
			// v[0]: the person's Height
			// v[1]: Count of people who is bigger than the person among standing in front of the person.

			if (v1[0] == v2[0])
				return v1[1] < v2[1];
			else
				return v1[0] > v2[0];
		}
	};

	vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
	{
		vector<vector<int>> vvResult;

		int nPeopleCount = people.size();
		sort(people.begin(), people.end(), stCompare());

		for (int nPerson = 0; nPerson < nPeopleCount; nPerson++)
		{
			if (people[nPerson][1] == nPerson)
			{
				vvResult.push_back(people[nPerson]);
			}
			else
			{
				vvResult.insert(vvResult.begin() + people[nPerson][1], people[nPerson]);
			}
		}

		return vvResult;
	}
};