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
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int j = n - 2; j >= 0; j--)
		{
			for (int i = 0; i < m; i++)
			{
				if (grid[i][j] < grid[i][j + 1])
				{
					dp[i][j] = max(dp[i][j], dp[i][j + 1] + 1);
				}
				if (i > 0 && grid[i][j] < grid[i - 1][j + 1])
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + 1);
				}
				if (i < m - 1 && grid[i][j] < grid[i + 1][j + 1])
				{
					dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + 1);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < m; i++)
		{
			ans = max(dp[i][0], ans);
		}
		return ans;
	}
};

int main() 
{
	vector<vector<int>> grid = { {2,4,3,5},{5,4,9,3},{3,4,2,11},{10,9,13,15} };
	Solution s;
	s.maxMoves(grid);
}