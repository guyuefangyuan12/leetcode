#include<vector>
#include<algorithm>
#include<unordered_map>
#include<functional>
using namespace std;

class Solution
{
public:
	int sumOfPowers(vector<int>& nums, int k)
	{
		int n = nums.size();
		sort(nums.begin(), nums.end());
		unordered_map<long long, int>f;
		int res = 1000000007;
		function<long long(int, int, int, long long)> dfs = [&](int i, int j, int k, int mi)->long long
			{
				long long key = (1LL * mi) << 18 | (i << 12) | (j << 6) | k;
				if (f.count(key)) 
				{
					return f[key];
				}
				long long ans = 0;
				if (i >= n) 
				{
					if (k == 0) 
					{
						return mi;
					}
					else 
					{
						return 0;
					}
				}
				if (n - i < k) 
				{
					return 0;
				}
				ans += dfs(i + 1, j, k, mi);
				if (j == n) 
				{
					ans += dfs(i + 1, i, k - 1, mi);
				}
				else 
				{
					ans += dfs(i + 1, i, k - 1, min(mi, nums[i] - nums[j]));
				}
				f[key] = ans;
				return f[key];
			};
		long long t= dfs(0, n, k, INT_MAX);
		return dfs(0, n, k, INT_MAX);
	}
};

int main()
{
	vector<int> nums = { 1,2,3,4 };
	Solution s;
	s.sumOfPowers(nums, 3);
}