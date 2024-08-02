int fastpow(int x, int y) 
{
	int ans = 1;
	while (y) 
	{
		if (y & 1) 
		{
			ans *= x;
		}
		x *= x;
	}
	return ans;
}