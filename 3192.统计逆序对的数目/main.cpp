#include<vector>
#include<functional>
using namespace std;

class Solution
{
public:
	int numberOfPermutations(int n, vector<vector<int>>& requirements)
	{
		vector<int>req(n, -1);
		int cnt = -1;
		int res = 1000000007;
		for (auto v : requirements)
		{
			req[v[0]] = v[1];
			cnt = max(cnt, v[1]);
		}
		vector<vector<int>>cache(n, vector<int>(cnt + 1, -1));
		function<int(int, int)>dfs = [&](int i, int j)->int
			{
				int ans = 0;
				if (i == 0)
				{
					if (j == 0)
					{
						return 1;
					}
					else
					{
						return 0;
					}
				}
				if (cache[i][j] != -1)
				{
					return cache[i][j];
				}
				if (req[i - 1] >= 0)
				{
					if (j < req[i - 1] || j - i > req[i - 1])
					{
						return 0;
					}
					ans = dfs(i - 1, req[i - 1]) % res;
				}
				else
				{
					for (int k = 0; k <= min(i, j); k++)
					{
						ans = (ans + dfs(i - 1, j - k) % res) % res;
					}
				}
				cache[i][j] = ans;
				return ans;
			};
		return dfs(n - 1, req[n - 1]);
	}
};