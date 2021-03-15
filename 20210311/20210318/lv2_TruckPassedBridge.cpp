// Lv.2 다리를 지나는 트럭
int Programmers::TruckPassedBridge(int bridge_length, int weight, vector<int> truck_weights)
{
	queue<pair<int, int>> qBridge;		// <weight, time>
	int nTruckCount = truck_weights.size();
	int nCurWeightOnBridge = 0;
	int nTime = 0;
	int nCurTruck = 0;

	if (nTruckCount == 1)
		return (bridge_length + 1);

	nTime++;
	nCurWeightOnBridge = truck_weights[nCurTruck];
	qBridge.push(make_pair(truck_weights[nCurTruck++], 1));

	while ((qBridge.empty() != true) || (nCurTruck < nTruckCount))
	{
		nTime++;

		pair<int, int> pairFrontCar = qBridge.front();
		int nTimeCal = nTime - pairFrontCar.second;	// 트럭 들어간 후 흐른 시간
		if (nTimeCal >= bridge_length)
		{
			nCurWeightOnBridge -= pairFrontCar.first;
			qBridge.pop();
		}

		if ((nCurTruck < nTruckCount) && ((int)qBridge.size() < bridge_length))
		{
			int nWillWeight = nCurWeightOnBridge + truck_weights[nCurTruck];
			if (nWillWeight <= weight)
			{
				nCurWeightOnBridge = nWillWeight;
				qBridge.push(make_pair(truck_weights[nCurTruck++], nTime));
			}
		}
	}

	return nTime;
}