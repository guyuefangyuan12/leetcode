#include<vector>
#include<functional>
#include<unordered_map>
using namespace std;

class Solution
{
public:
	int maxOperations(vector<int>& nums)
	{
		int n = nums.size();
		unordered_map<long long, int>map;
		function<int(int, int, int)>dfs = [&](int l, int r, int sum)->int
			{
				int ans = 0;
				long long flag = l | r << 11 | (long long)sum << 22;
				if (map.count(flag))
				{
					return map[flag];
				}
				if (sum == 0)
				{
					ans = max(ans, dfs(l + 1, r - 1, nums[l] + nums[r]) + 1);
					ans = max(ans, dfs(l + 2, r, nums[l] + nums[l + 1]) + 1);
					ans = max(ans, dfs(l, r - 2, nums[r] + nums[r - 1]) + 1);
				}
				else
				{
					if (l >= r)
					{
						return 0;
					}
					if (nums[l] + nums[r] == sum)
					{
						ans = max(ans, dfs(l + 1, r - 1, sum) + 1);
					}
					if (nums[l] + nums[l + 1] == sum)
					{
						ans = max(ans, dfs(l + 2, r, sum) + 1);
					}
					if (nums[r] + nums[r - 1] == sum)
					{
						ans = max(ans, dfs(l, r - 2, sum) + 1);
					}
				}
				map[flag] = ans;
				return ans;
			};
		return dfs(0, n - 1, 0);
	}
};