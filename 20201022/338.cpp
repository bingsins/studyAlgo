vector<int> countBits(int num)
{
	vector<int> vCount1Bit;

	for (int i = 0; i <= num; i++)
	{
		vCount1Bit.push_back((int)bitset<32>(i).count());
	}

	return vCount1Bit;
}