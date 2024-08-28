#include<vector>
#include<string>
#include<functional>
#include<unordered_map>
using namespace std;

//º«“‰ªØµ›πÈ
/*
class Solution
{
public:
	int minimumSubstringsInPartition(string s)
	{
		int n = s.size();
		vector<int> cache(n, -1);
		function<int(int)>dfs = [&](int i)->int
			{
				int ans = INT_MAX;
				if (i == -1)
				{
					return 0;
				}
				if (cache[i] != -1)
				{
					return cache[i];
				}
				unordered_map<char, int>map;
				int max_cnt = 0;
				for (int j = i; j >= 0; j++)
				{
					if (map.count(s[j]))
					{
						map[s[j]]++;
					}
					else
					{
						map[s[j]] = 1;
					}
					max_cnt = max(max_cnt, map[s[j]]);
					if (max_cnt * map.size() == i - j + 1)
					{
						ans = min(ans, dfs(j - 1) + 1);
					}
				}
				cache[i] = ans;
				return ans;
			};
		return dfs(n - 1);
	}
};
*/
class Solution
{
public:
	int minimumSubstringsInPartition(string s)
	{
		int n = s.size();
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			unordered_map<char, int>map;
			int max_cnt = 0;
			for (int j = i; j > 0; j--)
			{
				if (map.count(s[j - 1]))
				{
					map[s[j - 1]]++;
				}
				else
				{
					map[s[j - 1]] = 1;
				}
				max_cnt = max(max_cnt, map[s[j - 1]]);
				if (max_cnt * map.size() == i - j + 1)
				{
					dp[i] = min(dp[i], dp[j - 1] + 1);
				}
			}
		}
		return dp[n];
	}
};

int main() {
	string s = "fabccddg";
	Solution ss;
	ss.minimumSubstringsInPartition(s);
}