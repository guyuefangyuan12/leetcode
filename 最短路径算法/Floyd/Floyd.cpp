#include<vector>
using namespace std;

class Floyd
{
	void floyd(vector<vector<int>>edges, int n)
	{
		vector<vector<int>> dis(n, vector<int>(n, INT_MAX / 2));
		vector<vector<int>> s(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < n; j++) 
			{
				s[i][j] = j;
			}
		}
		for (auto g : edges)
		{
			dis[g[0]][g[1]] = g[3];
			dis[g[1]][g[0]] = g[3];
		}
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++) 
			{
				for (int j = 0; j < n; j++) 
				{
					if (dis[i][j] > dis[i][k] + dis[k][j]) 
					{
						dis[i][j] = dis[i][k] + dis[k][j];
						s[i][j] = s[i][k];
					}
				}
			}
		}
	}
};