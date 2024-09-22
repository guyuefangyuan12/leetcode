#include<vector>
#include<functional>
#include<unordered_map>
using namespace std;

class Solution
{
public:
	int countSpecialNumbers(int n)
	{
		vector<int> nums;
		while (n)
		{
			nums.insert(nums.begin(), n % 10);
			n /= 10;
		}
		int m = nums.size();
		unordered_map<long long,int> map;
		function<int(int, int, bool)>dfs = [&](int i, int s, bool limit)->int
			{
				int ans = 0;
				int j = 0;
				long long flag = limit | i << 1 | s << 7;
				if (i == m)
				{
					return 1;
				}
				if (map.count(flag)) 
				{
					return map[flag];
				}
				int mx = limit ? nums[i] : 9;
				if (s == 0)
				{
					ans += dfs(i + 1, s, false);
					j = 1;
				}
				else
				{
					j = 0;
				}
				for (; j <= mx; j++)
				{
					if (!((s >> j) & 1))
					{
						ans += dfs(i + 1, s | (1 << j), limit && (j == mx));
					}
				}
				map[flag] = ans;
				return ans;
			};
		return dfs(0, 0, true) - 1;
	}
};

int main() {
	Solution s;
	s.countSpecialNumbers(5);
}