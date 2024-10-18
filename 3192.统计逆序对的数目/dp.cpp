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
		if (req[0] > 0)
		{
			return 0;
		}
		vector<vector<int>>dp(n, vector<int>(cnt + 1, 0));
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
			{
				dp[i][0] = 1;
				for (int j = 1; j <= cnt; j++)
				{
					dp[i][j] = 0;
				}
			}
			else
			{
				for (int j = 0; j <= cnt; j++)
				{
					if (req[i - 1] == -1)
					{
						for (int k = 0; k <= min(i, j); k++)
						{
							dp[i][j] = (dp[i][j] + dp[i - 1][j - k] % res) % res;
						}
					}
					else
					{
						if (j < req[i - 1] || j - i > req[i - 1])
						{
							dp[i][j] = 0;
						}
						else
						{
							dp[i][j] = dp[i - 1][req[i - 1]] % res;;
						}
					}
				}
			}
		}
		int ans = dp[n - 1][req[n - 1]];
		return dp[n - 1][req[n - 1]];
	}
};

int main() {
	vector<vector<int>> nums = { {2,2},{0,0} };
	Solution s;
	s.numberOfPermutations(3, nums);
}