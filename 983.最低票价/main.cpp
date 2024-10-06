#include<vector>
#include<functional>
using namespace std;

class Solution
{
public:
	int mincostTickets(vector<int>& days, vector<int>& costs)
	{
		int n = days.size();
		vector<int>cache(n, -1);
		auto dfs = [&](auto& dfs, int i, int res)->int
			{
				int ans = 0;
				if (i == n)
				{
					return 0;
				}
				if (days[i] > res)
				{
					if (cache[i] == -1)
					{
						ans = dfs(dfs, i + 1, days[i]) + costs[0];
						ans = min(ans, dfs(dfs, i + 1, days[i] + 6) + costs[1]);
						ans = min(ans, dfs(dfs, i + 1, days[i] + 29) + costs[2]);
						cache[i] = ans;
					}
					else
					{
						return cache[i];
					}
				}
				else
				{
					ans = dfs(dfs, i + 1, res);
				}
				return ans;
			};
		return dfs(dfs, 0, 0);
	}
};