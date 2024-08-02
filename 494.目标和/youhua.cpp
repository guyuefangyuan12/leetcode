#include<vector>
using namespace std;
//更加优化方案：取负号的数之和为q,取正号之和为p,则p-q=target,p+q=sum则q=(sum-target)/2
//问题就转化为了在nums中取k个数，使其和为q
//定义dp[i][j]为在nums中选取元素之和为j的方案数
class Solution
{
public:
	int findTargetSumWays(vector<int>& nums, int target)
	{
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(2001, 0));
		dp[0][nums[0] + 1000] += 1;
		dp[0][1000 - nums[0]] += 1;
		for (int i = 1; i < n; i++)
		{
			for (int k = 0; k < 2001; k++)
			{
				if (nums[i] < k)
				{
					dp[i][k] += dp[i - 1][k - nums[i]];
				}
				if (2001 - nums[i] > k)
				{
					dp[i][k] += dp[i - 1][k + nums[i]];
				}
			}
		}
		return dp[n - 1][target + 1000];
	}
};