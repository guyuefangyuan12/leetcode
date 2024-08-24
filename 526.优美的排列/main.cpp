#include<functional>
#include<vector>
using namespace std;

class Solution
{
public:
	int countArrangement(int n)
	{
		vector<int>cache((1 << n), -1);
		function<int(int)>dfs = [&](int s)->int
			{
				int ans = 0;
				if (s == (1 << n) - 1)
				{
					return 1;
				}
				if (cache[s] != -1)
				{
					return cache[s];
				}
				int i = __builtin_popcount(s);
				for (int j = 1; j <= n; j++)
				{
					if (((s >> (j - 1)) & 1) == 0 && (j % i == 0 || i % j == 0))
					{
						ans += dfs(s | (1 << (j - 1)));
					}
				}
				cache[s] = ans;
				return ans;
			};
		return dfs(0);
	}
};