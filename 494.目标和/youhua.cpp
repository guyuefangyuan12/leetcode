#include<vector>
using namespace std;
//�����Ż�������ȡ���ŵ���֮��Ϊq,ȡ����֮��Ϊp,��p-q=target,p+q=sum��q=(sum-target)/2
//�����ת��Ϊ����nums��ȡk������ʹ���Ϊq
//����dp[i][j]Ϊ��nums��ѡȡԪ��֮��Ϊj�ķ�����
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