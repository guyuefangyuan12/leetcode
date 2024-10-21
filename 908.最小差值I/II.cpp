#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	int smallestRangeII(vector<int>& nums, int k)
	{
		sort(nums.begin(), nums.end());
		int ans = nums[nums.size() - 1] - nums[0];
		for (int i = 0; i < nums.size() - 1; i++)
		{
			int minn = min(nums[0] + k, nums[i + 1] - k);
			int maxx = max(nums[nums.size() - 1] - k, nums[i] + k);
			ans = min(ans, maxx - minn);
		}
		return ans;
	}
};