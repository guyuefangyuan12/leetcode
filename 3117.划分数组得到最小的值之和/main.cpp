#include<vector>
#include<functional>
#include<unordered_map>
using namespace std;

class Solution
{
public:
	int minimumValueSum(vector<int>& nums, vector<int>& andValues)
	{
		int m = nums.size();
		int n = andValues.size();
		unordered_map<long long, int>map;
		auto dfs = [&](auto&& dfs, int i, int j, int And)->int
			{
				long long flag = i | j << 14 | And << 18;
				int ans = INT_MAX;
				if (i == m && j == n)
				{
					return 0;
				}
				if (i == m || j == n)
				{
					return INT_MAX;
				}
				if (map.count(flag)) {
					return map[flag];
				}
				if ((And & nums[i]) == andValues[j])
				{
					int temp = dfs(dfs,i + 1, j + 1, -1);
					if (temp != INT_MAX)
					{
						ans = min(ans, temp + nums[i]);
					}
				}
				int temp = dfs(dfs,i + 1, j, And & nums[i]);
				if (temp != INT_MAX)
				{
					ans = min(ans, temp);
				}
				map[flag] = ans;
				return ans;
			};
		int ans = dfs(dfs,0, 0, -1);
		if (ans == INT_MAX)
		{
			return -1;
		}
		return ans;
	}
};
int main() {
	vector<int> nums = { 4,8,9 };
	vector<int> andvalues = { 0 };
	Solution s;
	s.minimumValueSum(nums, andvalues);
}