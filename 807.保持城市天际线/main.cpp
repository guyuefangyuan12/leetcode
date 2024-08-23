#include<vector>
using namespace std;

class Solution
{
public:
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid)
	{
		int n = grid.size();
		vector<int> colmun(n, 0);
		vector<int> line(n, 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				colmun[j] = max(colmun[j], grid[i][j]);
				line[i] = max(line[i], grid[i][j]);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ans = ans - grid[i][j] + min(colmun[j], line[i]);
			}
		}
		return ans;
	}
};