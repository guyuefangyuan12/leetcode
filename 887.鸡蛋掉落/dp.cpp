#include<vector>
#include<unordered_map>
using namespace std;




class Solution
{
public:
	int superEggDrop(int k, int n)
	{
		vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == 1)
				{
					dp[i][j] = j;
				}
				else
				{
					dp[i][j] = INT_MAX / 2;
					for (int m = 1; m <= j; m++)
					{
						dp[i][j] = min(dp[i][j], max(dp[i - 1][m - 1] + 1, dp[i][j - m] + 1));
					}
				}
			}
		}
		return dp[k][n];
	}
};

int main()
{
	Solution s;
	s.superEggDrop(2, 6);
}