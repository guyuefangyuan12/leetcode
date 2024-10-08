#include<vector>
#include<functional>
#include<unordered_map>
using namespace std;

class Solution
{
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
	{
		int n = stations.size();
		vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
		dp[0][0] = startFuel;
		for (int i = 1; i < n + 1; i++)
		{
			long long dis = stations[i - 1][0] - ((i == 1) ? 0 : stations[i - 2][0]);
			if (dp[i][0] >= 0)
			{
				dp[i][0] = dp[i - 1][0] - dis;
			}
			else
			{
				dp[i][0] = dp[i - 1][0];
			}
			for (int j = 1; j <= i; j++)
			{
				if (dp[i - 1][j - 1] >= dis)
				{
					dp[i][j] = dp[i - 1][j - 1] - dis + stations[i - 1][1];
				}
				else
				{
					dp[i][j] = dp[i - 1][j - 1] - dis;
				}
				if (i != j)
				{
					if (dp[i - 1][j] >= 0)
					{
						dp[i][j] = max(dp[i][j], dp[i - 1][j] - dis);
					}
				}
			}
		}
		for (int i = 0; i <= n; i++)
		{
			if (dp[n][i] >= target - ((n == 0) ? 0 : stations[n - 1][0]))
			{
				return i;
			}
		}
		return -1;
	}
};

