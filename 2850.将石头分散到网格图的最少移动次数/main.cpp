#include<vector>
#include<functional>
using namespace std;

class Solution
{
public:
	int minimumMoves(vector<vector<int>>& grid)
	{
		int n = grid.size();
		vector<vector<int>> zero;
		vector<vector<int>> more;
		vector<int> vis;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 0)
				{
					zero.push_back({ i,j });
				}
				if (grid[i][j] > 1)
				{
					more.push_back({ i,j });
					vis.push_back(grid[i][j]);
				}
			}
		}
		int m = zero.size();
		int p = more.size();
		function<int(int, int)> dfs = [&](int i, int j)->int
			{
				int Min = INT_MAX;
				if (vis[j] == 1)
				{
					return INT_MAX / 2;
				}
				else
				{
					vis[j]--;
					if (i == 0)
					{
						vis[j]++;
						return abs(more[j][0] - zero[i][0]) + abs(more[j][1] - zero[i][1]);
					}
					else
					{
						for (int k = 0; k < p; k++)
						{
							Min = min(Min, dfs(i - 1, k));
						}
					}
					vis[j]++;
					return Min+abs(more[j][0] - zero[i][0]) + abs(more[j][1] - zero[i][1]);
				}
			};
		int Min = INT_MAX;
		for (int i = 0; i < p; i++) 
		{
			Min = min(Min, dfs(m - 1, i));
		}
		return Min;
	}
};

int main() 
{
	vector<vector<int>>grid = { {1,1,0},{1,1,1},{1,2,1} };
	Solution s;
	s.minimumMoves(grid);
}