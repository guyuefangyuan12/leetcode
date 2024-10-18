#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	double minimumAverage(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		int n = nums.size();
		double ans = 51;
		for (int i = 0, j = n - 1; i < n / 2; i++, j--) 
		{
			ans = min(ans, (0.0 + nums[i] + nums[j]) / 2);
		}
		return ans;
	}
};