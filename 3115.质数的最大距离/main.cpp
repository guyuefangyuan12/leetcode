#include<vector>
using namespace std;

class Solution
{
public:
	bool iszhishu(int num)
	{
		for (int i = 2; i <=num / 2; i++)
		{
			if (num % i == 0)
			{
				return false;
			}
		}
		return true;
	}
	int maximumPrimeDifference(vector<int>& nums)
	{
		int n = nums.size();
		vector<bool> dp(101);
		dp[1] = false;
		int left = 0;
		int right = 0;
		for (int i = 2; i < 101; i++)
		{
			dp[i] = iszhishu(i);
		}
		for (int i = 0; i < n; i++)
		{
			if (dp[nums[i]])
			{
				left = i;
				break;
			}
		}
		for (int i = n - 1; i >= 0; i--)
		{
			if (dp[nums[i]])
			{
				right = i;
				break;
			}
		}
		return right - left;
	}
};

int main() {
	vector<int> nums = { 4,2,9,5,3 };
	Solution s;
	s.maximumPrimeDifference(nums);
}