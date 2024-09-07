#include<vector>
#include<unordered_map>
#include<algorithm>
#include<functional>
using namespace std;

class Solution
{
public:
	int countWays(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int ans = 0;
		if (nums[0] > 0)
		{
			ans++;
		}
		if (nums[n - 1] < n) 
		{
			ans++;
		}
		for (int i = 1; i < n; i++) 
		{
			if (nums[i - 1]<i && nums[i]>i) 
			{
				ans++;
			}
		}
		return ans;
	}
};

