#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	long long maxStrength(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		int n = nums.size();
		long long ans = 1;
		int pos_0 = -1;
		int pos = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (nums[i] == 0)
			{
				pos_0 = i;
			}
			else if (nums[i] < 0)
			{
				pos = i;
				break;
			}
			else
			{
				ans *= nums[i];
			}
		}
		if (pos_0 <= 1 && nums[n - 1] == 0)
		{
			return 0;
		}
		if (n == 1)
		{
			return nums[0];
		}
		for (int i = 1; i <= pos; i = i + 2)
		{
			ans *= nums[i - 1];
			ans *= nums[i];
		}
		return ans;
	}
};