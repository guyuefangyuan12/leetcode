#include<string>
#include<vector>
#include<unordered_map>
#include<functional>
using namespace std;

class Solution
{
public:
	int minimumSubstringsInPartition(string s)
	{
		int n = s.size();
		vector<vector<int>>cache(n, vector<int>(n, -1));
		vector<vector<bool>>check(n, vector<bool>(n, false));
		for (int i = 0; i < n; i++)
		{
			unordered_map<char, int>map;
			int maxcnt = 0;
			for (int j = i; j < n; j++)
			{
				if (map.count(s[j]))
				{
					map[s[j]]++;
				}
				else
				{
					map[s[j]] = 1;
				}
				maxcnt = max(maxcnt, map[s[j]]);
				if (maxcnt * map.size() == j - i + 1)
				{
					check[i][j] = true;
				}
			}
		}
		function<int(int, int)>dfs = [&](int i, int l)->int
			{
				int ans = INT_MAX;
				if (i == n)
				{
					if (l == n)
					{
						return 0;
					}
					if (check[l][i])
					{
						return 1;
					}
					else
					{
						return INT_MAX;
					}
				}
				if (cache[i][l] != -1)
				{
					return cache[i][l];
				}
				if (check[l][i])
				{
					int temp = dfs(i + 1, i + 1);
					ans = min(ans, temp == INT_MAX ? INT_MAX : temp + 1);
				}
				int temp = dfs(i + 1, l);
				ans = min(ans, temp == INT_MAX ? INT_MAX : temp);
				cache[i][l] = ans;
				return ans;
			};
		dfs(0, 0);
		return cache[0][0];
	}
};

