class UndergroundSystem 
{
public:
    struct Customer
	{
		int nID;
		int nInTime;
		string strInStation;

		Customer(int n1, int n2, string str)
		{
			nID = n1;
			nInTime = n2;
			strInStation = str;
		}
	};

	struct TripRecord
	{
		string strInStation;
		string strOutStation;

		TripRecord(string str1, string str2)
		{
			strInStation = str1;
			strOutStation = str2;
		}

		bool operator < (const TripRecord& t) const
		{
			if (strInStation == t.strInStation)
				return strOutStation < t.strOutStation;
			else
				return strInStation < t.strInStation;
		}
	};

	map<int, Customer> m_mCheckIn;
	map<TripRecord, vector<int>> m_mAverageTime;
    
    UndergroundSystem() 
    {
        m_mCheckIn.clear();
	    m_mAverageTime.clear();
    }
    
    void checkIn(int id, string stationName, int t) 
    {
        m_mCheckIn.insert(make_pair(id, Customer(id, t, stationName)));
    }
    
    void checkOut(int id, string stationName, int t)
    {
    	auto iter = m_mCheckIn.find(id);

    	vector<int> v;
    	int nTripTime = t - iter->second.nInTime;
    	v.push_back(nTripTime);

    	auto iterAverage = m_mAverageTime.insert(make_pair(TripRecord(iter->second.strInStation, stationName), v));
    	if (iterAverage.second == false)
    	{
    		iterAverage.first->second.push_back(nTripTime);
    	}

    	m_mCheckIn.erase(iter);  
   }
    
    double getAverageTime(string startStation, string endStation)
    {
        auto iter = m_mAverageTime.find(TripRecord(startStation, endStation));

    	if (iter == m_mAverageTime.end())
    		return 0.;

    	return (double)accumulate(iter->second.begin(), iter->second.end(), 0)/ (double)iter->second.size()
    }
};