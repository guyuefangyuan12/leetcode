#include<vector>
using namespace std;

class Solution
{
public:
	int checkRecord(int n)
	{
		vector<vector<vector<int>>> dp(2, vector<vector<int>>(3, vector<int>(2, 0)));
		long long res = 1000000007;
		dp[0][0][0] = 1;
		for (int i = 0; i < n; i++)
		{
			dp[i][0][0] = (dp[i - 1][0][0] + dp[i][0][0]) % res;
			dp[i][0][0] = (dp[i - 1][1][0] + dp[i][0][0]) % res;
			dp[i][0][0] = (dp[i - 1][2][0] + dp[i][0][0]) % res;
			dp[i][1][0] = (dp[i - 1][0][0]) % res;
			dp[i][2][0] = (dp[i - 1][1][0]) % res;
			dp[i][0][1] = (dp[i - 1][0][0] + dp[i][0][1]) % res;
			dp[i][0][1] = (dp[i - 1][1][0] + dp[i][0][1]) % res;
			dp[i][0][1] = (dp[i - 1][2][0] + dp[i][0][1]) % res;
			dp[i][0][1] = (dp[i - 1][0][1] + dp[i][0][1]) % res;
			dp[i][0][1] = (dp[i - 1][1][1] + dp[i][0][1]) % res;
			dp[i][0][1] = (dp[i - 1][2][1] + dp[i][0][1]) % res;
			dp[i][1][1] = (dp[i - 1][0][1]) % res;
			dp[i][2][1] = (dp[i - 1][1][1]) % res;
		}
		int ans = dp[n][0][0];
		ans = (ans + dp[n][0][1]) % res;
		ans = (ans + dp[n][1][0]) % res;
		ans = (ans + dp[n][1][1]) % res;
		ans = (ans + dp[n][2][0]) % res;
		ans = (ans + dp[n][2][1]) % res;
		return ans;
	}
};