#include<vector>
#include<functional>
using namespace std;

class Solution
{
public:
	int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads)
	{
		vector<vector<int>> dp(n, vector<int>(n, INT16_MAX / 2));
		vector<vector<int>> g(n, vector<int>(n, INT16_MAX / 2));
		int cnt = 0;
		for (auto& r : roads)
		{
			g[r[0]][r[1]] = min(r[2], g[r[0]][r[1]]);
			g[r[1]][r[0]] = min(r[2], g[r[1]][r[0]]);
		}
		for (int s = 0; s <(1 << n) ; s++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					dp[i][j] = g[i][j];
				}
			}
			for (int k = 1; k < n + 1; k++)
			{
				if (s & (1 << (k - 1)))
				{
					for (int i = 0; i < n; i++)
					{
						if (s & (1 << i))
						{
							for (int j = 0; j < n; j++)
							{
								if (s & (1 << j)&&i!=j)
								{
									dp[i][j] = min(dp[i][k - 1] + dp[k - 1][j], dp[i][j]);
								}
							}
						}
					}
				}
			}
			int flag = 0;
			for (int i = 0; i < n; i++)
			{
				if (s & (1 << i))
				{
					for (int j = 0; j < n; j++)
					{
						if (s & (1 << j) && i != j&&dp[i][j]>=maxDistance)
						{
							flag = 1;
							break;
						}
					}
				}
				if (flag) 
				{
					break;
				}
			}
			if (!flag) 
			{
				cnt++;
			}
		}
		return cnt;
	}
};

int main() 
{
	vector<vector<int>> roads = { {1,0,11},{1,0,16},{0,2,13} };
	Solution s;
	s.numberOfSets(3, 12, roads);

}