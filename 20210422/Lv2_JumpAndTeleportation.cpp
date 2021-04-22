int JumpAndTeleportation(int n)
{
	int nUsage = 1;

	while (n > 2)
	{
		if (n & 1 == true)
		{
			nUsage++;
			n--;
		}

		n /= 2;
	}

	return nUsage;
}