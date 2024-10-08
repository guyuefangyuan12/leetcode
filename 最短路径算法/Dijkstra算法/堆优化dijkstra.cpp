#include<vector>
#include<queue>
using namespace std;

class dijkstra
{
public:
	int dij(vector<vector<int>> edges, int n, int start, int end)
	{
		vector<vector<pair<int, int>>> g(n);
		for (auto& p : edges)
		{
			g[p[0]].emplace_back(p[1], p[2]);
			g[p[1]].emplace_back(p[0], p[2]);
		}
		vector<int> dis(n, INT_MAX / 2);//每个点距离起始点的最短距离
		dis[start] = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
		q.emplace(start, 0);
		while (!q.empty())
		{
			auto p = q.top();
			q.pop();
			if (p.first > dis[p.second])
			{
				continue;
			}
			for (auto k : g[p.second])
			{
				if (dis[k.first] > dis[p.second] + k.second)
				{
					dis[k.first] = dis[p.second] + k.second;
					q.emplace(dis[k.first], k.first);
				}
			}
		}
		return dis[end];
	}
};