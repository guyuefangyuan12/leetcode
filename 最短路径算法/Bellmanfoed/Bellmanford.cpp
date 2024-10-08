#include<vector>
using namespace std;

class bellmanford
{
public:
	int bellman(vector<vector<int>> edges, int n, int start, int end)
	{
		vector<int> dis(n, INT_MAX / 2);
		dis[start] = 0;
		for (int i = 0; i < n; i++)
		{
			for (auto& p : edges)
			{
				if (dis[p[0]] > dis[p[1]] + p[2])
				{
					dis[p[0]] = dis[p[1]] + p[2];
				}
				if (dis[p[1]] > dis[p[0]] + p[2])
				{
					dis[p[1]] = dis[p[0]] + p[2];
				}
			}
		}
		return dis[end];
	}
};