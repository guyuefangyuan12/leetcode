#include<vector>
using namespace std;

class Solution
{
public:
	int findTargetSumWays(vector<int>& nums, int target)
	{
		int n = nums.size();
		vector<vector<vector<int>>>dp(n, vector<vector<int>>(2));
		dp[0][0].push_back(nums[0]);
		dp[0][1].push_back(nums[0]*-1);
		for (int i = 1; i < n; i++) 
		{
			for (auto& k : dp[i-1][0]) 
			{
				dp[i][0].push_back(k + nums[i]);
			}
			for (auto& k : dp[i - 1][1])
			{
				dp[i][0].push_back(k + nums[i]);
			}
			for (auto& k : dp[i - 1][0])
			{
				dp[i][1].push_back(k - nums[i]);
			}
			for (auto& k : dp[i - 1][1])
			{
				dp[i][1].push_back(k - nums[i]);
			}			
		}
		int cnt = 0;
		for (auto& k : dp[n - 1][0]) 
		{
			if (k == target) 
			{
				cnt++;
			}
		}
		for (auto& k : dp[n - 1][1])
		{
			if (k == target)
			{
				cnt++;
			}
		}
		return cnt;
	}
};