#include<vector>
#include<unordered_map>
#include<queue>
#include<functional>
using namespace std;

class Solution
{
public:
	int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees)
	{
		int m = edges.size();
		int n = passingFees.size();
		vector<vector<int>> dp(maxTime + 1, vector<int>(n, INT_MAX / 2));
		dp[0][0] = passingFees[0];
		for (int i = 1; i <=maxTime; i++)
		{
			for (auto p : edges)
			{
				if (p[2] <= i) 
				{
					dp[i][p[0]] = min(dp[i][p[0]], dp[i - p[2]][p[1]]+passingFees[p[0]]);
					dp[i][p[1]] = min(dp[i][p[1]], dp[i - p[2]][p[0]]+passingFees[p[1]]);
				}
			}
		}
		int ans = INT_MAX / 2;
		for (int i = 1; i <= maxTime; i++)
		{
			ans = min(ans, dp[i][n - 1]);
		}
		return ans == INT_MAX / 2 ? -1 : ans;
	}
};