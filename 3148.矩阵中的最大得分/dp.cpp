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
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == 0 && j == 0)
				{
					dp[i][j] = 0;
					continue;
				}
				else
				{
					if (i > 0)
					{
						dp[i][j] = max(dp[i][j], dp[i - 1][j] > 0 ? dp[i - 1][j] + grid[i][j] - grid[i - 1][j] : grid[i][j] - grid[i - 1][j]);
					}
					if (j > 0)
					{
						dp[i][j] = max(dp[i][j], dp[i][j - 1] > 0 ? dp[i][j - 1] + grid[i][j] - grid[i][j - 1] : grid[i][j] - grid[i][j - 1]);
					}
					ans = max(dp[i][j], ans);
				}
			}
		}
		return ans;
	}
};

int main() {
	vector<vector<int>>grid = { {4,3,2},{3,2,1} };
	Solution s;
	s.maxScore(grid);
}