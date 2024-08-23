#include<vector>
using namespace std;

class Solution
{
public:
	long long countAlternatingSubarrays(vector<int>& nums)
	{
		long long ans = 0;
		int n = nums.size();
		int left = 0;
		for (int i = 1; i < n; i++)
		{
			if (nums[i] == nums[i - 1])
			{
				long long temp = n - left;
				ans += (temp * (temp + 1) / 2);
				left = i;
			}
		}
		long long temp = n - left;
		ans += (temp * (temp + 1) / 2);
		return ans;
	}
};