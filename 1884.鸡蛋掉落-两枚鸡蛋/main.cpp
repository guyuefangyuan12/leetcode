class Solution
{
public:
	int twoEggDrop(int n)
	{
		int cnt = 0;
		int  ans = 0;
		while (ans < n)
		{
			cnt++;
			ans += cnt;
		}
		return cnt + 1;
	}
};