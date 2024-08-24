#include<functional>
#include<vector>
using namespace std;

class Solution {
public:
	int specialPerm(vector<int>& nums)
	{
		int n = nums.size();
		vector<vector<int>>cache(1 << n, vector<int>(n, -1));
		function<int(int, int)>dfs = [&](int s, int i)->int
			{
				int res = 1000000007;
				int ans = 0;
				if (s == (1 << n) - 1)
				{
					return 1;
				}
				if (cache[s][i] != -1)
				{
					return cache[s][i];
				}
				for (int j = 0; j < n; j++)
				{
					if (s == 0 || ((s >> j & 1) == 0 && (nums[j] % nums[i] == 0 || nums[i] % nums[j] == 0)))
					{
						ans += dfs(s | (1 << j), j);
						ans = ans % res;
					}
				}
				cache[s][i] = ans;
				return ans;
			};
		return dfs(0, 0);
	}
};

int main() {
	vector<int >nums = { 2,3,6 };
	Solution s;
	s.specialPerm(nums);
}