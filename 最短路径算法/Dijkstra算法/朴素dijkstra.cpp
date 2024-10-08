#include<vector>
using namespace std;

class dijkstra
{
public:
	int dij(vector<vector<int>> edges, int n, int start, int end)
	{
		vector<vector<int>> g(n, vector<int>(n, INT_MAX / 2));//建立邻接矩阵
		for (auto& p : edges)
		{
			g[p[0]][p[1]] = p[2];
			g[p[1]][p[0]] = p[2];
		}
		vector<int> dis(n, INT_MAX / 2);//每个点距离起始点的最短距离
		vector<int> visit(n, false);//是否遍历过
		dis[start] = 0;
		while (true)
		{
			int x = -1;//找到还未遍历过的当前距离起始点最近的点
			for (int i = 0; i < n; i++)
			{
				if (!visit[i] && (x == -1 || dis[i] < dis[x]))
				{
					x = i;
				}
			}
			if (x == -1 || dis[x] == INT_MAX / 2)//已经没用可以遍历的点了
			{
				return -1;
			}
			if (x == end) //找到了终点
			{
				return dis[x];
			}
			for (int i = 0; i < n; i++)
			{
				dis[i] = min(dis[x] + g[x][i], dis[i]);
			}
		}
	}
};