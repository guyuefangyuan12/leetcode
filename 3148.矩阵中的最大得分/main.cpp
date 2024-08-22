#include<vector>
using namespace std;

class Solution
{
public:
	int maxScore(vector<vector<int>>& grid)
	{
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, INT_MIN / 2));
		int ans = INT_MIN;
		for (int i = m - 1; i >= 0; i--)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				if (i == m - 1 && j == n - 1)
				{
					dp[i][j] = 0;
					continue;
				}
				else
				{
					for (int k = j + 1; k < n; k++)
					{
						dp[i][j] = max(dp[i][j], dp[i][k] > 0 ? (dp[i][k] + grid[i][k] - grid[i][j]) : (grid[i][k] - grid[i][j]));
					}
					for (int k = i + 1; k < m; k++)
					{
						dp[i][j] = max(dp[i][j], dp[k][j] > 0 ? (dp[k][j] + grid[k][j] - grid[i][j]) : (grid[k][j] - grid[i][j]));
					}
					ans = max(dp[i][j], ans);
				}
			}
		}
		return ans;
	}
};

