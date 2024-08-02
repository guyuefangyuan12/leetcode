#include<vector>
#include<functional>
using namespace std;

class Solution
{
public:
	int maxMoves(vector<vector<int>>& grid)
	{
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, -1));
		function<int(int, int)> dfs = [&](int i, int j)->int
			{
				if (dp[i][j] == -1)
				{
					int Max = 0;
					if (j == n - 1)
					{
						return Max;
					}
					else
					{
						if (grid[i][j + 1] > grid[i][j])
						{
							Max = max(1 + dfs(i, j + 1), Max);
						}
						if (i - 1 >= 0 && grid[i - 1][j + 1] > grid[i][j])
						{
							Max = max(1 + dfs(i - 1, j + 1), Max);
						}
						if (i + 1 < m && grid[i + 1][j + 1] > grid[i][j])
						{
							Max = max(1 + dfs(i + 1, j + 1), Max);
						}
					}
					dp[i][j] = Max;
					return Max;
				}
				else
				{
					return dp[i][j];
				}
			};
		int ans = 0;
		for (int i = 0; i < m; i++)
		{
			ans = max(dfs(i, 0), ans);
		}
		return ans;
	}
};