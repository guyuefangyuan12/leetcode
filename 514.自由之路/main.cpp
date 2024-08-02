#include<string>
#include<unordered_map>
using namespace std;

class Solution
{
public:
	int findRotateSteps(string ring, string key)
	{
		unordered_map<char, vector<int>>map;
		int n = ring.size();
		int m = key.size();
		for (int i = 0; i < n; i++)
		{
			map[ring[i]].push_back(i);
		}
		vector<vector<int>>dp(m, vector<int>(n,100000));
		for (auto i : map[key[0]]) 
		{
			dp[0][i] = min(i, n - 1) + 1;
		}
		for (int i = 1; i < m; i++) 
		{			
			for (auto j : map[key[i]]) 
			{
				for (auto k : map[key[i - 1]]) 
				{
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1);
				}
			}
		}
		return *min_element(dp[m - 1].begin(), dp[m - 1].end());
	}
};