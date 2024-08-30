#include<vector>
using namespace std;

class Solution
{
public:
	bool satisfiesConditions(vector<vector<int>>& grid)
	{
		int m = grid.size();
		int n = grid[0].size();
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == m - 1)
				{
					if (j != n - 1)
					{
						if (grid[i][j] == grid[i][j + 1])
						{
							return false;
						}
					}
				}
				else
				{
					if (j != n - 1)
					{
						if (grid[i][j] != grid[i + 1][j] || grid[i][j] == grid[i][j + 1])
						{
							return false;
						}
					}
					else
					{
						if (grid[i][j] != grid[i + 1][j])
						{
							return false;
						}
					}
				}
			}
		}
		return true;
	}
};