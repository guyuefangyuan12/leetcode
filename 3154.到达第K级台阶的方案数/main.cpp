#include<vector>
#include<unordered_map>
#include<functional>
using namespace std;

class Solution
{
public:
	int waysToReachStair(int k)
	{
		unordered_map<long long, int>map;
		function<int(int, int, bool)>dfs = [&](int pos, int jump, int flag)->int
			{
				int ans = 0;
				long long f = flag | jump << 1 | pos << 7;
				if (map.count(f))
				{
					return map[f];
				}
				if (pos - k > 1)
				{
					return 0;
				}
				if (pos == k)
				{
					ans++;
				}
				if (flag)
				{
					ans += dfs(pos + pow(2, jump), jump + 1, 0);
				}
				else
				{
					ans += dfs(pos + pow(2, jump), jump + 1, 0);
					if (pos != 0)
					{
						ans += dfs(pos - 1, jump, 1);
					}
				}
				map[f] = ans;
				return ans;
			};
		return dfs(1, 0, false);
	}
};